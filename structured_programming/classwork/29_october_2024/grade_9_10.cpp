// Nota 9-10 problema 56(b, c), 58
#include <iostream>
#include <cmath>

using namespace std;

bool isWhite(int coord1, int coord2) {
    if (coord1 == coord2) return true;
    else if (coord1 % 2 == 0 && coord2 % 2 == 0) return true;
    else if (coord1 % 2 == 1 && coord2 % 2 == 1) return true;
    else return false;
};
void problema56() {
    // Tabla de sah
    /*
    --1 2 3 4 5 6 7 8 y
    1 a N a N a N a N
    2 N a N a N a N a
    3 a N a N a N a N
    4 N a N a N a N a
    5 a N a N a N a N
    6 N a N a N a N a
    7 a N a N a N a N
    8 N a N a N a N a
    x
    */

    int a, b, c, d;
    cout << "Campul 1 | Introdu coordonata x: "; cin >> a;
    cout << "Campul 1 | Introdu coordonata y: "; cin >> b;
    cout << "Campul 2 | Introdu coordonata x: "; cin >> c;
    cout << "Campul 2 | Introdu coordonata y: "; cin >> d;

    // Campul 1: (a, b)
    // Campul 2: (c, d)

    if (
        (a < 1 || a > 8) ||
        (b < 1 || b > 8) ||
        (c < 1 || c > 8) ||
        (d < 1 || d > 8)
    ) {
        cout << "Coordonatele introduse trebuie sa fie intre 1 si 8" << endl;
        return;
    };

    if ((a == c) && (b == d)) {
        cout << "Campurile trebuie sa fie diferite." << endl;
        return;
    };

    if (isWhite(a, b) && isWhite(c, d)) cout << "Ambele campuri sunt de culoarea alba." << endl;
    else if (!isWhite(a, b) && !isWhite(c, d)) cout << "Ambele campuri sunt de culoarea neagra" << endl;
    else cout << "Campurile sunt de culori diferite" << endl;

    if (abs(c - a) == abs(d - b)) cout << "Un nebun poate ajunge de la campul 1 la campul 2 intr-o singura miscare" << endl;
    else cout << "Un nebun nu poate ajunge de la campul 1 la campul 2 intr-o singura miscare" << endl;
};

void problema58() {
    int x1, y1, x2, y2, x3, y3;
    cout << "Varful 1 | Introdu coordonata x: "; cin >> x1;
    cout << "Varful 1 | Introdu coordonata y: "; cin >> y1;
    cout << "Varful 2 | Introdu coordonata x: "; cin >> x2;
    cout << "Varful 2 | Introdu coordonata y: "; cin >> y2;
    cout << "Varful 3 | Introdu coordonata x: "; cin >> x3;
    cout << "Varful 3 | Introdu coordonata y: "; cin >> y3;

    if (
        !(
            // Verifica ca dreptunghiul sa aiba 2 laturi:
            // O latura trebuie sa aiba 2 varfuri cu aceeasi coordonata x
            // O latura trebuie sa aiba 2 varfuri cu aceeasi coordonata y
            (x1 == x2 || x1 == x3 || x2 == x3) &&
            (y1 == y2 || y1 == y3 || y2 == y3)
        ) || (
            // Verifica daca toate varfurile sunt pe o linie sau au aceleasi coordonate.
            (x1 == x2 && x2 == x3) ||
            (y1 == y2 && y2 == y3)
        )
    ) {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    int x4, y4;

    if (x1 == x2) x4 = x3;
    else if (x1 == x3) x4 = x2;
    else if (x2 == x3) x4 = x1;
    else {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    if (y1 == y2) y4 = y3;
    else if (y1 == y3) y4 = y2;
    else if (y2 == y3) y4 = y1;
    else {
        cout << "Coordonatele introduse nu pot crea un dreptunghi." << endl;
        return;
    };

    cout << "Coordonatele varfului 4 sunt: (" << x4 << ", " << y4 << ")" << endl;
};

int main() {
    cout << "\n----- Problema 56 -----" << endl;
    problema56();

    cout << "\n----- Problema 58 -----" << endl;
    problema58();

    return 0;
};