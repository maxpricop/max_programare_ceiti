#include <iostream>
using namespace std;

int main() {
    unsigned n, m;
    cout << "Introdu numarul de linii: ";
    cin >> n;
    cout << "Introdu numarul de coloane: ";
    cin >> m;

    int A[n][m];

    // Input la elementele array-ului de catre utilizator
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Sortarea liniilor in functie de elementul de pe ultima coloana (in ordine descrescatoare) cu selection sort
    for (unsigned linieCurenta = 0; linieCurenta < n - 1; linieCurenta++) {
        unsigned linieMaxima = linieCurenta;

        // Cauta linia cu valoarea maxima pe ultima coloana
        for (int linieUrmatoare = linieCurenta + 1; linieUrmatoare < n; linieUrmatoare++) {
            if (A[linieUrmatoare][m - 1] > A[linieMaxima][m - 1]) linieMaxima = linieUrmatoare;
        }

        // Daca s-a gasit o linie cu un element mai mare pe ultima coloana, se schimba intre ele
        if (linieMaxima != linieCurenta) {
            for (unsigned coloana = 0; coloana < m; coloana++) {
                unsigned temp = A[linieCurenta][coloana];
                A[linieCurenta][coloana] = A[linieMaxima][coloana];
                A[linieMaxima][coloana] = temp;
            }
        }
    }

    // Afisarea array-ului sortat
    cout << "Array-ul sortat:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}