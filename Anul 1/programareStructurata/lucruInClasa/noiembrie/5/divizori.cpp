#include <iostream>

using namespace std;

/*Se da un nr natural n.
Sa se determine si sa se afiseze la ecran toti divizorii acestui numar*/
int main() {
    // Declarare variabila din conditie
    unsigned n;

    // Introducerea valorii numarului
    cout << "Introdu un numar: ";
    cin >> n;

    // Declara si initializeaza numarul de divizori. Setat la 1 ca numarul tot timpul se divide cu dansul
    int divizori = 1;

    // Itereaza prin jumate de n (divizorul maxim al numarului este n / 2)
    for (int i = 1; i <= n / 2; ++i) {
        // Daca n se divide cu acel numar, numarul de divizori se incrementeaza
        if (n % i == 0) divizori++;
    };

    // Afiseaza rezultatele
    cout << n << " are " << divizori << " divizori" << endl;

    return 0;
}