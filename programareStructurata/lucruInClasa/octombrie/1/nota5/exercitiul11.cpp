#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 11 pagina 14 Turbo Pascal Culegere
Calcularea muchiei unui cub*/
int main()
{
    // Declararea variabilei cu muchia cubului
    float muchie;

    // Introducerea muhciei de catre utilizator
    cout << "Introdu muchia cubului: ";
    cin >> muchie;

    // Valoarea absoluta a muchiei, previne numere negative
    muchie = fabsf(muchie);

    // Calcularea si afisarea rezultatelor
    cout << "Aria Totala: " << 6 * pow(muchie, 2) << endl;
    cout << "Volumul patratului: " << pow(muchie, 3) << endl;

    return 0;
}