#include <iostream>
#include <cmath>

using namespace std;

/* Exercise 1
Se da cifre de la 0 pana la 10 (inclusiv 0 si 10)
Sa se afle cate numere pare sunt in acest interval
*/
void cifrePare() {
    // How many even numbers are in an interval
    int evenNumbers = 0;
    for (int i = 0; i <= 10; ++i) {
        // If the number is even, add increase the total even numbers;
        if (i % 2 == 0) evenNumbers++;
    };

    // Displays the result
    cout << "In interval se afla " << evenNumbers << " numere pare." << endl;
};

/* Exercise 2
Se da un nr natural n.
Sa se determine si sa se afiseze la ecran toti divizorii acestui numar
*/
void divizori() {
    // Inputs the numbers
    int n;
    cout << "Introdu un numar: "; cin >> n;

    // Prevents unnatural numbers from being inputted
    if (n <= 0) {
        cout << "Numarul introdus trebuie sa fie mai mare ca 0" << endl;
        return;
    };

    // Sets the divizors to 1 because n always has itself as the divizor
    int divizori = 1;
    // Determines the total number of divizors except for n itself
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) divizori++;
    };

    // Displays the results
    cout << n << " are " << divizori << " divizori" << endl;
};

void problema3() {
    long long f, i, n;
    float s, x, p;

    cin >> n;
    cin >> x;

    for (f = i = s = p = 1; i <=n; i++) {
        f *= i;
        p *= x;
        s *= p / f;
    };

    cout << "Rezultatul este: " << s << endl;
};

void problema4() {
    int n;
    cin >> n;

    double s = 0;
    for (int i = 1; i<=n; i++) {
        s += double(1 / i);
    };

    cout << s << endl;
};

int main() {
    cout << "\nProblema 1" << endl;
    cifrePare();

    cout << "\nProblema 2" << endl;
    divizori();

    cout << "\nProblema 3" << endl;
    problema3();

    cout << "\nProblema 4" << endl;
    problema4();

    return 0;
};