#include <iostream>

using namespace std;

// Suma progresiei aritmetice: 1 + 3 + 5 + 7 + ...
int main()
{
    /*Declararea variabilelor
    nrStop = Cate numere din progresie o sa fie calculate
    suma = Suma nr. calculate din progresie*/
    unsigned nrStop, suma = 0;

    // Introducerea numarului de catre utilizator
    cout << "Introdu suma a cator numere vrei sa afli din acest sir: ";
    cin >> nrStop;

    // Iterarea prin fiecare numar al progresiei
    for (int i = 1; i <= nrStop; ++i)
    {
        // Calcularea sumei in baza formulei progresiei: 2n - 1
        suma += 2 * i - 1;
    };

    // Afisarea rezultatului final
    cout << "Suma a " << nrStop << " numere din aceasta progresie este: " << suma << endl;

    return 0;
}