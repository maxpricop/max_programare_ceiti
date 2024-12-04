#include <iostream>

using namespace std;

/*Exercitiul 16 pagina 14 Turbo Pascal Culegere
Se da numarul natural n.
Sa se afle ultima cifra al lui, penultima cifra al lui
si restul si catul impartirii la 9*/
int main()
{
    // Declararea numarului n
    unsigned n;

    // Introducerea numarului de catre utilizator
    cout << "Introdu nr. n: ";
    cin >> n;

    // Calcularea si afisarea rezultatelor
    cout << "Ultima Cifra: " << n % 10 << endl;
    cout << "Penultimea Cifra: " << (n / 10) % 10 << endl;
    cout << "Catul impartirii la 9: " << n / 9 << endl;
    cout << "Restul impartirii la 9: " << n % 9 << endl;

    return 0;
}