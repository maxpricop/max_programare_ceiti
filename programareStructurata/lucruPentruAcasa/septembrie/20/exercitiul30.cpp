#include <iostream>

using namespace std;

/*Exercitiul 30 pagina 16 Turbo Pascal Culegere
Se citest de la tastatura 4 numere reale: a, b, c, d.
Sa se interschimbe circular de la stanga la dreapta valorile lor.*/
int main() {
    // Declararea variabilelor din conditie si a unei temporare
    float a, b, c, d, temp;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu variabila a: ";
    cin >> a;
    cout << "Introdu variabila b: ";
    cin >> b;
    cout << "Introdu variabila c: ";
    cin >> c;
    cout << "Introdu variabila d: ";
    cin >> d;

    // Schimbarea variabilelor intre ele
    temp = a;
    a = d;
    d = c;
    c = b;
    b = temp;

    // Afisarea rezultatelor
    cout << "Varbila a: " << a << endl;
    cout << "Varbila b: " << b << endl;
    cout << "Varbila c: " << c << endl;
    cout << "Varbila d: " << d << endl;

    return 0;
}