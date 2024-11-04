#include <iostream>
#include <cmath>

using namespace std;

void ex9(){
    int m, n;
    cout << "Introdu numarul m: "; cin >> m;
    cout << "Introdu numarul n: "; cin >> n;

    string consecutive = (m - n == 1 || m - n == -1) ? "Numerele sunt consecutive" : "Numerele nu sunt consecutive"; 
    cout << consecutive << endl;
}

void ex10(){
    unsigned int a, b, c;
    cout << "Introdu numarul a: "; cin >> a;
    cout << "Introdu numarul b: "; cin >> b;
    cout << "Introdu numarul c: "; cin >> c;

    int biggestNumber = (
        (a > b && a > c) ? a : 
        (b > a && b > c) ? b : 
        c
    );

    int middleNumber = (
        ((a < b && b < c) || (c < b && b < a)) ? b : 
        ((b < a && a < c) || (c < a && a < b)) ? a : 
        c
    );

    int smallestNumber = (
        (a < b && a < c) ? a : 
        (b < a && b < c) ? b : 
        c
    );
    
    cout << "Numbarul mijlociul este " << middleNumber << endl;

    int arithmeticDifference = middleNumber - smallestNumber;
    string arithmeticProgression = (middleNumber + arithmeticDifference == biggestNumber) ? "Este progresie aritmetica" : "Nu este progresie aritmetica";
    cout << arithmeticProgression << endl;
}

void ex13(){
    unsigned int a, b;
    // A > B - Zice in conditie

    string divisibil = (b % a == 0) ? "B divide A" : "B nu divided A";
    cout << divisibil << endl;
}

void ex14a(){
    float a, b;
    cout << "Introdu numarul a: "; cin >> a;
    cout << "Introdu numarul b: "; cin >> b;

    // ecuatia ax + b = 0
    float x = -1 * (a / b);
    cout << "Solutia ecuatiei de gradul 1: " << x << endl;
}

void ex14b(){
    float a, b, c;
    cout << "Introdu numarul a: "; cin >> a;
    cout << "Introdu numarul b: "; cin >> b;
    cout << "Introdu numarul c: "; cin >> c;

    // ecuatia ax^2 + bx + c = 0
    float delta = pow(b, 2) - 4 * a * c;
    bool solveable = (delta >= 0) ? true : false;

    (solveable) ? 
        (delta = 0) ? cout << "Ecuatia are doar o solutie: " << (-1 * b) / (2 * a) << endl : 
        cout << "Ecuatia are 2 solutii: " << ((-1 * b) + sqrt(delta)) / (2 * a) << ", " << ((-1 * b) - sqrt(delta)) / (2 * a) << endl
    : cout << "Ecuatia nu are solutii" << endl;
}

int main()
{
    cout << "------Exercitiul 9 ------" << endl;
    ex9();
    
    cout << "------Exercitiul 10 ------" << endl;
    ex10();

    cout << "------Exercitiul 13 ------" << endl;
    ex13();

    cout << "------Exercitiul 14 A ------" << endl;
    ex14a();

    cout << "------Exercitiul 14 B ------" << endl;
    ex14b();

    return 0;
}