using System.Text;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Platform.Storage;
using BarberDesk.Data;
using BarberDesk.Models;

namespace BarberDesk.Views;

public partial class MainWindow : Window {
    private readonly ShopData shopData;
    private bool isFilterRefreshEnabled;
    private List<Appointment> filteredAppointments = [];

    public MainWindow() : this(new ShopData()) {
    }

    public MainWindow(ShopData shopData) {
        InitializeComponent();

        this.shopData = shopData;
        LoadBarbers();

        StateFilter.SelectedIndex = 0;
        DateFilter.SelectedDate = DateTime.Today;

        isFilterRefreshEnabled = true;

        LoadAppointments();
    }

    private void LoadAppointments() {
        List<Appointment> matchingAppointments = [];
        string searchText = (SearchBox.Text ?? "").Trim();

        foreach (Appointment appointment in shopData.Appointments) {
            if (AllDatesCheck.IsChecked != true &&
                appointment.Date.Date != DateFilter.SelectedDate?.Date) {
                continue;
            }

            if (BarberFilter.SelectedIndex > 0 && appointment.Barber != (string?)BarberFilter.SelectedItem) {
                continue;
            }

            if (StateFilter.SelectedIndex > 0 &&
                appointment.Status != ((ComboBoxItem)StateFilter.SelectedItem!).Content?.ToString()) {
                continue;
            }

            if (!appointment.Client.Contains(searchText, StringComparison.OrdinalIgnoreCase) &&
                !appointment.Phone.Contains(searchText)) {
                continue;
            }

            matchingAppointments.Add(appointment);
        }

        matchingAppointments.Sort(CompareAppointments);
        filteredAppointments = matchingAppointments;

        AppointmentList.ItemsSource = matchingAppointments;
        AppointmentList.SelectedItem = null;

        EditButton.IsEnabled = false;
        DeleteButton.IsEnabled = false;
        EmptyText.IsVisible = matchingAppointments.Count == 0;
        StatusText.Text = $"Programări afișate: {matchingAppointments.Count} / {shopData.Appointments.Count}";

        ShowSummary();
    }

    private void ShowSummary() {
        int scheduledCount = 0;
        int completedCount = 0;
        int cancelledCount = 0;
        decimal completedServicesTotal = 0;

        foreach (Appointment appointment in filteredAppointments) {
            if (appointment.Status == "Finalizată") {
                completedCount++;
                completedServicesTotal += appointment.Service.Price;
            } else if (appointment.Status == "Anulată") {
                cancelledCount++;
            } else {
                scheduledCount++;
            }
        }

        SummaryText.Text = $"Programate: {scheduledCount} • Finalizate: {completedCount} • Anulate: {cancelledCount}"
            + $" • Valoare servicii finalizate: {completedServicesTotal:0.##} MDL";
    }

    private void LoadBarbers() {
        BarberFilter.Items.Clear();
        BarberFilter.Items.Add("Toți frizerii");

        foreach (string barber in shopData.Barbers) {
            BarberFilter.Items.Add(barber);
        }

        BarberFilter.SelectedIndex = 0;
    }

    private int CompareAppointments(Appointment firstAppointment, Appointment secondAppointment) {
        int dateComparison = firstAppointment.Date.CompareTo(secondAppointment.Date);

        if (dateComparison != 0) {
            return dateComparison;
        }

        return firstAppointment.Time.CompareTo(secondAppointment.Time);
    }

    private void Filter_Changed(object? sender, RoutedEventArgs e) {
        if (isFilterRefreshEnabled) {
            LoadAppointments();
        }
    }

    private void DateFilter_Changed(object? sender, DatePickerSelectedValueChangedEventArgs e) {
        if (isFilterRefreshEnabled) {
            LoadAppointments();
        }
    }

    private void AllDates_Changed(object? sender, RoutedEventArgs e) {
        if (isFilterRefreshEnabled) {
            DateFilter.IsEnabled = AllDatesCheck.IsChecked != true;
            LoadAppointments();
        }
    }

    private void AppointmentList_SelectionChanged(object? sender, SelectionChangedEventArgs e) {
        bool hasSelectedAppointment = AppointmentList.SelectedItem is Appointment;
        EditButton.IsEnabled = hasSelectedAppointment;
        DeleteButton.IsEnabled = hasSelectedAppointment;
    }

