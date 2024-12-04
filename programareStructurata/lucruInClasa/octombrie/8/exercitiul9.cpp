#include <iostream>

using namespace std;

/*Exercitiul 9 pagina 22 Turbo Pascal Culegere
Se dau numerele intregi n si m.
Sa se verifice daca ele sunt consecutive*/
int main()
{
    // Declararea numerelor n si m
    int m, n;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu numarul m: ";
    cin >> m;
    cout << "Introdu numarul n: ";
    cin >> n;

    // Determinarea si afisarea rezultatului
    (m - n == 1 || m - n == -1)
        ? cout << "Numerele introduse de la tastatura " << m << " si " << n << " sunt consecutive" << endl
        : cout << "Numerele introduse de la tastatura " << m << " si " << n << " nu sunt consecutive" << endl;

    return 0;
}