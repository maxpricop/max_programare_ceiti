#include <cmath>
#include <iostream>
using namespace std;

/* Conditie
La paradă participă N militari.
Comandanții de paradă au decis că cea mai eficientă aliniere a militarilor este sub forma unui pătrat,
adică numărul de participanți la aliniere trebuie să fie un pătrat perfect.
Dar, deoarece numărul N poate să nu fie un pătrat perfect, este permisă divizarea militarilor în mai multe regimente,
fiecare dintre ele fiind reprezentat în formă de pătrat.
Pentru frumusețe, toate regimentele ar trebui să aibă aceeași dimensiune (același număr de militari),
iar сomandanții de paradă mai doresс ca fiecare  regiment să fie cât mai mare posibil.
Determinați dimensiunea maximă posibilă a regimentului.

Date de intrare. De la tastatură se citește numărul întreg pozitiv N – numărul participanților la paradă.
Date de ieşire. La ecran se va afișa numărul natural М– dimensiunea maximă posibilă a regimentului.
Restricţii: 1 ≤ N ≤ 2×10^9*/
int main() {
    unsigned N, M; // Declararea variabilelor din conditie
    cin >> N;      // Introducerea numarului de soldati din conditie

    // Previne introducerea numarului care sunt inafara restrictiiei din conditie
    // Nu previn de introducerea a textului deoarace in conditie se zice ca sa introduce un numar natural
    while (N < 1 || N > 2 * 1000000000) {
        cout << "Numarul trebuie sa fie intre 1 si 2 * 10^9. Reintrodu numarul din nou: ";

        cin.clear(); // Previne erori cauzate de numere introduse ce sunt mai mari ca limita tipului unsigned in bytes
        cin >> N;    // Reintroducerea numarului
    }

    // Iterarea de la cel mai mare patrat (radical din N) in jos pana la 1.
    for (unsigned i = sqrt(N); i >= 1; i--) {
        unsigned patratPerfect = i * i; // Calcularea numarului original (patratul perfect)

        // Determinarea daca patratul perfect este un divizor al numarului introdus
        if (N % patratPerfect == 0) {
            M = patratPerfect; // Setarea lui M ca si patratul perfect
            break;             // Oprirea totala a iteratiilor
        }
    }

    // Afisarea rezultatului
    cout << M << endl;
    return 0;
}