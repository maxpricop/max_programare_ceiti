#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 14 (b) pagina 23 Turbo Pascal Culegere
Sa se rezolve ecuatia: ax^2 + bx + c = 0*/
int main()
{
    // Declararea celor 3 numere din ecuatie
    float a, b, c;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;
    cout << "Introdu numarul c: ";
    cin >> c;

    // Calcularea delta si radical din delta
    float delta = pow(b, 2) - 4 * a * c;
    float sqrtDelta = sqrt(delta);

    // Calcularea si afisarea solutiilor
    (delta < 0)
        ? cout << "Ecuatia nu are solutii deoarece delta e mai mic ca 0. Calcularea solutiilor e imposibila." << endl
    : (delta == 0)
        ? cout << "Delta este egala cu " << delta << ", ecuatia are doar o solutie: " << -b / (2 * a) << endl
        : cout << "Ecuatia are 2 solutii: " << (-b + sqrtDelta) / (2 * a) << ", " << (-b - sqrtDelta) / (2 * a) << endl;

    return 0;
}