#include <iostream>

using namespace std;

// Eu sunt nr. 26 in catalog, fac exercitiul 26.
int main() {
    /* Declararea Variabilelor:
    n = numarul de numere fibonaci ce trebuie sa fie aratate
    i = variabila pentru a stoca numarul iteratiei in diferite bucle*/
    unsigned n = 1, i = 1;

    // Introducerea variabilei n de catre utilizator
    cout << "Introdu cate numere Fibonacci vrei sa fie calculate: ";
    cin >> n;

    /*Declararea Variabilelor:
    nextNumber = numarul fibonaci calculat
    displayNumber = primul numar fibonacci (numarul mai mic)
    otherNumber = al doilea numar fibonacci (numarul mai mare)*/
    unsigned long long nextNumber = 0, displayNumber = 0, otherNumber = 1;

    // Secventa fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
    // Metoda 1 - For Loop
    for (i; i < n; i++) {
        nextNumber = displayNumber + otherNumber;

        displayNumber = otherNumber;
        otherNumber = nextNumber;
    };

    // Metoda 2 - While Loop
    // while (i < n)
    // {
    //     i++;
    //     nextNumber = displayNumber + otherNumber;

    //     displayNumber = otherNumber;
    //     otherNumber = nextNumber;
    // };

    // Metoda 3 - Do While Loop
    // do
    // {
    //     i++;
    //     if (i == 2) continue;

    //     nextNumber = displayNumber + otherNumber;

    //     displayNumber = otherNumber;
    //     otherNumber = nextNumber;
    // } while (i <= n);

    // Afisarea ultimului numar fibonaci calculat
    cout << "Nr. " << n << " din secventa Fibonacci este " << displayNumber << endl;

    return 0;
}