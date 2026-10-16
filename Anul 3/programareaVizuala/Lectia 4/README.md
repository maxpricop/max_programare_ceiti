# Test de programare

Run from this directory with the .NET 10 SDK:

```sh
dotnet run
```

The Romanian interface starts with instructions and an **Începe testul** button. The test has 15 C# questions worth 4 points each, for a total of 60 points. There is no time limit.

Use **Înapoi**, **Înainte**, or the numbered question buttons to navigate. Answers persist when switching questions. The summary marks completed questions in blue, partly filled dropdown questions in yellow, and unanswered questions in white. A blue outline identifies the current question. Tooltips and accessibility labels also describe each question's status.

**Finalizează testul** submits the current answers and replaces the test with results in the same window, including when some questions are unanswered. The results show the total score and the points earned for each question. Select any result to review the saved answer, correct answer, and explanation. Review is read-only. **Începe un test nou** clears every answer and starts again.

## Questions and scoring

Questions remain in C#, in `Models/QuestionBank.cs`. The bank contains four single-choice questions, four multiple-choice questions, four dropdown questions, and three written-answer questions.

- Single choice uses radio buttons. Only the correct answer earns 4 points.
- Multiple choice uses checkboxes. Each correct selection adds `4 / number of correct options` points. Each incorrect selection subtracts the same amount. The score cannot fall below zero. Omitting a correct option earns partial credit; selecting every option cannot earn full credit.
- Dropdown questions place two lists inside sentence fragments. Each correctly completed blank earns 2 points independently. Incorrect and unanswered blanks earn zero.
- Written questions use a text box and ask for a specific number or keyword. Responses are compared with accepted answers after trimming, collapsing whitespace, and ignoring capitalization. These are exact short-answer checks, not free-form essay grading. Add accepted variants with `Question.Written` when needed.

Unanswered questions earn zero. Scores use decimal arithmetic and are displayed with up to two decimal places. The total uses the unrounded question scores.

`Models/Question.cs` defines question types, scoring, and attempt responses. `QuestionResponse` keeps selections separate from the question bank. `MainWindow.axaml` defines the start, test, and results views; `MainWindow.axaml.cs` renders the question controls and manages navigation.

## Checks

Run the scoring and Avalonia headless UI checks:

```sh
dotnet run --project Tests/Lectia4.Tests.csproj
```

The checks cover all choice combinations, partial credit, unanswered questions, written-answer normalization, navigation persistence, single-choice exclusivity, in-window results, review, and restart. Add `-- --screenshots` to save rendered views to `/tmp/lectia4-*.png` on Linux.
