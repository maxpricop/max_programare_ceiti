using BarberDesk.Models;

namespace BarberDesk.Data;

public class ShopData {
    public List<Appointment> Appointments { get; } = [];
    public List<string> Barbers { get; } = ["Andrei", "Mihai", "Victor"];
    public List<Service> Services {
        get;
    } = [
        new Service { Name = "Tuns", Minutes = 30, Price = 150 },
        new Service { Name = "Aranjat barbă", Minutes = 15, Price = 80 },
        new Service { Name = "Tuns și barbă", Minutes = 45, Price = 210 }
    ];

    public ShopData() {
        Appointments.Add(new Appointment {
            Client = "Ion Rusu",
            Phone = "060000001",
            Barber = Barbers[0],
            Service = Services[0],
            Date = DateTime.Today,
            Time = new TimeSpan(10, 0, 0)
        });

        Appointments.Add(new Appointment {
            Client = "Dan Munteanu",
            Phone = "060000002",
            Barber = Barbers[1],
            Service = Services[2],
            Date = DateTime.Today,
            Time = new TimeSpan(11, 0, 0)
        });

        Appointments.Add(new Appointment {
            Client = "Alex Popa",
            Phone = "060000003",
            Barber = Barbers[2],
            Service = Services[1],
            Date = DateTime.Today,
            Time = new TimeSpan(14, 30, 0)
        });
    }

    // Returnăm un mesaj dacă datele sunt greșite; textul gol înseamnă că putem salva.
    public string Validate(Appointment appointment, Appointment? originalAppointment) {
        if (appointment.Client.Trim().Length < 2) {
            return "Introduceți numele clientului (cel puțin două caractere).";
        }

        if (!IsValidPhone(appointment.Phone)) {
            return "Telefonul trebuie să conțină între 8 și 15 cifre, cu + opțional la început.";
        }

        bool isAvailableService = Services.Contains(appointment.Service);
        bool isOriginalService = appointment.Service == originalAppointment?.Service;

        if (!Barbers.Contains(appointment.Barber) || (!isAvailableService && !isOriginalService)) {
            return "Alegeți frizerul și serviciul.";
        }

        TimeSpan appointmentEnd = appointment.Time + TimeSpan.FromMinutes(appointment.Service.Minutes);

        if (appointment.Time < new TimeSpan(9, 0, 0) || appointmentEnd > new TimeSpan(18, 0, 0)) {
            return "Programarea trebuie să înceapă și să se termine între 09:00 și 18:00.";
        }

        if (appointment.Status == "Anulată") {
            return "";
        }

        foreach (Appointment existingAppointment in Appointments) {
            // La editare nu comparăm programarea cu ea însăși. Anulările nu ocupă timpul.
            if (existingAppointment == originalAppointment
                || existingAppointment.Date.Date != appointment.Date.Date
                || existingAppointment.Status == "Anulată") {
                continue;
            }

            TimeSpan existingAppointmentEnd = existingAppointment.Time
                + TimeSpan.FromMinutes(existingAppointment.Service.Minutes);
            bool intervalsOverlap = appointment.Time < existingAppointmentEnd
                && appointmentEnd > existingAppointment.Time;

            if (intervalsOverlap && existingAppointment.Barber == appointment.Barber) {
                return "Frizerul are deja o programare în acest interval.";
            }

            if (intervalsOverlap && existingAppointment.Phone == appointment.Phone) {
                return "Clientul are deja o programare în acest interval.";
            }
        }

        return "";
    }

    private static bool IsValidPhone(string phone) {
        // Telefonul rămâne string: un număr întreg ar pierde zero-ul de la început.
        string digits = phone;

        if (digits.StartsWith('+')) {
            digits = digits[1..];
        }

        if (digits.Length < 8 || digits.Length > 15) {
            return false;
        }

        foreach (char character in digits) {
            if (character < '0' || character > '9') {
                return false;
            }
        }

        return true;
    }
}
