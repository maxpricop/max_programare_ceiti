using System.Globalization;
using Avalonia;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Markup.Xaml;
using BarberDesk.Views;

namespace BarberDesk;

public class App : Application {
    public override void Initialize() {
        // Datele și sumele sunt afișate în formatul folosit în Republica Moldova.
        CultureInfo displayCulture = new("ro-MD");
        CultureInfo.CurrentCulture = displayCulture;
        CultureInfo.CurrentUICulture = displayCulture;

        AvaloniaXamlLoader.Load(this);
    }

    public override void OnFrameworkInitializationCompleted() {
        if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop) {
            desktop.MainWindow = new MainWindow();
        }

        base.OnFrameworkInitializationCompleted();
    }
}
