#include <iostream>
using namespace std;

/* Conditie
În țara Minunilor, vulpea Alice și pisoiul Basilio au făcut rost de arborele de Jad (așa numitul arborele banilor).
În momentul răpirii copacul a rodit monede de 3-euro și 5-euro.
Vulpea a împărțit monedele în felul următor: sie și-a luat monede în valoare de 3-euro, iar motanului i s-a revenit
monedele de 5-euro. Fiind ”modestă” vulpea a propus ca fiecare cumpărătură să fie achitată împreună astfel încît: suma
să fie achitată fără rest și cu numărul minim de monede. Se cunoaște că ei au făcut cumpărărturi în valorea de N euro,
și s-au achitat fără rest. Scrieți un program care va determina:
cu câte monede a contribuit motanul și cu câte monede a contribuit vulpea pentru a achita cumparatura.

Date de intrare:
De la tastatură se citește un număr natural N, ce reprezintă suma spre achitare în euro. (7 < N < 1000).

Date de ieșire:
La ecran se va afișa două numere întregi separate prin spațiu, ce reprezintă
numărul de monede contribuite de motanul Basilio și numărul de monede contribuite de vulpea Alice. */
int main() {
    // Declararea variabilelor cu numarul de monede tinute de vulpe si pisoi si suma ce trebuie platita
    unsigned monede3, monede5, suma;

    cout << "Introdu suma ce vrei sa fie platita: ";
    cin >> suma;

    // Previne introducerea numerelor care nu sunt intre 7 si 1000 (din conditie)
    while (suma < 7 || suma >= 1000) {
        cout << "Suma trebuie sa fie intre 7 si 1000. Introdu valoarea din nou: ";
        cin >> suma;
    }

    // Itereaza prin toate posibilitatile de numere a monedelor de 5 euro. Incepe cu cea mai mare valoarea posibila
    for (monede5 = suma / 5; monede5 >= 0; monede5--) {
        unsigned sumaRamas = suma - monede5 * 5;

        // Daca suma ramasa dupa achiatarea cu monede de 5 euro este divizibila cu 3, atunci raspunsul este gasit
        if (sumaRamas % 3 == 0) {
            monede3 = sumaRamas / 3;
            break;
        }
    }

    // Afisarea rezultatului
    cout << monede5 << " " << monede3 << endl;
    return 0;
}