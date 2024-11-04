#include <iostream>
#include <cmath>

using namespace std;

void biggerNumber(){
    int a, b;
    cout << "Introdu nr. 1: "; cin >> a;
    cout << "Introdu nr. 2: "; cin >> b;

    if (a > b) {
        cout << "Nr. a este mai mare ca b" << endl;
    } else {
        cout << "Nr. b este mai mare ca a" << endl;
    }
}

void parImpar(){
    int a;
    cout << "Introdu un nr.: "; cin >> a;

    if (a % 2 == 0) {
        cout << "Nr. este par" << endl;
    } else {
        cout << "Nr. este impar" << endl;
    }
}

void gradul1(){
    float a, b, x;
    cout << "Introdu a: "; cin >> a;
    cout << "Introdu b: "; cin >> b;

    if (a != 0) {
        x = -b / a;
        cout << "X este egal cu: " << x << endl;
    } else {
        cout << "A este 0, nu e posibila rezolvarea ecuatiei" << endl;
    }
}

void gradul2(){
    float a, b, c;
    cout << "Introdu a: "; cin >> a;
    cout << "Introdu b: "; cin >> b;
    cout << "Introdu c: "; cin >> c;

    float delta = pow(b, 2) - 4 * a * c;

    if (a != 0){
        if (delta <= 0) {
            cout << "Delta e mai mic ca 0, nu e posibila rezolvarea ecuatiei cu numere reale." << endl;
        } else {
            if (delta == 0) {
                cout << "Ecuatia are o solutie, x = " << -b / 2 * a << endl;
            } else {
                cout << "Ecuatia are 2 solutii." << endl;
                cout << "X1 = " << (-b + sqrt(delta)) / 2 * a << endl;
                cout << "X2 = " << (-b - sqrt(delta)) / 2 * a << endl;
            }
        }
    } else {
        cout << "A este 0, nu e posibila rezolvarea ecuatiei" << endl;
    }
}

int main(){
    cout << "---- Cel mai mare numar din 2 numere ----" << endl;;
    biggerNumber();

    cout << "---- Numarul este par/impar ----" << endl;;
    parImpar();

    cout << "---- Ecuatie de gradul 1 (ax + b = 0) ----" << endl;;
    gradul1();

    cout << "---- Ecuatie de gradul 2 (ax^2 + bx + c = 0) ----" << endl;;
    gradul2();

    return 0;
}