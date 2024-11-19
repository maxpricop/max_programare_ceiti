#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    cout << "Introdu un numar: "; cin >> number;

    int squared = sqrt(number);
    if (squared * squared == number) cout << "Numarul este prim" << endl;
    else cout << "Numarul nu este prim" << endl;
}
// Se verifica daca nr e patrat perfect