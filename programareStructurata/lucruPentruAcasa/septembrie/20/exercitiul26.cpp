#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 26 pagina 15 Turbo Pascal Culegere
Se dau nr. naturale a, p, s
Sa se afle cu cat va creste in timp de a ani suma de s lei depusa la o banca,
daca dobanda anuala este de p procente*/
int main()
{
    // Declararea variabilelor din conditie
    unsigned int a, s;
    float p;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu anii (a): ";
    cin >> a;
    cout << "Introdu Suma de lei (s): ";
    cin >> s;
    cout << "Introdu dobanda anuala (p): ";
    cin >> p;

    // Transformarea procentului in nr. cu virgula
    p /= 100;

    // Calcularea si afisarea valoarea viitoare a banilor
    float valoarea_viitoare = s * pow(1 + p, a);
    cout << "Dupa " << a << " cu dobanda anuala de " << p << " vei avea " << valoarea_viitoare << " lei" << endl;

    return 0;
}