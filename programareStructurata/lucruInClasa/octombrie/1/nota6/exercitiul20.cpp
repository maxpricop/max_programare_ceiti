#include <iostream>

using namespace std;

/*Exercitiul 20 pagina 15 Turbo Pascal Culegere
Se da numerele reale x si y
Sa se afiseze dacac x > y*/
int main()
{
    // Declararea numerelor
    float x, y;

    // Introducerea numerelor de utilizator
    cout << "Introdu nr. x: ";
    cin >> x;
    cout << "Introdu nr. y: ";
    cin >> y;

    // Afisarea rezultatului
    cout << "x > y: ";
    x > y ? cout << "Adevarat" << endl : cout << "Fals" << endl;

    return 0;
}