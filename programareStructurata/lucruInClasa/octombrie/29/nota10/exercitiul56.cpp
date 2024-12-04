#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 56 (b si c) pagina 29 Turbo Pascal Culegere
Se dau numerele a, b, c, d reprezentand fiecare cate o coordonata intr-o masa de sah
Sa se determine daca campurile (a, b) si (c, d) sunt de aceeasi culoare
Sa se determine daca nebunul situat pe (a, b) poate ajunge dintr-o miscare la (c, d)*/

/*Tabla de sah
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
int main() {
    // Declararea variabilelor din conditie
    int a, b, c, d;

    // Introducerea numerelor de utilizator
    cout << "Campul 1 | Introdu coordonata x: ";
    cin >> a;
    cout << "Campul 1 | Introdu coordonata y: ";
    cin >> b;
    cout << "Campul 2 | Introdu coordonata x: ";
    cin >> c;
    cout << "Campul 2 | Introdu coordonata y: ";
    cin >> d;

    // Prevenirea coordonatelor infara mesii de sah
    if ((a < 1 || a > 8) || (b < 1 || b > 8) || (c < 1 || c > 8) || (d < 1 || d > 8)) {
        cout << "Coordonatele introduse trebuie sa fie intre 1 si 8" << endl;
        return;
    };

    // Prevenirea introducerii aceluiasi camp de 2 ori
    if ((a == c) && (b == d)) {
        cout << "Campurile trebuie sa fie diferite." << endl;
        return;
    };

    // Verifica daca primul camp e alb
    if ((a == b) || (a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1)) {
        // Primul camp e abl
        if ((c == d) || (c % 2 == 0 && d % 2 == 0) || (c % 2 == 1 && d % 2 == 1)) {
            // Al doilea camp tot e alb
            cout << "Ambele campuri sunt de culoarea alba." << endl;
        } else {
            // Al doilea camp e negru
            cout << "Campurile sunt de culori diferite." << endl;
        }
    } else {
        // Primul camp e negru
        if ((c == d) || (c % 2 == 0 && d % 2 == 0) || (c % 2 == 1 && d % 2 == 1)) {
            // Al doilea camp e alb
            cout << "Campurile sunt de culori diferite." << endl;
        } else {
            // Al doilea camp tot e negru
            cout << "Ambele campuri sunt de culoarea neagra." << endl;
        }
    }

    if (abs(c - a) == abs(d - b)) cout << "Un nebun poate ajunge de la campul 1 la 2 intr-o singura miscare" << endl;
    else cout << "Un nebun nu poate ajunge de la campul 1 la 2 intr-o singura miscare" << endl;

    return 0;
}