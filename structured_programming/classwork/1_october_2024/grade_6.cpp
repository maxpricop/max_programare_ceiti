#include <iostream>
#include <cmath>

using namespace std;

void ex16()
{
    unsigned int n;
    cout << "Introdu nr. n: "; cin >> n;

    cout << "Ultima Cifra: " << n % 10 << endl;
    cout << "Penultimea Cifra: " << (n / 10) % 10 << endl;
    cout << "Catul impartirii la 9: " << n / 9 << endl;
    cout << "Restul impartirii la 9: " << n % 9 << endl;
}

void ex17()
{
    unsigned int n, d;
    
    // n > d
    cout << "Introdu nr. n: "; cin >> n;
    cout << "Introdu nr. d: "; cin >> d;

    cout << "Restul impartirii lui n la d: " << n % d << endl;
    cout << "Catul impartirii lui n la d: " << n / d << endl;
}

void ex20()
{
    float x, y;
    cout << "Introdu nr. x: "; cin >> x;
    cout << "Introdu nr. y: "; cin >> y;

    // x > y
    string bigger = x > y ? "True" : "False";
    cout << "x > y: " << bigger << endl;
}


int main()
{
    cout << "------Exercitiul 16 ------" << endl;
    ex16();

    cout << "------Exercitiul 17 ------" << endl;
    ex17();

    cout << "------Exercitiul 20 ------" << endl;
    ex20();

    return 0;
}