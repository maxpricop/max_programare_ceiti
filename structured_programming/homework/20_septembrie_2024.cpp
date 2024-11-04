// Homework for 20 september -> 24 september
#include <iostream>
#include <cmath>

using namespace std;

void ex26()
{
    unsigned int a, s;
    float p;

    cout << "Introdu anii (a): "; cin >> a;
    cout << "Introdu Suma de lei (s): "; cin >> s;
    cout << "Introdu dobanda anuala (p): "; cin >> p;

    p /= 100;

    float future_value = s * pow(1 + p, a);
    cout << "Dupa " << a << " cu dobanda anuala de " << p << " vei avea " << future_value << " lei" << endl;
}

void ex28()
{
    int a, b, c, temp;

    cout << "Introdu variabila a: "; cin >> a;
    cout << "Introdu variabila b: "; cin >> b;
    cout << "Introdu variabila c: "; cin >> c;

    temp = a;
    a = b;
    b = c;
    c = temp;

    cout << "Varbila a: " << a << endl;
    cout << "Varbila b: " << b << endl;
    cout << "Varbila c: " << c << endl;
}

void ex30()
{
    float a, b, c, d, temp;

    cout << "Introdu variabila a: "; cin >> a;
    cout << "Introdu variabila b: "; cin >> b;
    cout << "Introdu variabila c: "; cin >> c;
    cout << "Introdu variabila d: "; cin >> d;

    temp = a;

    a = d;
    d = c;
    c = b;
    b = temp;

    cout << "Varbila a: " << a << endl;
    cout << "Varbila b: " << b << endl;
    cout << "Varbila c: " << c << endl;
    cout << "Varbila d: " << d << endl;
}

int main()
{
    cout << "----- Exercitiul 26 -----" << endl;
    ex26();

    cout << "----- Exercitiul 28 -----" << endl;
    ex28();

    cout << "----- Exercitiul 30 -----" << endl;
    ex30();

    return 0;
}
