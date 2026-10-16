using System.Globalization;
using Avalonia.Controls;
using Avalonia.Interactivity;
using BarberDesk.Data;
using BarberDesk.Models;

namespace BarberDesk.Views;

public partial class CatalogWindow : Window {
    private readonly ShopData shopData;

    public CatalogWindow() : this(new ShopData()) {
    }

    public CatalogWindow(ShopData shopData) {
        InitializeComponent();

        this.shopData = shopData;

        RefreshList();
    }

    private void RefreshList() {
        ServiceList.ItemsSource = new List<Service>(shopData.Services);
        ClearForm();
    }

    private void ClearForm() {
        ServiceList.SelectedItem = null;
        EditorTitle.Text = "Serviciu nou";
        NameBox.Text = "";
        PriceBox.Text = "";
        MinutesBox.Value = 30;
        DeleteButton.IsEnabled = false;
        ErrorText.Text = "";
    }

    private void ServiceList_Changed(object? sender, SelectionChangedEventArgs e) {
        if (ServiceList.SelectedItem is Service service) {
            EditorTitle.Text = "Editează serviciul";
            NameBox.Text = service.Name;
            PriceBox.Text = service.Price.ToString("0.##");
            MinutesBox.Value = service.Minutes;
            DeleteButton.IsEnabled = true;
            ErrorText.Text = "";
        }
    }

    private void Save_Click(object? sender, RoutedEventArgs e) {
        string serviceName = (NameBox.Text ?? "").Trim();

        // Acceptăm atât virgula, cât și punctul ca separator zecimal.
        string priceText = (PriceBox.Text ?? "").Trim().Replace(',', '.');

        if (serviceName.Length < 2) {
            ErrorText.Text = "Introduceți o denumire de cel puțin două caractere.";
            return;
        }

        if (!decimal.TryParse(priceText, NumberStyles.AllowDecimalPoint,
            CultureInfo.InvariantCulture, out decimal servicePrice)
            || servicePrice <= 0 || servicePrice > 10000 || decimal.Round(servicePrice, 2) != servicePrice) {
            ErrorText.Text = "Introduceți un preț între 0,01 și 10000 MDL, cu cel mult două zecimale.";
            return;
        }

        if (MinutesBox.Value == null || MinutesBox.Value < 5 || MinutesBox.Value > 180
            || MinutesBox.Value % 1 != 0) {
            ErrorText.Text = "Durata trebuie să fie un număr întreg între 5 și 180 de minute.";
            return;
        }

        Service? selectedService = ServiceList.SelectedItem as Service;

        foreach (Service service in shopData.Services) {
            if (service != selectedService && service.Name.Equals(serviceName, StringComparison.OrdinalIgnoreCase)) {
                ErrorText.Text = "Există deja un serviciu cu această denumire.";
                return;
            }
        }

        Service savedService = new() {
            Name = serviceName,
            Price = servicePrice,
            Minutes = (int)MinutesBox.Value.Value
        };

        if (selectedService == null) {
            shopData.Services.Add(savedService);
        } else {
            // Înlocuim obiectul din catalog. Programările vechi păstrează obiectul cu tariful rezervat.
            shopData.Services[shopData.Services.IndexOf(selectedService)] = savedService;
        }

        RefreshList();
    }

    private async void Delete_Click(object? sender, RoutedEventArgs e) {
        if (ServiceList.SelectedItem is not Service selectedService) {
            return;
        }

        if (shopData.Services.Count == 1) {
            ErrorText.Text = "Păstrați cel puțin un serviciu în catalog.";
            return;
        }

        ConfirmWindow confirmationDialog = new(
            $"Ștergeți serviciul {selectedService.Name} din catalog? Programările existente se păstrează.");

        if (await confirmationDialog.ShowDialog<bool>(this)) {
            shopData.Services.Remove(selectedService);
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
