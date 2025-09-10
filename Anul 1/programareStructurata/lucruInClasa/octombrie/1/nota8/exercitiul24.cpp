#include <iostream>

using namespace std;

/*Exercitiul 24 pagina 15 Turbo Pascal Culegere
Se da numarul natural n.
Sa se calculeze cate ore, minute, secunde sunt in:
n zile, n saptamani si luna mai*/
int main() {
    // Declararea numarului n
    unsigned n;

    // Introducerea lui n de utilizator
    cout << "Introdu nr. n: ";
    cin >> n;

    // N zile
    float oreZ = n * 24;
    float minuteZ = oreZ * 60;
    float secundeZ = minuteZ * 60;
    cout << "Ore in n zile: " << oreZ << endl;
    cout << "Minute in n zile: " << minuteZ << endl;
    cout << "Secunde in n zile: " << secundeZ << endl;

    // N saptamani
    float zileS = n * 7;
    float oreS = zileS * 24;
    float minuteS = oreZ * 60;
    float secundeS = minuteZ * 60;
    cout << "Ore in n saptamani: " << oreS << endl;
    cout << "Minute in n saptamani: " << minuteS << endl;
    cout << "Secunde in n saptamani: " << secundeS << endl;

    // Luna mai
    unsigned zileMai = 31;
    float oreM = zileMai * 24;
    float minuteM = oreZ * 60;
    float secundeM = minuteZ * 60;
    cout << "Ore in luna mai: " << oreM << endl;
    cout << "Minute in luna mai: " << minuteM << endl;
    cout << "Secunde in luna mai: " << secundeM << endl;

    return 0;
}