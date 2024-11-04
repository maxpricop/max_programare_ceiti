// Tema pentru acasa 6 octombrie -> 10 octombrie
#include <iostream>
#include <cmath>

using namespace std;

void monede(){
    int s, monede3, monede5;

    cout << "Introdu suma de bani: "; cin >> s;
    switch (s % 3){
        case 0: {
            monede3 = s / 3;
            monede5 = 0;

            break;
        }
        case 1: {
            monede3 = s / 3 - 3;
            monede5 = 2;

            break;
        }
        case 2: {
            monede3 = s / 3 - 1;
            monede5 = 1;

            break;
        }
    }

    if (s % 3 == 0) {
        monede3 = s / 3;
        monede5 = 0;
    } else if (s % 3 == 1) {
        monede3 = s / 3 - 3;
        monede5 = 2;
    } else {
        monede3 = s / 3 - 1;
        monede5 = 1;
    }

    if (monede3 < 0) {
        cout << "Nu se poate plati cu monede de 3 sau 5.";
    } else {
        cout << "Suma poate fi platita cu urmatoarele monezi:" << endl;
        cout << "Monede de 3: " << monede3 << endl;
        cout << "Monede de 5: " << monede5 << endl;
    }
}

void biggestNumber(){
    int a, b, c, biggestNumber;

    cout << "Introdu a: "; cin >> a;
    cout << "Introdu b: "; cin >> b;
    cout << "Introdu c: "; cin >> c;

    if (a > b && a > c) biggestNumber = a;
    else if (b > a && b > c) biggestNumber = b;
    else biggestNumber = c;

    cout << "Cel mai mare numar este: " << biggestNumber << endl;
}

void leapYear(){
    int year;
    cout << "Introdu un an: "; cin >> year;

    string response = "Anul este bisect";
    if (year % 4 != 0) response = "Anul nu este bisect";
    if (year % 100 == 0 && year % 400 == 0) response = "Anul nu este bisect";

    cout << response << endl;
}

int main(){
    cout << "---- Monede ----" << endl;;
    monede();

    cout << "---- Cel mai mare nr. ----" << endl;;
    biggestNumber();

    cout << "---- An bisect ----" << endl;
    leapYear();

    return 0;
}