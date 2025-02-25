#include <iostream>
using namespace std;

union numar {
    float zecimal;
    int intreg;
};

int main() {
    int short optiune;
    numar nr1, nr2;
    cout << "Alege tipul intreg sau float: (1 sau 2): ";
    cin >> optiune;

    switch (optiune) {
        case 1: {
            cout << "Introdu un numar intreg: ";
            cin >> nr1.intreg;

            cout << "Introdu alt numar intreg: ";
            cin >> nr2.intreg;

            cout << "Suma numerelor intregi: " << nr1.intreg + nr2.intreg;
            break;
        }
        case 2: {
            cout << "Introdu un numar real: ";
            cin >> nr1.zecimal;

            cout << "Introdu alt numar real: ";
            cin >> nr2.zecimal;

            cout << "Suma numerelor reale: " << nr1.zecimal + nr2.zecimal;
            break;
        }
        default: {
            cout << "Optiune invalida" << endl;
            break;
        }
    }

    return 0;
}