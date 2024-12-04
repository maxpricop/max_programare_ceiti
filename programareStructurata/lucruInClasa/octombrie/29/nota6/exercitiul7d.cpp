#include <iostream>

using namespace std;

/*Exercitiul 7 (d) pagina 22 Turbo Pascal Culegere
Se dau numerele reale a si b.
Sa se afiseze a si b daca a este diferit de b.
In caz contrar sa se afiseze doar a.*/
int main() {
    // Declararea variabilelor din conditie
    float a, b;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;

    // Determinarea si afisarea rezultatului
    if (a != b) {
        cout << "Numarul a este: " << a << endl;
        cout << "Numarul b este: " << b << endl;
    } else cout << "Numarul a este: " << a << endl;

    return 0;
}