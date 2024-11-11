#include <iostream>
#include <cmath>

using namespace std;

// Nr. 26
void program1() {
    float lungime, latime;
    cout << "Introdu lungimea dreptunghiului: "; cin >> lungime;
    cout << "Introdu latimea dreptunghiului: "; cin >> latime;

    // Converteste numerele negative in pozitive pentru a preveni rezultate imposibile
    lungime = abs(lungime);
    latime = abs(latime);

    float perimetru = 2 * (lungime + latime);
    float aria = lungime * latime;

    cout << "Perimetrul dreptunghiului este: " << perimetru << endl;
    cout << "Aria dreptunghiului este: " << aria << endl;
};

// Nr. 26 => problema 9
void program2() {
    float x, y;
    cout << "Introdu numarul: "; cin >> x;

    if (x < -4) y = x + 2 * pow(x, 2) + 6;
    else if (-4 <= x && x <= 4) y = (2 * x * (pow(x, 2) + 1)) / (x + 1);
    else y = 2 * pow(x, 3) + (x - 11) - 7 * pow(x, 2);

    cout << "Rezultatul este: " << y << endl;
};

// Problema 26
void program3() {
    unsigned n = 1, i = 1;
    cout << "Introdu cate numere Fibonacci vrei sa fie calculate: "; cin >> n;

    unsigned long long nextNumber = 0, displayNumber = 0, otherNumber = 1;
    
    // Secventa fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
    // Metoda 1 - For Loop
    for (i; i < n; i++) {
        nextNumber = displayNumber + otherNumber;

        displayNumber = otherNumber;
        otherNumber = nextNumber;
    };

    // Metoda 2 - While Loop
    // while (i < n) {
    //     i++;
    //     nextNumber = displayNumber + otherNumber;

    //     displayNumber = otherNumber;
    //     otherNumber = nextNumber;
    // };

    // Metoda 3 - Do While Loop
    // do {
    //     i++;
    //     if (i == 2) continue;

    //     nextNumber = displayNumber + otherNumber;

    //     displayNumber = otherNumber;
    //     otherNumber = nextNumber;
    // } while (i <= n);

    cout << "Nr. " << n << " din secventa Fibonacci este " << displayNumber << endl;
};

int main(){
    cout << "---- Program nr. 1 ----" << endl;
    program1();

    cout << "---- Program nr. 2 ----" << endl;
    program2();

    cout << "---- Program nr. 3 ----" << endl;
    program3();

    return 0;
};