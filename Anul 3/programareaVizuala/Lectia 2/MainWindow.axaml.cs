using System;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace Lectia2;

public partial class MainWindow : Window {
    public MainWindow() {
        InitializeComponent();
        SpecialtyComboBox.SelectedIndex = 0;
    }

    private void SpecialtyComboBox_SelectionChanged(object? sender, SelectionChangedEventArgs e) {
        string? specialty = GetSelectedSpecialty();
        ClearFeedback();

        if (specialty is null) {
            return;
        }

        string profile = GetProfile(specialty);
        bool usesLanguages = profile != "operator";

        InstructionLanguageLabel.IsVisible = usesLanguages;
        InstructionLanguageTextBox.IsVisible = usesLanguages;

        ForeignLanguageLabel.IsVisible = usesLanguages;
        ForeignLanguageTextBox.IsVisible = usesLanguages;

        InformaticsLabel.IsVisible = profile != "uman";
        InformaticsTextBox.IsVisible = profile != "uman";

        HistoryLabel.IsVisible = profile == "uman";
        HistoryTextBox.IsVisible = profile == "uman";
    }

    private void CalculateButton_Click(object? sender, RoutedEventArgs e) {
        ClearFeedback();
        string? specialty = GetSelectedSpecialty();

        if (specialty is null) {
            ShowError("Selectează o specialitate.");
            return;
        }

        string profile = GetProfile(specialty);
        double subjectAverage;

        if (!TryReadGrade(ExamAverageTextBox, "Media examenelor", out double examAverage)) {
            return;
        }

        switch (profile) {
            case "real": {
                if (!TryReadGrade(MathematicsTextBox, "Media la matematică", out double mathematics)) {
                    return;
                }

                if (!TryReadGrade(InstructionLanguageTextBox, "Media la limba de instruire", out double instructionLanguage)) {
                    return;
                }

                if (!TryReadGrade(ForeignLanguageTextBox, "Media la limba străină", out double foreignLanguage)) {
                    return;
                }

                if (!TryReadGrade(InformaticsTextBox, "Media la informatică", out double informatics)) {
                    return;
                }

                subjectAverage = (instructionLanguage + foreignLanguage + mathematics + informatics) / 4;
                break;
            }
            case "uman": {
                if (!TryReadGrade(MathematicsTextBox, "Media la matematică", out double mathematics)) {
                    return;
                }

                if (!TryReadGrade(InstructionLanguageTextBox, "Media la limba de instruire", out double instructionLanguage)) {
                    return;
                }

                if (!TryReadGrade(ForeignLanguageTextBox, "Media la limba străină", out double foreignLanguage)) {
                    return;
                }

                if (!TryReadGrade(HistoryTextBox, "Media la istorie", out double history)) {
                    return;
                }

                subjectAverage = (instructionLanguage + foreignLanguage + mathematics + history) / 4;
                break;
            }
            case "operator": {
                if (!TryReadGrade(MathematicsTextBox, "Media la matematică", out double mathematics)) {
                    return;
                }

                if (!TryReadGrade(InformaticsTextBox, "Media la informatică", out double informatics)) {
                    return;
                }

                subjectAverage = (mathematics + informatics) / 2;
                break;
            }
            default: {
                throw new InvalidOperationException("Profil necunoscut.");
            }
        }

        double competitionAverage = 0.6 * subjectAverage + 0.4 * examAverage;

        SpecialtyResultTextBlock.Text = $"Specialitatea: {specialty}";
        ProfileResultTextBlock.Text = $"Profil: {profile}";
        SubjectAverageResultTextBlock.Text = $"Media disciplinelor de profil (MDNP): {subjectAverage:F2}";
        ExamAverageResultTextBlock.Text = $"Media examenelor (MNEA): {examAverage:F2}";
        CompetitionAverageResultTextBlock.Text = $"Media de concurs (MC): {competitionAverage:F2}";
        ResultPanel.IsVisible = true;
    }

    private string? GetSelectedSpecialty() {
        if (SpecialtyComboBox.SelectedItem is ComboBoxItem selectedItem) {
            return selectedItem.Content?.ToString();
        }

        return null;
    }

    private static string GetProfile(string specialty) {
        return specialty switch {
            "Programare" or "Web" or "Rețele" => "real",
            "Secretariat" or "Contabilitate" => "uman",
            "Operator" => "operator",
            _ => throw new InvalidOperationException("Specialitate necunoscută."),
        };
    }

    private bool TryReadGrade(TextBox textBox, string label, out double grade) {
        // Accepts both 8.5 and 8,5.
        string input = (textBox.Text ?? "").Trim().Replace(',', '.');

        if (double.TryParse(input, out grade) && grade >= 1 && grade <= 10) {
            return true;
        }

        ShowError($"{label} trebuie să fie un număr între 1 și 10.");
        textBox.Focus();
        return false;
    }

    private void GradeTextBox_TextChanged(object? sender, TextChangedEventArgs e) {
        ClearFeedback();
    }

    private void ClearFeedback() {
        ResultPanel.IsVisible = false;
        ErrorTextBlock.IsVisible = false;
    }

    private void ShowError(string message) {
        ErrorTextBlock.Text = message;
        ErrorTextBlock.IsVisible = true;
    }
}
