using System.Globalization;
using Avalonia.Controls;
using Avalonia.Interactivity;
using BarberDesk.Data;
using BarberDesk.Models;

namespace BarberDesk.Views;

public partial class AppointmentWindow : Window {
    private readonly ShopData shopData;
    private readonly Appointment? originalAppointment;

    public AppointmentWindow() : this(new ShopData(), null, DateTime.Today) {
    }

    public AppointmentWindow(ShopData shopData, Appointment? existingAppointment, DateTime appointmentDate) {
        InitializeComponent();

        this.shopData = shopData;
        originalAppointment = existingAppointment;

        BarberBox.ItemsSource = shopData.Barbers;

        // Dacă tariful s-a schimbat, programarea păstrează serviciul rezervat anterior.
        List<Service> availableServices = [.. shopData.Services];

        if (existingAppointment != null && !availableServices.Contains(existingAppointment.Service)) {
            availableServices.Add(existingAppointment.Service);
        }

        ServiceBox.ItemsSource = availableServices;
        BarberBox.SelectedIndex = 0;
        ServiceBox.SelectedIndex = 0;
        AppointmentDate.SelectedDate = appointmentDate;

        if (existingAppointment != null) {
            Title = "Editează programarea";
            HeadingText.Text = Title;
            ClientBox.Text = existingAppointment.Client;
            PhoneBox.Text = existingAppointment.Phone;
            BarberBox.SelectedItem = existingAppointment.Barber;
            ServiceBox.SelectedItem = existingAppointment.Service;
            TimeBox.Text = existingAppointment.Time.ToString(@"hh\:mm");
            NotesBox.Text = existingAppointment.Notes;
            ScheduledRadio.IsChecked = existingAppointment.Status == "Programată";
            CompletedRadio.IsChecked = existingAppointment.Status == "Finalizată";
            CancelledRadio.IsChecked = existingAppointment.Status == "Anulată";
        }
    }

    private void Save_Click(object? sender, RoutedEventArgs e) {
        if (!DateTime.TryParseExact((TimeBox.Text ?? "").Trim(), "HH:mm", CultureInfo.InvariantCulture,
            DateTimeStyles.None, out DateTime parsedTime)) {
            ShowError("Introduceți ora în format HH:mm, de exemplu 09:30.");
            return;
        }

        if (AppointmentDate.SelectedDate == null) {
            ShowError("Alegeți data programării.");
            return;
        }

        if (BarberBox.SelectedItem is not string selectedBarber
            || ServiceBox.SelectedItem is not Service selectedService) {
            ShowError("Alegeți frizerul și serviciul.");
            return;
        }

        string selectedStatus = "Programată";

        if (CompletedRadio.IsChecked == true) {
            selectedStatus = "Finalizată";
        } else if (CancelledRadio.IsChecked == true) {
            selectedStatus = "Anulată";
        }

        // Construim un obiect nou. Modificarea câmpurilor nu schimbă direct elementul din listă.
        Appointment savedAppointment = new() {
            Client = (ClientBox.Text ?? "").Trim(),
            Phone = (PhoneBox.Text ?? "").Trim(),
            Barber = selectedBarber,
            Service = selectedService,
            Date = AppointmentDate.SelectedDate.Value.Date,
            Time = parsedTime.TimeOfDay,
            Status = selectedStatus,
            Notes = (NotesBox.Text ?? "").Trim()
        };

        string validationMessage = shopData.Validate(savedAppointment, originalAppointment);

        if (validationMessage != "") {
            ShowError(validationMessage);
            return;
        }

        Close(savedAppointment);
    }

    private void ShowError(string message) {
        ErrorText.Text = message;
        ErrorText.IsVisible = true;
    }

    private void Cancel_Click(object? sender, RoutedEventArgs e) {
        Close();
    }
}