    private async void Add_Click(object? sender, RoutedEventArgs e) {
        AppointmentWindow appointmentDialog = new(shopData, null, DateFilter.SelectedDate?.Date ?? DateTime.Today);
        Appointment? savedAppointment = await appointmentDialog.ShowDialog<Appointment?>(this);

        if (savedAppointment != null) {
            shopData.Appointments.Add(savedAppointment);
            LoadAppointments();
            StatusText.Text += " • Programarea a fost adăugată.";
        }
    }

    private async void Edit_Click(object? sender, RoutedEventArgs e) {
        if (AppointmentList.SelectedItem is not Appointment selectedAppointment) {
            return;
        }

        AppointmentWindow appointmentDialog = new(shopData, selectedAppointment, selectedAppointment.Date);
        Appointment? savedAppointment = await appointmentDialog.ShowDialog<Appointment?>(this);

        if (savedAppointment != null) {
            // Înlocuim elementul numai după salvare; butonul Renunță păstrează datele inițiale.
            int appointmentIndex = shopData.Appointments.IndexOf(selectedAppointment);
            shopData.Appointments[appointmentIndex] = savedAppointment;
            LoadAppointments();
            StatusText.Text += " • Programarea a fost modificată.";
        }
    }

    private async void Delete_Click(object? sender, RoutedEventArgs e) {
        if (AppointmentList.SelectedItem is not Appointment selectedAppointment) {
            return;
        }

        ConfirmWindow confirmationDialog = new(
            $"Ștergeți programarea pentru {selectedAppointment.Client} din {selectedAppointment.Date:dd.MM.yyyy}?"
            + " Pentru a păstra programarea în listă, editați-o și alegeți starea Anulată.");
        bool confirmed = await confirmationDialog.ShowDialog<bool>(this);

        if (confirmed) {
            shopData.Appointments.Remove(selectedAppointment);
            LoadAppointments();
            StatusText.Text += " • Programarea a fost ștearsă.";
        }
    }

    private async void Services_Click(object? sender, RoutedEventArgs e) {
        CatalogWindow servicesDialog = new(shopData);
        await servicesDialog.ShowDialog(this);
    }

    private async void Barbers_Click(object? sender, RoutedEventArgs e) {
        BarbersWindow barbersDialog = new(shopData);
        await barbersDialog.ShowDialog(this);

        isFilterRefreshEnabled = false;
        LoadBarbers();
        isFilterRefreshEnabled = true;

        LoadAppointments();
    }

    private void Reset_Click(object? sender, RoutedEventArgs e) {
        isFilterRefreshEnabled = false;

        SearchBox.Text = "";
        BarberFilter.SelectedIndex = 0;
        StateFilter.SelectedIndex = 0;
        AllDatesCheck.IsChecked = false;
        DateFilter.IsEnabled = true;
        DateFilter.SelectedDate = DateTime.Today;

        isFilterRefreshEnabled = true;

        LoadAppointments();
    }

    private async void Export_Click(object? sender, RoutedEventArgs e) {
        if (!StorageProvider.CanSave) {
            StatusText.Text = "Salvarea fișierelor nu este disponibilă pe acest sistem.";
            return;
        }

        try {
            IStorageFile? file = await StorageProvider.SaveFilePickerAsync(new FilePickerSaveOptions {
                Title = "Exportă programările afișate",
                SuggestedFileName = "programari.csv",
                DefaultExtension = "csv",
                FileTypeChoices = [new FilePickerFileType("Fișier CSV") { Patterns = ["*.csv"] }]
            });

            if (file == null) {
                return;
            }

            using (file)
            using (Stream stream = await file.OpenWriteAsync()) {
                stream.SetLength(0);

                using StreamWriter writer = new(stream, new UTF8Encoding(true));
                await writer.WriteAsync(CsvExport.Create(filteredAppointments));
            }

            StatusText.Text = $"Au fost exportate {filteredAppointments.Count} programări.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            StatusText.Text = "Fișierul nu a putut fi salvat. Alegeți un dosar în care aveți drept de scriere.";
        }
    }
}
