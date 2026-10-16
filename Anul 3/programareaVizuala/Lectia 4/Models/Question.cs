using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace Lectia4.Models;

public enum QuestionType { SingleChoice, MultipleChoice, Dropdown, Written }

// The response belongs to the test attempt, not to the question bank.
public sealed class QuestionResponse {
    public bool[] Selected { get; }
    public int[] Blanks { get; }
    public string Text { get; set; } = "";

    public QuestionResponse(Question question) {
        Selected = new bool[question.Answers.Length];
        Blanks = Enumerable.Repeat(-1, question.Gaps.Length).ToArray();
    }

    public bool HasAnswer => Selected.Any(value => value) ||
        Blanks.Any(value => value >= 0) || !string.IsNullOrWhiteSpace(Text);

    public bool IsComplete(Question question) => question.Type == QuestionType.Dropdown
        ? Blanks.All(value => value >= 0)
        : HasAnswer;
}

// Each gap appears between two sentence fragments and has its own options.
public sealed record DropdownGap(string[] Options, int CorrectIndex);

public sealed class Question {
    public string Text { get; }
    public QuestionType Type { get; }
    public decimal MaxPoints { get; }
    public string Explanation { get; }
    public Answer[] Answers { get; private init; } = Array.Empty<Answer>();
    public string[] Fragments { get; private init; } = Array.Empty<string>();
    public DropdownGap[] Gaps { get; private init; } = Array.Empty<DropdownGap>();
    public string[] AcceptedAnswers { get; private init; } = Array.Empty<string>();

    private Question(string text, QuestionType type, decimal maxPoints, string explanation) {
        if (string.IsNullOrWhiteSpace(text) || maxPoints <= 0)
            throw new ArgumentException("A question needs a prompt and positive points.");
        Text = text;
        Type = type;
        MaxPoints = maxPoints;
        Explanation = explanation;
    }

    public static Question Choice(string text, bool multiple, string explanation, params Answer[] answers) {
        int correct = answers.Count(answer => answer.IsCorrect);
        if (answers.Length < 2 || correct == 0 || correct == answers.Length || (!multiple && correct != 1))
            throw new ArgumentException("Choice questions need correct and incorrect options; single choice needs exactly one correct option.");
        return new Question(text, multiple ? QuestionType.MultipleChoice : QuestionType.SingleChoice, 4, explanation) {
            Answers = answers
        };
    }

    public static Question Dropdown(string text, string explanation, string[] fragments, params DropdownGap[] gaps) {
        if (gaps.Length == 0 || fragments.Length != gaps.Length + 1 ||
            gaps.Any(gap => gap.Options.Length < 2 || gap.CorrectIndex < 0 || gap.CorrectIndex >= gap.Options.Length))
            throw new ArgumentException("Each dropdown needs valid options and surrounding sentence fragments.");
        return new Question(text, QuestionType.Dropdown, 4, explanation) { Fragments = fragments, Gaps = gaps };
    }

    public static Question Written(string text, string explanation, params string[] acceptedAnswers) {
        if (acceptedAnswers.Length == 0 || acceptedAnswers.Any(string.IsNullOrWhiteSpace))
            throw new ArgumentException("Written questions need at least one accepted answer.");
        return new Question(text, QuestionType.Written, 4, explanation) { AcceptedAnswers = acceptedAnswers };
    }

    public string Instructions => Type switch {
        QuestionType.SingleChoice => "Alege un singur răspuns. Răspunsul corect valorează 4 puncte.",
        QuestionType.MultipleChoice => "Alege toate răspunsurile corecte. Fiecare alegere corectă aduce o parte egală din punctaj; fiecare alegere greșită scade aceeași parte. Minimum: 0 puncte.",
        QuestionType.Dropdown => "Completează fiecare spațiu din propoziții. Fiecare spațiu corect aduce o parte egală din punctaj, fără penalizare.",
        _ => "Scrie doar răspunsul cerut. Majusculele și spațiile suplimentare nu contează. Răspunsul corect valorează 4 puncte."
    };

    public string TypeLabel => Type switch {
        QuestionType.SingleChoice => "Un singur răspuns",
        QuestionType.MultipleChoice => "Răspunsuri multiple",
        QuestionType.Dropdown => "Completează din liste",
        _ => "Răspuns scris"
    };

    public string CorrectAnswer => Type switch {
        QuestionType.SingleChoice or QuestionType.MultipleChoice =>
            string.Join("; ", Answers.Where(answer => answer.IsCorrect).Select(answer => answer.Text)),
        QuestionType.Dropdown => string.Concat(Fragments.Select((fragment, index) =>
            fragment + (index < Gaps.Length ? Gaps[index].Options[Gaps[index].CorrectIndex] : ""))),
        _ => AcceptedAnswers[0]
    };

    public decimal Score(QuestionResponse response) {
        switch (Type) {
            case QuestionType.SingleChoice:
                return response.Selected.Count(value => value) == 1 &&
                    Answers.Where((answer, index) => response.Selected[index] && answer.IsCorrect).Any() ? MaxPoints : 0;
            case QuestionType.MultipleChoice:
                int balance = Answers.Select((answer, index) =>
                    response.Selected[index] ? (answer.IsCorrect ? 1 : -1) : 0).Sum();
                return Math.Max(0, MaxPoints * balance / Answers.Count(answer => answer.IsCorrect));
            case QuestionType.Dropdown:
                int correct = Gaps.Where((gap, index) => response.Blanks[index] == gap.CorrectIndex).Count();
                return MaxPoints * correct / Gaps.Length;
            default:
                return AcceptedAnswers.Any(answer => Normalize(answer) == Normalize(response.Text)) ? MaxPoints : 0;
        }
    }

    private static string Normalize(string text) => Regex.Replace(text.Trim(), @"\s+", " ").ToUpperInvariant();
}
