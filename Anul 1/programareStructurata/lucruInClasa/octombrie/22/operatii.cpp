#include <iostream>

using namespace std;

// Folosirea unei operatii matematica introduse de utilizator
int main() {
    // Declararea operatiei si a numerelor
    char operatie;
    int numar1, numar2;

    // Introducerea variabilelor de utilizator
    cout << "Introdu o operatie: ";
    cin >> operatie;
    cout << "Introdu primul nr: ";
    cin >> numar1;
    cout << "Introdu al doilea nr: ";
    cin >> numar2;

    // Determinarea operatiei si calcularea rezultatului
    switch (operatie) {
        case '*':
            numar1 *= numar2;
            break;
        case '/':
            numar1 /= numar2;
            break;
        case '+':
            numar1 += numar2;
            break;
        case '-':
            numar1 -= numar2;
            break;
        default:
            cout << "Operatia este invalida.";
            return;
    };

    // Afisarea rezultatului
    cout << "Rezultatul este: " << numar1 << endl;

    return 0;
}