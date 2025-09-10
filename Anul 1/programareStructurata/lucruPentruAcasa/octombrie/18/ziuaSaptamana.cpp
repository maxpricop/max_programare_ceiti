#include <iostream>

using namespace std;

// Sa se afli ziua saptamanii in baza nr. zilei
int main() {
    // Declararea variabilei zilei
    unsigned zi;

    // Introducerea numarului de catre utilizator
    cout << "Introdu ziua saptamanii: ";
    cin >> zi;

    // Determinarea zilei in baza numarului si afisarea rezultatului
    switch (zi) {
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
        cout << "Ziua introdusa nu exista." << endl;
        break;
    }

    return 0;
}