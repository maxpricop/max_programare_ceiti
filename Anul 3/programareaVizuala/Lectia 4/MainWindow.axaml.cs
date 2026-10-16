using System;
using System.Linq;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Media;
using Lectia4.Models;

namespace Lectia4;

public partial class MainWindow : Window {
    private readonly Question[] questions = QuestionBank.Create();
    private QuestionResponse[] responses = Array.Empty<QuestionResponse>();
    private int currentQuestion;
    private bool reviewing;

    public MainWindow() {
        InitializeComponent();
        StartDetails.Text = $"{questions.Length} întrebări · {questions.Sum(question => question.MaxPoints)} puncte · Fără limită de timp";
        AnswerProgress.Maximum = questions.Length;
        for (int index = 0; index < questions.Length; index++) {
            Button button = new() { Content = (index + 1).ToString(), Tag = index };
            button.Classes.Add("question");
            button.Click += SelectQuestion;
            QuestionSelector.Children.Add(button);
        }
    }

    private void StartTest(object? sender, RoutedEventArgs e) {
        responses = questions.Select(question => new QuestionResponse(question)).ToArray();
        currentQuestion = 0;
        reviewing = false;
        StartView.IsVisible = false;
        ResultsView.IsVisible = false;
        TestView.IsVisible = true;
        ShowQuestion();
    }

    private void ShowQuestion() {
        Question question = questions[currentQuestion];
        QuestionResponse response = responses[currentQuestion];
        ProgressText.Text = $"Întrebarea {currentQuestion + 1} din {questions.Length} · {question.TypeLabel} · {question.MaxPoints} puncte";
        QuestionText.Text = question.Text;
        InstructionText.Text = question.Instructions;
        AnswersPanel.Children.Clear();

        switch (question.Type) {
            case QuestionType.SingleChoice:
            case QuestionType.MultipleChoice:
                for (int index = 0; index < question.Answers.Length; index++) {
                    int optionIndex = index;
                    // Radio buttons enforce one selection; checkboxes allow several.
                    Avalonia.Controls.Primitives.ToggleButton control = question.Type == QuestionType.SingleChoice
                        ? new RadioButton { GroupName = $"question-{currentQuestion}" }
                        : new CheckBox();
                    control.Content = new TextBlock {
                        Text = question.Answers[index].Text, TextWrapping = TextWrapping.Wrap
                    };
                    control.IsChecked = response.Selected[index];
                    control.IsEnabled = !reviewing;
                    control.IsCheckedChanged += (_, _) => {
                        if (reviewing) return;
                        response.Selected[optionIndex] = control.IsChecked == true;
                        UpdateSummary();
                    };
                    AnswersPanel.Children.Add(control);
                }
                break;
            case QuestionType.Dropdown:
                WrapPanel sentence = new() { Orientation = Avalonia.Layout.Orientation.Horizontal };
                for (int index = 0; index < question.Fragments.Length; index++) {
                    sentence.Children.Add(new TextBlock {
                        Text = question.Fragments[index], TextWrapping = TextWrapping.Wrap,
                        FontSize = 18, VerticalAlignment = Avalonia.Layout.VerticalAlignment.Center,
                        Margin = new Thickness(0, 8, 4, 8)
                    });
                    if (index >= question.Gaps.Length) continue;
                    int gapIndex = index;
                    ComboBox dropdown = new() {
                        ItemsSource = question.Gaps[index].Options,
                        SelectedIndex = response.Blanks[index], PlaceholderText = "Alege…",
                        MinWidth = 130, Margin = new Thickness(0, 4, 6, 4), IsEnabled = !reviewing
                    };
                    Avalonia.Automation.AutomationProperties.SetName(dropdown, $"Spațiul {index + 1}: {question.Fragments[index]}");
                    dropdown.SelectionChanged += (_, _) => {
                        if (reviewing) return;
                        response.Blanks[gapIndex] = dropdown.SelectedIndex;
                        UpdateSummary();
                    };
                    sentence.Children.Add(dropdown);
                }
                AnswersPanel.Children.Add(sentence);
                break;
            case QuestionType.Written:
                TextBox input = new() {
                    Text = response.Text, PlaceholderText = "Scrie răspunsul aici", MinHeight = 100,
                    AcceptsReturn = true, TextWrapping = TextWrapping.Wrap, IsReadOnly = reviewing
                };
                Avalonia.Automation.AutomationProperties.SetName(input, "Răspunsul tău");
                // TextChanged is queued; capture Text immediately so navigation or
                // submission on the same dispatcher turn cannot lose the last edit.
                input.PropertyChanged += (_, change) => {
                    if (reviewing || change.Property != TextBox.TextProperty) return;
                    response.Text = input.Text ?? "";
                    UpdateSummary();
                };
                AnswersPanel.Children.Add(input);
                break;
        }

        PreviousButton.IsEnabled = currentQuestion > 0;
        NextButton.IsEnabled = currentQuestion < questions.Length - 1;
        FinishButton.IsVisible = !reviewing;
        BackToResultsButton.IsVisible = reviewing;
        ReviewFeedback.IsVisible = reviewing;
        if (reviewing) {
            QuestionScoreText.Text = $"Punctaj: {question.Score(response):0.##} / {question.MaxPoints}";
            CorrectAnswerText.Text = $"Răspuns corect: {question.CorrectAnswer}";
            ExplanationText.Text = question.Explanation;
        }
        UpdateSummary();
    }

