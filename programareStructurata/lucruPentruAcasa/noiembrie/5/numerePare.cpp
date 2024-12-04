#include <iostream>

using namespace std;

// Sa se calculeze suma primelor N numere pare.
int main() {
    /*Declararea variabilelor
    n = cate numere pare trebuie sa fie calculate
    suma = suma numerelor pare
    */
    unsigned n = 1;
    unsigned long long sum = 0;

    // Introducerea lui n de catre utilizator
    cout << "Introdu cate numere pare vrei sa aduni: ";
    cin >> n;

    /*Iterarea prin fiecare numar natural de la 0 in sus
    I = orice numar natural, se incrementeaza cu 1 dupa fiecare rulare
    Dupa gasirea unui numar par, n se decrementeaza cu 1 pana cand ajunge la 0
    */
    for (unsigned long long i = 1; n > 0; i++) {
        // Verifica daca numarul este par
        if (i % 2 == 0) {
            // Numarul e adaugat la suma
            sum += i;

            // n scade cu 1, semnificand ca trebuie de calculat cu 1 numar mai ptuin
            n--;
        };
    };

    // Afisarea rezultatului final
    cout << "Suma este " << sum << endl;

    return 0;
}