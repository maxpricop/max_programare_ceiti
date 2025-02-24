/* Exercitiul 5 pagina 101 Turbo Pascal Culegere
Se introduce de la tastatura data calendaristica curenta (ziua, luna) si denumirea unei zile a saptamanii.
Sa se calculeze cate zile cu aceasta denumire au fost de la inceputul anului curent pana in ziua curenta.*/
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    bool anBisect = false;
    int zileLuni[12] = {31, anBisect ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned short zi, luna;
    char ziSaptamanaNume[9];

    // Introducerea lunii de utilizator (Previne luni invalide)
    do {
        cout << "Introdu luna: ";
        cin >> luna;
    } while (luna < 1 || luna > 12);

    // Introducerea zilei de utilizator (Previne zile invalide)
    do {
        cout << "Introdu ziua: ";
        cin >> zi;
    } while (zi < 1 || zi > zileLuni[luna - 1]);

    // Introducerea zilei saptamanii de utilizator (Previne zile invalide)
    unsigned short ziSaptamana = 7;
    do {
        cout << "Introdu ziua saptamanii: ";
        cin.ignore(); // Ignore characterul de newline scris dupa apasarea enter de la alte cin
        cin.getline(ziSaptamanaNume, 9);

        if (strcmp(ziSaptamanaNume, "luni") == 0) ziSaptamana = 0;
        else if (strcmp(ziSaptamanaNume, "marti") == 0) ziSaptamana = 1;
        else if (strcmp(ziSaptamanaNume, "miercuri") == 0) ziSaptamana = 2;
        else if (strcmp(ziSaptamanaNume, "joi") == 0) ziSaptamana = 3;
        else if (strcmp(ziSaptamanaNume, "vineri") == 0) ziSaptamana = 4;
        else if (strcmp(ziSaptamanaNume, "sambata") == 0) ziSaptamana = 5;
        else if (strcmp(ziSaptamanaNume, "duminica") == 0) ziSaptamana = 6;
    } while (ziSaptamana > 6);

    // Calcularea zilelor totale in an
    unsigned short zileTotale = 0;
    for (unsigned short i = 1; i < luna; i++) {
        zileTotale += zileLuni[i - 1];
    }
    zileTotale += zi;

    // Setarea primei zile sa fie luni, si creearea contorului pentru a numara ziua dorita
    unsigned short primaZi = 2, contorZile = 0;
    for (unsigned short i = 1; i <= zileTotale; i++) {
        unsigned short ziuaSaptamanii = (primaZi + (i - 1)) % 7;
        if (ziuaSaptamanii == ziSaptamana) contorZile++;
    }

    // Afisarea rezultatului
    cout << "Ziua de " << ziSaptamanaNume << " a avut loc de " << contorZile << " ori." << endl;
    return 0;
}