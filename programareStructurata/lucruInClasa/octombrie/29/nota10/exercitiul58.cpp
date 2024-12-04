#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 58 pagina 29 Turbo Pascal Culegere
Se dau coordonatele carteziene ale 3 varfuri unui dreptunghi.
Sa se afle coordonatele celui dea patrulea varf*/
int main() {
    // Declararea variabilelor cu coordonatele varfurilor
    int x1, y1, x2, y2, x3, y3;

    // Introducerea coordonatelor de utilizator
    cout << "Varful 1 | Introdu coordonata x: ";
    cin >> x1;
    cout << "Varful 1 | Introdu coordonata y: ";
    cin >> y1;
    cout << "Varful 2 | Introdu coordonata x: ";
    cin >> x2;
    cout << "Varful 2 | Introdu coordonata y: ";
    cin >> y2;
    cout << "Varful 3 | Introdu coordonata x: ";
    cin >> x3;
    cout << "Varful 3 | Introdu coordonata y: ";
    cin >> y3;

    if (!(
            // Verifica ca dreptunghiul sa aiba 2 laturi:
            // O latura trebuie sa aiba 2 varfuri cu aceeasi coordonata x
            // O latura trebuie sa aiba 2 varfuri cu aceeasi coordonata y
            (x1 == x2 || x1 == x3 || x2 == x3) && (y1 == y2 || y1 == y3 || y2 == y3)) ||
        (
            // Verifica daca toate varfurile sunt pe o linie sau au aceleasi coordonate.
            (x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))) {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    // Declararea coordonatelor varfului 4
    int x4, y4;

    // Determinarea coordonatelor x a varfului 4
    if (x1 == x2) x4 = x3;
    else if (x1 == x3) x4 = x2;
    else if (x2 == x3) x4 = x1;
    else {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    // Determinarea coordonatelor y a varfului 4
    if (y1 == y2) y4 = y3;
    else if (y1 == y3) y4 = y2;
    else if (y2 == y3) y4 = y1;
    else {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    // Afisarea coordonatelor varfului 4
    cout << "Coordonatele varfului 4 sunt: (" << x4 << ", " << y4 << ")" << endl;

    return 0;
}