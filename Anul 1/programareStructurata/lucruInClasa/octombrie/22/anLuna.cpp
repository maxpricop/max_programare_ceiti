#include <iostream>

using namespace std;

// Determinarea nr. de zile in luni si daca anul e bisect
int main() {
    // Declararea lunii si anului
    unsigned luna, an;

    // Introducerea variabilelor de utilizator
    cout << "Introdu luna: ";
    cin >> luna;
    cout << "Introdu anul: ";
    cin >> an;

    // Determinarea si afisarea daca anul e bisect sau nu
    if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) cout << "Anul este bisect";
    else cout << "Anul nu este bisect";

    // Determinarea si afisarea nr. de zile ale lunii
    switch (luna) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Luna are 31 de zile" << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Luna are 30 de zile" << endl;
            break;
        case 2:
            if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) cout << "Luna are 29 de zile" << endl;
            else cout << "Luna are 28 de zile" << endl;

            break;
        default:
            cout << "Luna introdusa este invalida" << endl;
    }

    return 0;
}