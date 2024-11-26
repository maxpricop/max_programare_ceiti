#include <iostream>

using namespace std;

/*
Se da un array simplu cu n elemente care se introduc de la tastatura.
1. Sa se afle elementul maxim.
2. Suma elementelor.
3. Sa se numere de cate ori se repeta elementul maxim
*/
int main() {
    // n - nr. de elemente din array, maxCount - de cate ori este prezent nr. maxim
    unsigned n, sum = 0, maxCount = 0; 
    // Storeaza cel mai mare nr. din array
    int max = 0;

    // Alege cate elemente sa fie in array
    cout << "Introdu cate elemente vrei sa fie in array: "; cin >> n;
    int inputArray[n]; // Creaza arrayul

    // Loop ca sa mearga prin fiecare pozitie a arrayului
    for (int i = 0; i < n; i++) {
        // Introdu fiecare numar la fiecare pozitie de la tastatura
        cout << "Pozitia " << i << " = "; cin >> inputArray[i];

        // Mareste suma cu numarul nou
        sum+= inputArray[i];

        // Verifica daca un numar maxim este introdus decat numarul maxim trecut
        if (inputArray[i] > max) {
            max = inputArray[i];
            maxCount = 1;
        }
        // Daca este introdus un alt numar maxim din nou, se mareste countul
        else if (inputArray[i] == max) maxCount++;
    };

    cout << "Suma numerelor este: " << sum << endl;
    cout << "Numarul maxim din array este: " << max << endl;
    cout << "Numarul " << max << " apare de " << maxCount << " ori" << endl;

    // cout << "\n Elementele arrayului:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << "inputNumbers[" << i << "] = " << inputNumbers[i] << endl;
    // };

    return 0;
};