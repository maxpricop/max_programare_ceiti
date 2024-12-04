#include <iostream>

using namespace std;

/*Exercitiul 27 pagina 15 Turbo Pascal Culegere
Se dau variabilele a si b. Sa se schimbe intre ele valorile*/
int main() {
    // Declararea variabilelor a si b si a unei temporare pentru schimbare
    int a, b, temp;

    // Introducerea a si b de utilizator
    cout << "Introdu nr. a: ";
    cin >> a;
    cout << "Introdu nr. b: ";
    cin >> b;

    // Schimbarea valorilor intre ele
    temp = a;
    a = b;
    b = temp;

    // Afisarea rezultatelor
    cout << "a dupa schimbare: " << a << endl;
    cout << "b dupa schimbare: " << b << endl;

    return 0;
}