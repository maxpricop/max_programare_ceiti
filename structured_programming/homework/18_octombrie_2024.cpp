// Tema pentru acasa 18 octombrie -> 22 octombrie
#include <iostream>
#include <cmath>

using namespace std;

void ziuaSapt(){
    int day;
    cout << "Introdu ziua saptamanii: "; cin >> day;

    switch (day) {
    case 1:
        cout << "Ziua este luni." << endl;
        break;
    case 2:
        cout << "Ziua este marti." << endl;
        break;
    case 3:
        cout << "Ziua este miercuri." << endl;
        break;
    case 4:
        cout << "Ziua este joi." << endl;
        break;
    case 5:
        cout << "Ziua este vineri." << endl;
        break;
    case 6:
        cout << "Ziua este sambata." << endl;
        break;
    case 7:
        cout << "Ziua este duminica." << endl;
        break;
    default:
        cout << "Ziua este invalida." << endl;
        break;
    }
}

void anotimpul(){
    int luna;
    cout << "Introdu luna anului: "; cin >> luna;

    switch (luna){
    case 3:
    case 4:
    case 5:
        cout << "Anotimpul este primavara" << endl;
        break;
    case 6:
    case 7:
    case 8:
        cout << "Anotimpul este vara" << endl;
        break;
    case 9:
    case 10:
    case 11:
        cout << "Anotimpul este toamna" << endl;
        break;
    case 12:
    case 1:
    case 2:
        cout << "Anotimpul este iarna" << endl;
        break;
    default:
        break;
    }
}

int main(){
    cout << "---- Ziua Saptamanii ----" << endl;
    ziuaSapt();

    cout << "---- Anotimpul ----" << endl;
    anotimpul();

    return 0;
}