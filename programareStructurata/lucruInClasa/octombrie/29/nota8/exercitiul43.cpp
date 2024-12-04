#include <iostream>

using namespace std;

/*Exercitiul 43 pagina 27 Turbo Pascal Culegere
Se dau numerele intregi a, b, c, d.
Sa se afiseze numerele in ordine crescatoare si descrescatoare*/
int main() {
    // Declararea variabilelor din conditie
    int a, b, c, d;

    // Introducerea numerelor de utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;
    cout << "Introdu numarul c: ";
    cin >> c;
    cout << "Introdu numarul d: ";
    cin >> d;

    /*Variabile ce stocheaza numerele introduse:
    n1 = cel mai mare numar
    n4 = cel mai mic numar*/
    int n1, n2, n3, n4;

    // Determinarea celui mai mare numar
    if (a > b && a > c && a > d) n1 = a;
    else if (b > a && b > c && b > d) n1 = b;
    else if (c > a && c > b && c > d) n1 = c;
    else n1 = d;

    // Determinarea celui mai mic numar
    if (a < b && a < c && a < d) n4 = a;
    else if (b < a && b < c && b < d) n4 = b;
    else if (c < a && c < b && c < d) n4 = c;
    else n4 = d;

    /*Determinarea numerelor din mijloc
    Valori din mijloc posibile: AB, AC, AD, BA, BC, BC, CA, CB, CD, DA, DB, DC
    Valori din mijloc posibile fara duplicates: AB, AC, AD, BC, BD, CD (6 cazuri)*/
    if ((a != n1 && a != n4) && (b != n1 && b != n4)) {
        // Cand A si B sunt valorile din mijloc
        n2 = (a > b) ? a : b;
        n3 = (a < b) ? a : b;
    } else if ((a != n1 && a != n4) && (c != n1 && c != n4)) {
        // Cand A si C sunt valorile din mijloc
        n2 = (a > c) ? a : c;
        n3 = (a < c) ? a : c;
    } else if ((a != n1 && a != n4) && (d != n1 && d != n4)) {
        // Cand A si D sunt valorile din mijloc
        n2 = (a > d) ? a : d;
        n3 = (a < d) ? a : d;
    } else if ((b != n1 && b != n4) && (c != n1 && c != n4)) {
        // Cand B si C sunt valorile din mijloc
        n2 = (b > c) ? b : c;
        n3 = (b < c) ? b : c;
    } else if ((b != n1 && b != n4) && (d != n1 && d != n4)) {
        // Cand B si D sunt valorile din mijloc
        n2 = (b > d) ? b : d;
        n3 = (b < d) ? b : d;
    } else {
        // Cand C si D sunt valorile din mijloc
        n2 = (c > d) ? c : d;
        n3 = (c < d) ? c : d;
    };

    // Afisarea rezultatelor
    cout << "Numerele in ordine descrescatoare sunt: " << n1 << ", " << n2 << ", " << n3 << ", " << n4 << endl;
    cout << "Numerele in ordine crescatoare sunt: " << n4 << ", " << n3 << ", " << n2 << ", " << n1 << endl;

    return 0;
}