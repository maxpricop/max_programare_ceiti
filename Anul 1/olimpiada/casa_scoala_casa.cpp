#include <iostream>
#include <string>
using namespace std;

/* Conditie
Un elev merge cu metroul în fiecare zi, traseul său fiind:
dimineața: de acasă – la școală;
iar seara: de la școală – acasă.

Pentru a economisi bani, își cumpără un card electronic pentru X călătorii.
Când vrea să se deplaseze cu metroul, își pune cardul pe turnichet.
Dacă pe card există un număr, diferit de zero, de călătorii atunci
turnichetul îl lasă pe elev să treacă și se anulează o călătorie de pe card.
Dacă nu mai sunt călătorii pe card, atunci turnichetul nu-l lasă pe elev să treacă și
el este obligat să cumpere un card nou pentru X călătorii la aceeași stație și să treacă din nou prin turnichet.
Elevul a observat că dimineața, din cauza supraaglomerării, el nu-și poate permite să cumpere un card nou,
deoarece va întârzia la lecții.
În condițiile date elevul ar dori să cunoască: va fi așa dimineață când el nu-și va putea achita călătoria?

Date de intrare:
De la tastatură se citește cuvântul «School» sau «Home»
în dependență de unde și-a procurat prima dată elevul cardul pentru X călătorii,
apoi din rândul următor se citește un număr natural X, 1 ≤ X ≤ 1000.
Date de ieșire:
La ecran se va afișa «Yes», dacă va sosi astfel de zi:
dimineața de acasă pe cardul elevului nu vor mai fi bani pentru achitarea călătoriei,
în caz contrar se va afișa «No».*/
int main() {
    string locatie;     // Declararea variabilei introduse de utilizator cu locatia de unde a fost cumparat cardul
    unsigned calatorii; // Declararea variabilei cu cu cate calatorii ramase are cardul

    // Introducerea informatiilor din conditie
    cin >> locatie;
    cin >> calatorii;

    // Converteste locatia introdusa asa incat sa fie tot cuvantul scris cu litere mici
    for (unsigned i = 0; i <= 6; i++) {
        locatie[i] = tolower(locatie[i]);
    }

    // Determinarea daca calatoriile se vor termina intr-o dimineata si afisarea rezultatului
    if (calatorii % 2 == 0) cout << "No" << endl;      //  Daca numarul de calatorii e par, tot timpul vor fi destule
    else if (locatie == "home") cout << "Yes" << endl; // Daca nr. e impar si incepe de acasa, se termina
    else cout << "No" << endl; // Daca nr. e impar si incepe de la scoala, vor fi tot timpul destule

    return 0;
}