#include <iostream>

using namespace std;

// Produsul progresiei aritmetice: 4 * 8 * 12 * ...
int main() {
    /*Declararea variabilelor
    nrStop = Cate numere din progresie o sa fie calculate
    produs = Produsul nr. calculate din progresie*/
    unsigned nrStop, produs = 0;

    // Introducerea numarului de catre utilizator
    cout << "Introdu produsul a cator numere vrei sa afli din acest sir: ";
    cin >> nrStop;

    // Iterarea prin fiecare numar al progresiei
    for (int i = 1; i <= nrStop; ++i) {
        // Calcularea produslui in baza formulei: 4n
        produs *= 4 * i;
    };

    // Afisarea rezultatului final
    cout << "Produsul a " << nrStop << " numere din aceasta progresie este: " << produs << endl;

    return 0;
}