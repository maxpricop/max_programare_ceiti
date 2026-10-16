using System.Globalization;
using System.Text;
using BarberDesk.Models;

namespace BarberDesk.Data;

public static class CsvExport {
    public static string Create(List<Appointment> appointments) {
        StringBuilder csvContent = new();
        csvContent.AppendLine("Data;Ora;Client;Telefon;Frizer;Serviciu;Minute;Pret MDL;Stare;Observatii");

        foreach (Appointment appointment in appointments) {
            string[] cells = [
                appointment.Date.ToString("dd.MM.yyyy"),
                appointment.Time.ToString(@"hh\:mm"),
                appointment.Client,
                appointment.Phone,
                appointment.Barber,
                appointment.Service.Name,
                appointment.Service.Minutes.ToString(),
                appointment.Service.Price.ToString(CultureInfo.InvariantCulture),
                appointment.Status,
                appointment.Notes
            ];

            for (int columnIndex = 0; columnIndex < cells.Length; columnIndex++) {
                cells[columnIndex] = EscapeCell(cells[columnIndex]);
            }

            csvContent.AppendLine(string.Join(";", cells));
        }

        return csvContent.ToString();
    }

    private static string EscapeCell(string value) {
        // Textele care seamănă cu formule trebuie deschise ca text în Excel sau LibreOffice.
        string trimmedValue = value.TrimStart();

        if (trimmedValue.StartsWith('=') || trimmedValue.StartsWith('+')
            || trimmedValue.StartsWith('-') || trimmedValue.StartsWith('@')) {
            value = "'" + value;
        }

        return "\"" + value.Replace("\"", "\"\"") + "\"";
    }
}
