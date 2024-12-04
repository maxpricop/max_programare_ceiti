#include <iostream>

using namespace std;

/*Exercitiul 28 pagina 15 Turbo Pascal Culegere
Se dau variabilele numerice a, b si c.
Sa se schimbe intre ele valorile acestor variabile, astfel incat:
a sa aiba valoarea lui b
b sa aiba valoarea lui c
c sa aiba valoarea lui a*/
int main() {
    // Declararea variabilelor din conditie si a unei temporare
    int a, b, c, temp;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu variabila a: ";
    cin >> a;
    cout << "Introdu variabila b: ";
    cin >> b;
    cout << "Introdu variabila c: ";
    cin >> c;

    // Schimbarea variabilelor intre ele
    temp = a;
    a = b;
    b = c;
    c = temp;

    // Afisarea rezultatelor finale
    cout << "Varbila a: " << a << endl;
    cout << "Varbila b: " << b << endl;
    cout << "Varbila c: " << c << endl;

    return 0;
}