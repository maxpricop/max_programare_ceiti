#include <iostream>

using namespace std;

/*Eu sunt nr. 26 in catalog, fac exercitiul 26.
Se consideră tabloul T[n][m] cu elemente numere întregi.
Să se compună un program care va înlocui în tabloul T elementele lui negative prin elementul maxim.
Tabloul modificat  se va  afişa pe ecran.*/
int main() {
    /*Declararea variabilelor:
    n = nr. de randuri (cate elemente contine array-ul principal)
    m = nr. de coloane (cate elemente contine fiecare array din array-ul principal)*/
    unsigned n, m;

    // Introducerea de randuri si coloane de catre utilizator
    cout << "Introdu nr. de randuri: ";
    cin >> n;
    cout << "Introdu numarul de coloane: ";
    cin >> m;

    // Declararea array-ului si a variabilei ce va contine numarul maxim din array
    int T[n][m], maxNumber;

    // Iterarea prin array-ul principal pentru ca utilizatorul sa le acceseze pe cele secundare
    for (unsigned row = 0; row < n; row++) {
        // Interarea prin fiecare element al fiecarui array secundar
        for (unsigned column = 0; column < m; column++) {
            // Introducerea fiecarui element din array de catre utilizator
            cout << "Introdu T[" << row << "][" << column << "] = ";
            cin >> T[row][column];

            /* Determinarea numarului maxim din array:
            Daca este prima iteratie (introducerea primului nr.) nr. maxim este setat ca el
            Daca este alta iteratie, nr. maxim este setat doar daca noul nr. introdus e mai mare ca cel trecut*/
            if (T[row][column] == T[0][0]) maxNumber = T[0][0];
            else if (T[row][column] > maxNumber) maxNumber = T[row][column];
        };
    };

    // Text pentru a arata mai frumos
    cout << endl << "Afisarea array-ului:" << endl;

    // Iterarea prin array-ul principal pentru a afisa elementele la ecran
    for (unsigned row = 0; row < n; row++) {
        // Interarea prin fiecare element al fiecarui array secundar
        for (unsigned column = 0; column < m; column++) {
            // Setarea numerelor negative ca si numarul maxim din array (din conditie)
            if (T[row][column] < 0) T[row][column] = maxNumber;

            // Afisarea fiecarui numar la ecran
            cout << T[row][column] << "\t";
        };
        // Rescrie fiecare array iterat pe o linie noua
        cout << endl;
    };

    return 0;
}