    private void UpdateSummary() {
        int completed = responses.Where((response, index) => response.IsComplete(questions[index])).Count();
        AnsweredText.Text = reviewing ? "Revizuirea răspunsurilor" : $"{completed} din {questions.Length} întrebări completate";
        AnswerProgress.Value = completed;
        foreach (Button button in QuestionSelector.Children.Cast<Button>()) {
            int index = (int)button.Tag!;
            QuestionResponse response = responses[index];
            string status = response.IsComplete(questions[index]) ? "Cu răspuns" : response.HasAnswer ? "Incomplet" : "Fără răspuns";
            button.Background = Brush.Parse(response.IsComplete(questions[index]) ? "#DBE7FF" : response.HasAnswer ? "#FFF0BF" : "#FFFFFF");
            button.Foreground = Brush.Parse("#203049");
            button.BorderBrush = Brush.Parse(index == currentQuestion ? "#245BCC" : "#CED8E5");
            button.BorderThickness = new Thickness(index == currentQuestion ? 2 : 1);
            string label = $"Întrebarea {index + 1}: {status}";
            ToolTip.SetTip(button, label);
            Avalonia.Automation.AutomationProperties.SetName(button, label);
        }
    }

    private void SelectQuestion(object? sender, RoutedEventArgs e) {
        if (sender is Button { Tag: int index }) NavigateTo(index);
    }

    private void NavigateTo(int index) {
        if (index < 0 || index >= questions.Length) return;
        currentQuestion = index;
        ShowQuestion();
    }

    private void PreviousQuestion(object? sender, RoutedEventArgs e) => NavigateTo(currentQuestion - 1);
    private void NextQuestion(object? sender, RoutedEventArgs e) => NavigateTo(currentQuestion + 1);

    private void FinishTest(object? sender, RoutedEventArgs e) {
        if (reviewing) return;
        reviewing = true;
        decimal earned = questions.Select((question, index) => question.Score(responses[index])).Sum();
        decimal possible = questions.Sum(question => question.MaxPoints);
        int full = questions.Where((question, index) => question.Score(responses[index]) == question.MaxPoints).Count();
        int partial = questions.Where((question, index) => question.Score(responses[index]) > 0 && question.Score(responses[index]) < question.MaxPoints).Count();
        int unanswered = responses.Count(response => !response.HasAnswer);
        ResultText.Text = $"{earned:0.##} din {possible} puncte ({earned / possible:P0})";
        ResultSummary.Text = $"Punctaj integral: {full} · Punctaj parțial: {partial} · Fără răspuns: {unanswered}";
        ResultsList.Children.Clear();
        for (int index = 0; index < questions.Length; index++) {
            Question question = questions[index];
            Button row = new() {
                Tag = index, HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Stretch,
                HorizontalContentAlignment = Avalonia.Layout.HorizontalAlignment.Stretch,
                Background = Brushes.White,
                Content = new TextBlock {
                    Text = $"{index + 1}. {question.Text}\n{question.Score(responses[index]):0.##} / {question.MaxPoints} puncte",
                    TextWrapping = TextWrapping.Wrap
                }
            };
            row.Click += ReviewQuestion;
            ResultsList.Children.Add(row);
        }
        ShowResults();
    }

    private void ReviewQuestion(object? sender, RoutedEventArgs e) {
        if (sender is not Button { Tag: int index }) return;
        ResultsView.IsVisible = false;
        TestView.IsVisible = true;
        NavigateTo(index);
    }

    private void BackToResults(object? sender, RoutedEventArgs e) => ShowResults();

    private void ShowResults() {
        TestView.IsVisible = false;
        ResultsView.IsVisible = true;
    }
}
