#include <cmath>
#include <iostream>

using namespace std;

/* Calcularea ariei, perimetrului, numarul diagonalelor si raza cercului inscris
intrun poligon in baza numarului de laturi si a razei cercului circumscris*/
int main()
{
    /*Declararea variabilelor:
    n = nr. de laturi a poligonului
    r = raza cercului circumscris a poligonului*/
    unsigned n;
    float r;

    // Introducerea datelor de catre utilizator
    cout << "Introdu numarul laturilor poligonului: ";
    cin >> n;
    cout << "Introdu raza cercului circumscris: ";
    cin >> r;

    // Calcularea numarului de diagonale dupa formula
    float nr_diagonale = n * (n - 3) / 2;

    // Calcularea laturei poligonului in baza formulei
    float latura = 2 * r * sin(M_PI / n);

    // Calcularea ariei si perimetrului poligonului dupa formula cu ajutorul laturii
    float perimetru = latura * n;
    float aria = 0.25 * n * (latura * latura) * (1 / tan(M_PI / n));

    // Calcularea razei cercului inscris dupa formula cu ajutorul laturii
    float r_inscris = latura / (2 * tan(M_PI / n));

    // cout << "Latura poligonului: " << latura << endl;
    cout << "Perimetrul poligonului: " << perimetru << endl;
    cout << "Area poligonului: " << aria << endl;
    cout << "Raza cercului inscris: " << r_inscris << endl;
    cout << "Numarul diagonalelor: " << nr_diagonale << endl;

    return 0;
}