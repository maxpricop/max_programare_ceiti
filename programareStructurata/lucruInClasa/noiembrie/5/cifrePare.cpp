#include <iostream>

using namespace std;

/*Se da cifre de la 0 pana la 10 (inclusiv 0 si 10)
Sa se afle cate numere pare sunt in acest interval*/
int main() {
    // Declarare si initializare variabila cu numarul de cifra pare
    int cifrePare = 0;

    // Iterare prin fiecare numar de la 0 la 10.
    for (int i = 0; i <= 10; ++i) {
        // Daca numarul este par, se incrementeaza cifrePare
        if (i % 2 == 0) cifrePare++;
    };

    // Afiseaza rezultatul
    cout << "In interval se afla " << cifrePare << " numere pare." << endl;

    return 0;
}