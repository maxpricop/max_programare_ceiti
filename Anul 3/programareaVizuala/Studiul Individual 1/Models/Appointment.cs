namespace BarberDesk.Models;

public class Appointment {
    public string Client { get; set; } = "";
    public string Phone { get; set; } = "";
    public string Barber { get; set; } = "";
    public Service Service { get; set; } = new();
    public DateTime Date {
        get; set;
    }

    public TimeSpan Time {
        get; set;
    }

    public string Status { get; set; } = "Programată";
    public string Notes { get; set; } = "";

    public string Title {
        get {
            return $"{Date:dd.MM.yyyy}   {Time:hh\\:mm}   {Client}";
        }
    }

    public string Details {
        get {
            return $"{Barber} • {Service.Name} • {Service.Price:0.##} MDL • {Status}";
        }
    }
}
