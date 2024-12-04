#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 12 pagina 14 Turbo Pascal Culegere
Calcularea lungimii si ariei unui cerc in baza razei*/
int main()
{
    // Declararea variabilei cu raza cercului
    float raza;

    // Introducerea razei cercului de catre utilizator
    cout << "Introdu raza cercului: ";
    cin >> raza;

    // Valoarea absoluta a razei, previne numere negative
    raza = fabsf(raza);

    // Calcularea si afisarea rezultatelor
    cout << "Lungimea Cercului: " << 2 * M_PI * raza << endl;
    cout << "Aria discului: " << M_PI * pow(raza, 2) << endl;

    return 0;
}