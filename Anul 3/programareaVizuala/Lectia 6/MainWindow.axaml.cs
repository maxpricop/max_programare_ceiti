using System;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Shapes;
using Avalonia.Media;

namespace Lectia6;

public partial class MainWindow : Window {
    public MainWindow() {
        InitializeComponent();

        FirstTextBox.TextChanged += DimensionTextBox_TextChanged;
        SecondTextBox.TextChanged += DimensionTextBox_TextChanged;
        ThirdTextBox.TextChanged += DimensionTextBox_TextChanged;

        FigureComboBox.SelectedIndex = 0;
    }

    private void FigureComboBox_SelectionChanged(object? sender, SelectionChangedEventArgs e) {
        int figure = FigureComboBox.SelectedIndex;

        if (figure < 0) {
            return;
        }

        SecondPanel.IsVisible = figure != 2;
        ThirdPanel.IsVisible = figure == 0;

        if (figure == 0) {
            FirstLabel.Text = "Latura a (m)";
            SecondLabel.Text = "Latura b (m)";
        } else if (figure == 1) {
            FirstLabel.Text = "Lățimea l (m)";
            SecondLabel.Text = "Înălțimea h (m)";
        } else {
            FirstLabel.Text = "Raza r (m)";
        }

        Calculate();
    }

    private void DimensionTextBox_TextChanged(object? sender, TextChangedEventArgs e) {
        Calculate();
    }

    private static bool ReadNumber(TextBox input, out double value) {
        return double.TryParse(input.Text, out value)
            && double.IsFinite(value)
            && value > 0;
    }

    private void Calculate() {
        int figure = FigureComboBox.SelectedIndex;

        ErrorTextBlock.Text = "";
        AreaTextBlock.Text = "";
        PerimeterTextBlock.Text = "";
        TypeTextBlock.Text = "";

        DrawingCanvas.Children.Clear();

        if (figure < 0) {
            return;
        }

        double a;
        double b = 0;
        double c = 0;

        if (!ReadNumber(FirstTextBox, out a)
            || (figure != 2 && !ReadNumber(SecondTextBox, out b))
            || (figure == 0 && !ReadNumber(ThirdTextBox, out c))) {
            ErrorTextBlock.Text = "Introduceți numere pozitive în câmpurile afișate.";
            return;
        }

        double area;
        double perimeter;
        string type = "";
        string areaFormula;
        string perimeterFormula;

        if (figure == 0) {
            if (a + b <= c || a + c <= b || b + c <= a) {
                ErrorTextBlock.Text = "Laturile nu formează un triunghi.";
                return;
            }

            double s = (a + b + c) / 2;

            area = Math.Sqrt(s * (s - a) * (s - b) * (s - c));
            perimeter = a + b + c;
            areaFormula = "√[s(s - a)(s - b)(s - c)]; s = (a + b + c) / 2";
            perimeterFormula = "a + b + c";

            if (a == b && b == c) {
                type = "Echilateral";
            } else if (a == b || a == c || b == c) {
                type = "Isoscel";
            } else {
                type = "Oarecare (scalen)";
            }

            double[] sides = [a, b, c];
            Array.Sort(sides);

            double sum = sides[0] * sides[0] + sides[1] * sides[1];
            double largestSquare = sides[2] * sides[2];

            if (Math.Abs(sum - largestSquare) <= 0.000001 * largestSquare) {
                type += " și dreptunghic";
            }
        } else if (figure == 1) {
            area = a * b;
            perimeter = 2 * (a + b);
            areaFormula = "l × h";
            perimeterFormula = "2 × (l + h)";
        } else {
            area = Math.PI * a * a;
            perimeter = 2 * Math.PI * a;
            areaFormula = "π × r²";
            perimeterFormula = "2 × π × r";
        }

        if (!double.IsFinite(area) || !double.IsFinite(perimeter) || area <= 0) {
            ErrorTextBlock.Text = "Valorile sunt prea mari sau prea mici pentru calcul.";
            return;
        }

        AreaTextBlock.Text = $"Aria ({areaFormula}) = {area:0.###} m²";
        PerimeterTextBlock.Text = $"Perimetrul ({perimeterFormula}) = {perimeter:0.###} m";
        TypeTextBlock.Text = type;

        DrawFigure(a, b, c, area);
    }

    private void DrawFigure(double a, double b, double c, double area) {
        int figure = FigureComboBox.SelectedIndex;
        double width;
        double height;
        double x = 0;
        double left = 0;

        if (figure == 0) {
            height = 2 * area / c;
            x = (b * b + c * c - a * a) / (2 * c);

            left = Math.Min(0, x);
            width = Math.Max(c, x) - left;
        } else if (figure == 1) {
            width = a;
            height = b;
        } else {
            width = 2 * a;
            height = 2 * a;
        }

        double scale = Math.Min(420 / width, 280 / height);
        Shape shape;

        if (figure == 0) {
            shape = new Polygon {
                Points = [
                    new Point(40 - left * scale, 320),
                    new Point(40 + (c - left) * scale, 320),
                    new Point(40 + (x - left) * scale, 320 - height * scale)
                ]
            };
        } else if (figure == 1) {
            shape = new Rectangle();
        } else {
            shape = new Ellipse();
        }

        if (figure != 0) {
            shape.Width = width * scale;
            shape.Height = height * scale;

            Canvas.SetLeft(shape, 40);
            Canvas.SetTop(shape, 320 - shape.Height);
        }

        shape.Fill = Brushes.LightBlue;
        shape.Stroke = Brushes.Blue;
        shape.StrokeThickness = 2;

        DrawingCanvas.Children.Add(shape);
    }
}
