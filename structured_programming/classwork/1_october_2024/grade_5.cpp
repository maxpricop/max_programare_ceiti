#include <iostream>
#include <cmath>

using namespace std;

void ex7()
{
    int a, b;
    cout << "Introdu nr. 1: "; cin >> a;
    cout << "Introdu nr. 2: "; cin >> b;

    cout << "Suma Numerelor: " << a + b << endl;
    cout << "Diferenta Numerelor: " << a - b << endl;
}

void ex8()
{
    int a, b;
    cout << "Introdu nr. 1: "; cin >> a;
    cout << "Introdu nr. 2: "; cin >> b;

    cout << "Produsul Numerelor: " << a * b << endl;
    cout << "Catul Numerelor: " << a / b << endl;
}

void ex9()
{
    unsigned int a, b;
    cout << "Introdu nr. 1: "; cin >> a;
    cout << "Introdu nr. 2: "; cin >> b;

    cout << "Media Aritmetica: " << (a + b)/2 << endl;
    cout << "Media Geometrica: " << sqrt(a * b) << endl;
}

void ex10()
{
    float latura;
    cout << "Introdu latura patratului: "; cin >> latura;

    cout << "Perimetrul patratului: " << latura * 4 << endl;
    cout << "Aria patratului: " << pow(latura, 2) << endl;
}

void ex11()
{
    float muchie;
    cout << "Introdu muchia cubului: "; cin >> muchie;

    cout << "Aria Totala: " << 6 * pow(muchie, 2) << endl;
    cout << "Volumul patratului: " << pow(muchie, 3) << endl;
}

void ex12()
{
    float raza;
    cout << "Introdu raza cercului: "; cin >> raza;

    cout << "Lungimea Cercului: " << 2 * M_PI * raza << endl;
    cout << "Aria discului: " << M_PI * pow(raza, 2) << endl;
}


void ex13()
{
    float lungimea, raza;
    cout << "Introdu lungimea cercului: "; cin >> lungimea;

    raza = lungimea / 2 * M_PI;
    cout << "Raza Cercului: " << raza << endl;
    cout << "Aria discului: " << M_PI * pow(raza, 2) << endl;
}

int main()
{
    cout << "------Exercitiul 7 ------" << endl;
    ex7();

    cout << "------Exercitiul 8 ------" << endl;
    ex8();

    cout << "------Exercitiul 9 ------" << endl;
    ex9();

    cout << "------Exercitiul 10 ------" << endl;
    ex10();

    cout << "------Exercitiul 11 ------" << endl;
    ex11();

    cout << "------Exercitiul 12 ------" << endl;
    ex12();

    cout << "------Exercitiul 13 ------" << endl;
    ex13();

    return 0;
}