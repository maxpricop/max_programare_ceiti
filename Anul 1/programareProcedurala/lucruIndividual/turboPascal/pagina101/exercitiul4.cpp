/* Exercitiul 4 pagina 101 Turbo Pascal Culegere
Utilizand tipul de date record, sa se realizeze un algoritm pentru calcularea varstei in ani a unei persoane fiind date
- Data nasterii (zila, luna, anul)
- Data curenta (zila, luna, anul)*/
#include <iostream>
using namespace std;

struct date {
    int an;
    unsigned short luna, zi;
};

/**
 * @brief Calculeaza cate zile sunt in luna introdusa
 *
 * Aceasta functie determina cate zile se afla in fiecare luna in baza lunii si a anului introdus.
 *
 * @param luna Numarul lunii (1-12).
 * @param an Anul in care se afla luna.
 * @return Numarul de zile in luna sau 0 daca luna introdusa e invalida.
 */
int zileInLuna(unsigned short luna, int an) {
    switch (luna) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) ? 29 : 28;
        default:
            return 0;
    }
}

int main() {
    date nastere, curenta;

    // Introducerea anului de nastere (Se permit si numere negative pentru anii inainte de hristos, dar fara 0)
    do {
        cout << "Introdu anul de nastere: ";
        cin >> nastere.an;
    } while (nastere.an == 0);

    // Introducerea lunii de nastere (Se permit doar numere intre 1 si 12)
    do {
        cout << "Introdu luna de nastere: ";
        cin >> nastere.luna;
    } while (nastere.luna < 1 || nastere.luna > 12);

    // Introducerea zilei de nastere (Se permit doar numere intre 1 si zilele in luna respectiva)
    do {
        cout << "Introdu ziua de nastere: ";
        cin >> nastere.zi;
    } while (nastere.zi < 1 || nastere.zi > zileInLuna(nastere.luna, nastere.an));

    // Introducerea anului curent (Se permit si numere negative pentru anii inainte de hristos, dar fara 0)
    do {
        cout << "Introdu anul curent: ";
        cin >> curenta.an;
    } while (nastere.an > curenta.an || curenta.an == 0);

    // Introducerea lunii curente (Se permit doar numere intre 1 si 12)
    do {
        cout << "Introdu luna curenta: ";
        cin >> curenta.luna;
    } while (curenta.luna < 1 || curenta.luna > 12 || (curenta.an == nastere.an && nastere.luna > curenta.luna));

    // Introducerea zilei de nastere (Se permit doar numere intre 1 si zilele in luna respectiva)
    do {
        cout << "Introdu ziua curenta: ";
        cin >> curenta.zi;
    } while (curenta.zi < 1 || curenta.zi > zileInLuna(curenta.luna, curenta.an) ||
             (curenta.luna == nastere.luna && nastere.zi > curenta.zi));

    // Calculeaza diferenta intre ani
    int varsta = curenta.an - nastere.an;

    // Ajusteaza pentru diferenta intre inainte de Hristos si Dupa Hristos (nu exista anul 0)
    if (nastere.an < 0 && curenta.an > 0) varsta--;

    // Daca ziua de nastere inca nu a fost atinsa in anul curent
    if (curenta.luna < nastere.luna || (curenta.luna == nastere.luna && curenta.zi < nastere.zi)) varsta--;

    // Afisarea rezultatului
    cout << "Varsta persoanei este de " << varsta << " ani." << endl;
    return 0;
}