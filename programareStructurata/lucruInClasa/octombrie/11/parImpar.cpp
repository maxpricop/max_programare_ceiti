#include <iostream>

using namespace std;

// Determinare daca un numar este par sau impar
int main() {
    // Declararea numarului
    int numar;

    // Introducerea numarului de utilizator
    cout << "Introdu un nr.: ";
    cin >> numar;

    // Determinarea si afisarea rezultatelor
    if (numar % 2 == 0) cout << "Nr. este par" << endl;
    else cout << "Nr. este impar" << endl;

    return 0;
}