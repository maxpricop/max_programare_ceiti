using Avalonia.Controls;
using Avalonia.Interactivity;

namespace BarberDesk.Views;

public partial class ConfirmWindow : Window {
    public ConfirmWindow() : this("Confirmați acțiunea?") {
    }

    public ConfirmWindow(string message) {
        InitializeComponent();
        MessageText.Text = message;
    }

    private void Yes_Click(object? sender, RoutedEventArgs e) {
        Close(true);
    }

    private void No_Click(object? sender, RoutedEventArgs e) {
        Close(false);
    }
}
