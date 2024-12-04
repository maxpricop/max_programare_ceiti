#include <iostream>

using namespace std;

// Determinarea daca litera e vocala sau consoana
int main() {
    // Declararea literei
    char litera;

    // Introducerea literei de utilizator
    cout << "Introdu o litera: ";
    cin >> litera;

    // Determinarea si afisarea rezultatului
    switch (litera) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "Litera este o vocala";
            break;
        default:
            cout << "Litera este o consoana";
    };

    return 0;
}