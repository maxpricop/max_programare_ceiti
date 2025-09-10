#include <iostream>

using namespace std;

/*Exercitiul 25 pagina 15 Turbo Pascal Culegere
Se da numarul natural n.
Sa se transforme n mentri in cm
Sa se transforme n kg in mg
Cate tone se afla in n kg
Sa se transforme n ani in luni, saptamani si zile*/
int main() {
    // Declararea numarului n
    unsigned n;

    // Introducerea numarului n de utilizator
    cout << "Introdu nr. n: ";
    cin >> n;

    // Calcularea si afisarea rezultatelor pentru primele 3 exercitii
    cout << "n metri in cm: " << n * 100 << endl;
    cout << "n kg in miligrame: " << n * 1000000 << endl;
    cout << "tone in n kg: " << n / 1000 << endl;

    // Calcularea si afisarea rezultatelor pentru ultimul exercitiu
    unsigned luni = n * 12;
    unsigned saptamani = n * 52;
    unsigned zile = n * 365;
    cout << "luni in n ani: " << luni << endl;
    cout << "saptamani in n ani: " << saptamani << endl;
    cout << "zile in n ani: " << zile << endl;

    return 0;
}