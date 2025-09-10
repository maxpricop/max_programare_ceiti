/* Exercitiul 3 pagina 101 Turbo Pascal Culegere
Se dau 3 date calendaristice, reprezentand zilele de nastere a 3 prieteni.
Sa se afiseze numele celui mai in varsta*/
#include <iostream>
using namespace std;

struct persoana {
    char nume[30];
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
    unsigned lungime, mareIndex = 0;
    cout << "Introdu numarul de persoane pe care le vei compara: ";
    cin >> lungime;

    persoana persoane[lungime];
    for (unsigned i = 0; i < lungime; i++) {
        cout << "Introdu numele persoanei " << i << " (Max 30 caractere): ";
        cin.ignore(); // Ignore characterul de newline scris dupa apasarea enter de la alte cin
        cin.getline(persoane[i].nume, 30);

        // Introducerea anului de nastere (Se permit si numere negative pentru anii inainte de hristos, dar fara 0)
        do {
            cout << "Introdu anul de nastere a persoanei " << i << ": ";
            cin >> persoane[i].an;
        } while (persoane[i].an == 0);

        // Introducerea lunii de nastere (Se permit doar numere intre 1 si 12)
        do {
            cout << "Introdu luna de nastere a persoanei " << i << ": ";
            cin >> persoane[i].luna;
        } while (persoane[i].luna < 1 || persoane[i].luna > 12);

        // Introducerea zilei de nastere (Se permit doar numere intre 1 si zilele in luna respectiva)
        do {
            cout << "Introdu ziua de nastere a persoanei " << i << ": ";
            cin >> persoane[i].zi;
        } while (persoane[i].zi < 1 || persoane[i].zi > zileInLuna(persoane[i].luna, persoane[i].an));

        // Determinarea celei mai mari persoane
        if (persoane[i].an > persoane[mareIndex].an) continue;
        else if (persoane[i].an == persoane[mareIndex].an) {
            if (persoane[i].luna > persoane[mareIndex].luna) continue;
            else if (persoane[i].luna == persoane[mareIndex].luna) {
                if (persoane[i].zi > persoane[mareIndex].zi) continue;
            }
        }
        mareIndex = i;
    }

    // Afisarea rezultatului
    cout << "Cea mai mare persoana este: " << persoane[mareIndex].nume << endl;
    return 0;
}