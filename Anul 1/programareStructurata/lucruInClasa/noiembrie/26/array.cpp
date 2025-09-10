#include <iostream>

using namespace std;

/*Se da un array simplu cu n elemente care se introduc de la tastatura.
1. Sa se afle elementul maxim.
2. Suma elementelor.
3. Sa se numere de cate ori se repeta elementul maxim*/
int main() {
    /*Declararea variabilelor
    n = nr. de elemente din array
    sum = suma numerelor din array
    contorMax = de cate ori este prezent numarul maxim din array
    */
    unsigned n, sum = 0, contorMax = 0;

    // Declararea numarului maxim
    int max;

    // Introducerea numerelor din array de utilizator
    cout << "Introdu cate elemente vrei sa fie in array: ";
    cin >> n;

    // Declara array-ul
    int inputArray[n];

    // Itereaza prin fiecare pozitie a array-ului
    for (int i = 0; i < n; i++) {
        // Introdu fiecare numar la fiecare pozitie de la tastatura
        cout << "Pozitia " << i << " = ";
        cin >> inputArray[i];

        // Mareste suma cu numarul nou
        sum += inputArray[i];

        // Daca este prima rulare a array-ului, numarul maxim este primul numar
        if (i == 0) max = inputArray[0];
        // Verifica daca un numar maxim este introdus decat numarul maxim trecut
        if (inputArray[i] > max) {
            // Se reseteaza numarul maxim si contorul de numar maxim
            max = inputArray[i];
            contorMax = 1;
        }
        // Daca este introdus un alt numar maxim din nou, se mareste countul
        else if (inputArray[i] == max)
            contorMax++;
    };

    // Afisarea rezultatelor
    cout << "Suma numerelor este: " << sum << endl;
    cout << "Numarul maxim din array este: " << max << endl;
    cout << "Numarul " << max << " apare de " << contorMax << " ori" << endl;

    return 0;
};