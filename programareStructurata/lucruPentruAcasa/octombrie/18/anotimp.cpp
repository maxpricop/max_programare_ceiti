#include <iostream>

using namespace std;

// Sa se determine in ce anotimp se afla luna in baza numarului ei.
int main()
{
    // Declararea variabilei lunii
    unsigned luna;

    // Introducerea numarului lunei de catre utilizator
    cout << "Introdu luna anului: ";
    cin >> luna;

    // Determinarea anotimpului si afisarea rezultatului
    switch (luna)
    {
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
        cout << "Luna introdusa nu exista." << endl;
        break;
    }

    return 0;
}