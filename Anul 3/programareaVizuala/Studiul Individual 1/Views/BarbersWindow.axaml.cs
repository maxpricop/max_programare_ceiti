using Avalonia.Controls;
using Avalonia.Interactivity;
using BarberDesk.Data;
using BarberDesk.Models;

namespace BarberDesk.Views;

public partial class BarbersWindow : Window {
    private readonly ShopData shopData;

    public BarbersWindow() : this(new ShopData()) {
    }

    public BarbersWindow(ShopData shopData) {
        InitializeComponent();

        this.shopData = shopData;

        RefreshList();
    }

    private void RefreshList() {
        BarberList.ItemsSource = new List<string>(shopData.Barbers);
        ClearForm();
    }

    private void ClearForm() {
        BarberList.SelectedItem = null;
        EditorTitle.Text = "Frizer nou";
        NameBox.Text = "";
        DeleteButton.IsEnabled = false;
        ErrorText.Text = "";
    }

    private void BarberList_Changed(object? sender, SelectionChangedEventArgs e) {
        if (BarberList.SelectedItem is string barberName) {
            EditorTitle.Text = "Editează frizerul";
            NameBox.Text = barberName;
            DeleteButton.IsEnabled = true;
            ErrorText.Text = "";
        }
    }

    private void Save_Click(object? sender, RoutedEventArgs e) {
        string barberName = (NameBox.Text ?? "").Trim();
        string? selectedBarberName = BarberList.SelectedItem as string;

        if (barberName.Length < 2) {
            ErrorText.Text = "Introduceți un nume de cel puțin două caractere.";
            return;
        }

        foreach (string barber in shopData.Barbers) {
            if (barber != selectedBarberName && barber.Equals(barberName, StringComparison.OrdinalIgnoreCase)) {
                ErrorText.Text = "Există deja un frizer cu acest nume.";
                return;
            }
        }

        if (selectedBarberName == null) {
            shopData.Barbers.Add(barberName);
        } else {
            shopData.Barbers[shopData.Barbers.IndexOf(selectedBarberName)] = barberName;

            // Corectarea numelui se aplică și programărilor acelui frizer.
            foreach (Appointment appointment in shopData.Appointments) {
                if (appointment.Barber == selectedBarberName) {
                    appointment.Barber = barberName;
                }
            }
        }

        RefreshList();
    }

    private async void Delete_Click(object? sender, RoutedEventArgs e) {
        if (BarberList.SelectedItem is not string selectedBarberName) {
            return;
        }

        if (shopData.Barbers.Count == 1) {
            ErrorText.Text = "Păstrați cel puțin un frizer.";
            return;
        }

        foreach (Appointment appointment in shopData.Appointments) {
            if (appointment.Barber == selectedBarberName) {
                ErrorText.Text = "Frizerul are programări în listă și nu poate fi șters.";
                return;
            }
        }

        ConfirmWindow confirmationDialog = new($"Ștergeți frizerul {selectedBarberName}?");

        if (await confirmationDialog.ShowDialog<bool>(this)) {
            shopData.Barbers.Remove(selectedBarberName);
            RefreshList();
        }
    }

    private void New_Click(object? sender, RoutedEventArgs e) {
        ClearForm();
    }

    private void Close_Click(object? sender, RoutedEventArgs e) {
        Close();
    }
}
