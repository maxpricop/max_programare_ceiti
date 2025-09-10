#include <iostream>

using namespace std;

// Rezolvarea unei ecuatii de gradul 1 (ax + b = 0)
int main() {
    // Declararea numerelor din ecuatie (a si b)
    float a, b;
    cout << "Introdu a: ";
    cin >> a;
    cout << "Introdu b: ";
    cin >> b;

    if (a != 0) cout << "X este egal cu: " << -b / a << endl;
    else cout << "A este 0, nu e posibila rezolvarea ecuatiei" << endl;

    return 0;
}