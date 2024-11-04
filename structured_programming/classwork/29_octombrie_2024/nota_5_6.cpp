// Nota 5-6: problema 6(f) sau 7(d) sau 8(d)
#include <iostream>

using namespace std;

void problema7() {
    int a, b;
    cout << "Introdu numarul a: "; cin >> a;
    cout << "Introdu numarul b: "; cin >> b;

    if (a != b) {
        cout << "Numarul a este: " << a << endl;
        cout << "Numarul b este: " << b << endl;
    } else cout << "Numarul a este: " << a << endl;
};

int main() {
    cout << "\n----- Problema 7 -----" << endl;
    problema7();

    return 0;
};