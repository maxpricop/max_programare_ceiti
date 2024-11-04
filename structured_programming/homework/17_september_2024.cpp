// Homework for 17 september -> 20 september
#include <iostream>
#include <cmath>

using namespace std;

void ex8()
{
    int x, y;
    cout << "Introdu variabila nr. 1: "; cin >> x;
    cout << "Introdu variabila nr. 2: "; cin >> y;

    cout << "Produsul variabilelor: " << x * y << endl;
    cout << "Catul numerelor: " << x / y << endl;
}

void ex10()
{
    int latura;
    cout << "Introdu latura patratului: "; cin >> latura;

    cout << "Perimetrul patratului: " << latura * 4 << endl;
    cout << "Aria patratului: " << latura * latura << endl;
}

void ex14()
{
    unsigned int n;
    float r;

    cout << "Introdu numarul laturilor poligonului: "; cin >> n;
    cout << "Introdu raza cercului circumscris: "; cin >> r;

    float latura = 2 * r * sin(M_PI / n);

    float perimeter = latura * n;
    float area = 0.25 * n * (latura * latura) * (1 / tan(M_PI / n));

    float r_inscris = latura / (2 * tan(M_PI / n));
    float nr_diagonale = n * (n-3) / 2;

    // cout << "Latura poligonului: " << latura << endl;
    cout << "Perimetrul poligonului: " << perimeter << endl;
    cout << "Area poligonului: " << area << endl;
    cout << "Raza cercului inscris: " << r_inscris << endl;
    cout << "Numarul diagonalelor: " << nr_diagonale << endl;
}

int main()
{
    cout << "----- Exercitiul 8 -----" << endl;
    ex8();

    cout << "----- Exercitiul 10 -----" << endl;
    ex10();

    cout << "----- Exercitiul 14 -----" << endl;
    ex14();

    return 0;
}
