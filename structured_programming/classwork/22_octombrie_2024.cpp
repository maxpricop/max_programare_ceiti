#include <iostream>
#include <cmath>

using namespace std;

void operatii(){
    char operatie;
    cout << "Introdu o operatie: "; cin >> operatie;

    int x, y;
    cout << "Introdu primul nr: "; cin >> x;
    cout << "Introdu al doilea nr: "; cin >> y;

    switch (operatie) {
        case '*': x*= y; break;
        case '/': x/= y; break;
        case '+': x+= y; break;
        case '-': x-= y; break;
        default: cout << "Operatia este invalida."; return;
    };

    cout << "Rezultatul este: " << x << endl;
};

void lunaAn() {
    int luna, an;
    cout << "Introdu luna: "; cin >> luna;
    cout << "Introdu anul: "; cin >> an;

    bool anBisect;
    if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) anBisect = true;
    else anBisect = false;

    string lunaResponse;
    switch (luna) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: lunaResponse = "Luna are 31 de zile"; break;
        case 4:
        case 6:
        case 9:
        case 11: lunaResponse = "Luna are 30 de zile"; break;
        case 2: anBisect ? lunaResponse = "Luna are 29 de zile" : lunaResponse = "Luna are 28 de zile"; break;
        default: lunaResponse = "Luna introdusa este invalida";
    }

    anBisect ? cout << "Anul este bisect" << endl : cout << "Anul nu este bisect" << endl;
    cout << lunaResponse << endl;
};

void tringhi(){
    int a, b, c;
    cout << "Introdu primul nr: "; cin >> a;
    cout << "Introdu al doilea nr: "; cin >> b;
    cout << "Introdu al treilea nr: "; cin >> c;

    if (a + b + c != 180) {
        cout << "Nu se poate crea un triughi din aceste numere";
        return;
    };

    if (a == b == c) cout << "Triunghiul este echilateral";
    else if (a == b || a == c || b == c) cout << "Triunghiul este isoscel";
    else cout << "Triunghiul este scalen";
};

void litera(){
    char litera;
    cout << "Introdu o litera: "; cin >> litera;

    switch (litera) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': cout << "Litera este o vocala"; break;
        default: cout << "Litera este o consoana";
    };
};

int main(){
    cout << "--- Operatii ----" << endl;
    operatii();

    cout << "---- Luna si an ----" << endl;
    lunaAn();

    cout << "---- Tringhiu ----" << endl;
    tringhi();

    cout << "---- Litera ----" << endl;
    litera();

    return 0;
};