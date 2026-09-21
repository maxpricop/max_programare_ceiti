using System;
using System.Collections.Generic;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace Lectia3;

public partial class MainWindow : Window {
    private static readonly Dictionary<string, ExchangeRate> ExchangeRates = new() {
        ["MDL"] = new ExchangeRate(1.00m, 1.00m),
        ["EUR"] = new ExchangeRate(19.25m, 19.55m),
        ["USD"] = new ExchangeRate(17.10m, 17.35m),
        ["RON"] = new ExchangeRate(3.80m, 3.95m)
    };

    public MainWindow() {
        InitializeComponent();

        OriginalCurrencyComboBox.SelectedIndex = 0;
        FinalCurrencyComboBox.SelectedIndex = 1;

        UpdateCurrencyAvailability();
    }

    private void MoneyTextBox_TextChanged(object? sender, TextChangedEventArgs e) {
        ClearResult();
        ValidateCurrentInput();
    }

    private void OriginalCurrencyComboBox_SelectionChanged(object? sender, SelectionChangedEventArgs e) {
        UpdateCurrencyAvailability();
        ClearResult();
    }

    private void FinalCurrencyComboBox_SelectionChanged(object? sender, SelectionChangedEventArgs e) {
        UpdateCurrencyAvailability();
        ClearResult();
    }

    private void CalculateButton_Click(object? sender, RoutedEventArgs e) {
        HideError();
        ClearResult();

        if (!TryGetValidInput(out decimal amount, out string originalCurrency, out string finalCurrency)) {
            return;
        }

        try {
            decimal result = ConvertCurrency(amount, originalCurrency, finalCurrency);
            ShowResult(amount, result, originalCurrency, finalCurrency);
        } catch (OverflowException) {
            ShowError("Suma este prea mare pentru această conversie.");
        }
    }

    private static decimal ConvertCurrency(
        decimal amount,
        string originalCurrency,
        string finalCurrency
    ) {
        decimal amountInMdl;

        if (originalCurrency == "MDL") {
            amountInMdl = amount;
        } else {
            ExchangeRate originalRate = ExchangeRates[originalCurrency];
            amountInMdl = amount * originalRate.Buy;
        }

        if (finalCurrency == "MDL") {
            return amountInMdl;
        }

        ExchangeRate finalRate = ExchangeRates[finalCurrency];
        return amountInMdl / finalRate.Sell;
    }

    private void ShowResult(
        decimal originalAmount,
        decimal result,
        string originalCurrency,
        string finalCurrency
    ) {
        ResultTextBlock.Text = $"{result:F2} {finalCurrency}";
        ConversionSummaryTextBlock.Text = $"{originalAmount:F2} {originalCurrency} = {result:F2} {finalCurrency}";

        RateDetailsTextBlock.Text = GetRateDescription(originalCurrency, finalCurrency);
        ResultBorder.IsVisible = true;
    }

    private static string GetRateDescription(
        string originalCurrency,
        string finalCurrency
    ) {
        if (originalCurrency == "MDL") {
            ExchangeRate rate = ExchangeRates[finalCurrency];
            return $"{finalCurrency} Vânzare = {rate.Sell:F2} MDL";
        }

        if (finalCurrency == "MDL") {
            ExchangeRate rate = ExchangeRates[originalCurrency];
            return $"{originalCurrency} Cumpărare = {rate.Buy:F2} MDL";
        }

        ExchangeRate originalRate = ExchangeRates[originalCurrency];
        ExchangeRate finalRate = ExchangeRates[finalCurrency];

        return $"{originalCurrency} Cumpărare = {originalRate.Buy:F2} MDL; {finalCurrency} Vânzare = {finalRate.Sell:F2} MDL";
    }

    private bool TryGetValidInput(
        out decimal amount,
        out string originalCurrency,
        out string finalCurrency
    ) {
        amount = 0;

        originalCurrency = GetSelectedCurrency(OriginalCurrencyComboBox) ?? "";
        finalCurrency = GetSelectedCurrency(FinalCurrencyComboBox) ?? "";

        if (string.IsNullOrWhiteSpace(MoneyTextBox.Text)) {
            ShowError("Introduceți suma.");
            return false;
        }

        if (!TryParseMoney(MoneyTextBox.Text, out amount)) {
            ShowError("Suma introdusă nu este validă.");
            return false;
        }

        if (amount <= 0) {
            ShowError("Suma trebuie să fie mai mare decât 0.");
            return false;
        }

        if (string.IsNullOrEmpty(originalCurrency)) {
            ShowError("Selectați valuta originală.");
            return false;
        }

        if (string.IsNullOrEmpty(finalCurrency)) {
            ShowError("Selectați valuta finală.");
            return false;
        }

        if (originalCurrency == finalCurrency) {
            ShowError("Valuta originală și valuta finală nu pot fi identice.");
            return false;
        }

        return true;
    }

    private void ValidateCurrentInput() {
        HideError();

        if (string.IsNullOrWhiteSpace(MoneyTextBox.Text)) {
            return;
        }

        if (!TryParseMoney(MoneyTextBox.Text, out decimal amount)) {
            ShowError("Suma introdusă nu este validă.");
            return;
        }

        if (amount <= 0) {
            ShowError("Suma trebuie să fie mai mare decât 0.");
        }
    }

    private static bool TryParseMoney(string text, out decimal amount) {
        string normalized = text.Trim().Replace(',', '.');
        return decimal.TryParse(
            normalized,
            out amount
        );
    }

    private void UpdateCurrencyAvailability() {
        string? originalCurrency = GetSelectedCurrency(OriginalCurrencyComboBox);
        string? finalCurrency = GetSelectedCurrency(FinalCurrencyComboBox);

        foreach (object? control in OriginalCurrencyComboBox.Items) {
            if (control is not ComboBoxItem item) {
                continue;
            }

            string? currency = item.Content?.ToString();
            item.IsEnabled = item == OriginalCurrencyComboBox.SelectedItem || currency != finalCurrency;
        }

        foreach (object? control in FinalCurrencyComboBox.Items) {
            if (control is not ComboBoxItem item) {
                continue;
            }

            string? currency = item.Content?.ToString();
            item.IsEnabled = item == FinalCurrencyComboBox.SelectedItem || currency != originalCurrency;
        }
    }

    private static string? GetSelectedCurrency(ComboBox comboBox) {
        if (comboBox.SelectedItem is not ComboBoxItem item) {
            return null;
        }

        return item.Content?.ToString();
    }

    private void ClearResult() {
        ResultBorder.IsVisible = false;

        ResultTextBlock.Text = "";
        ConversionSummaryTextBlock.Text = "";
        RateDetailsTextBlock.Text = "";
    }

    private void ShowError(string message) {
        ErrorTextBlock.Text = message;
        ErrorTextBlock.IsVisible = true;
    }

    private void HideError() {
        ErrorTextBlock.Text = "";
        ErrorTextBlock.IsVisible = false;
    }

    private sealed record ExchangeRate(
        decimal Buy,
        decimal Sell
    );
}
