#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Introdu numarul de elemente din array: ";
    cin >> n;

    int A[n];
    int indexValoareMin = 0;

    // Input la elementele array-ului de catre utilizator
    for (int i = 0; i < n; i++) {
        cout << "Elementul " << i << ": ";
        cin >> A[i];

        // Stocarea indexului cu elementul minim din array. Mai mic sau egal pentru a stoca ultima lui aparinta in array
        if (A[i] <= A[indexValoareMin]) indexValoareMin = i;
    }

    // Sortarea partii 1 (de la A[0] pana la A[indexValoareaMin]) in ordine descrescatoare cu insertion sort
    for (int indexCurent = 1; indexCurent <= indexValoareMin; indexCurent++) {
        int elementCurent = A[indexCurent];
        int indexInserare = indexCurent - 1;

        while (indexInserare >= 0 && A[indexInserare] < elementCurent) {
            A[indexInserare + 1] = A[indexInserare];

            indexInserare--;
        }
        A[indexInserare + 1] = elementCurent;
    }

    // Sortarea partii 2 (de la A[indexValoareaMin] pana la finalul array-ului) in ordine crescatoare cu insertion sort
    for (int indexCurent = indexValoareMin + 1; indexCurent < n; indexCurent++) {
        int elementCurent = A[indexCurent];
        int indexInserare = indexCurent - 1;

        while (indexInserare >= indexValoareMin && A[indexInserare] > elementCurent) {
            A[indexInserare + 1] = A[indexInserare];

            indexInserare--;
        }
        A[indexInserare + 1] = elementCurent;
    }

    // Afisarea array-ului sortat
    cout << "Array-ul sortat:";
    for (int i = 0; i < n; i++) {
        cout << " " << A[i];
    }

    return 0;
}
