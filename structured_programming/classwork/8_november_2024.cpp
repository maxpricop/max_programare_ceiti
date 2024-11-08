#include <iostream>

using namespace std;

int main() {
    // n = nr introdus, i = nr interatiei, counter = cate numere pozitive
    unsigned n, i = 0, counter = 0;
    cout << "Cate numere vrei sa introduci: "; cin >> n;

    float m, sum = 0;
    while (i < n) {
        cout << "Introdu un numar: "; cin >> m;
        i++;
        if (m > 0) {
            sum += m;
            counter++;
        };
    };

    if (counter) cout << "Media aritmetica este: " << sum / counter << endl;
    else cout << "Media aritmetica nu poate fi calculata." << endl;
};