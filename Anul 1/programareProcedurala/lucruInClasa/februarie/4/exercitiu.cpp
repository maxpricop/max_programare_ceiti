#include <iostream>
using namespace std;

/* Exercitiul 9
Se consideră tabloul unidimensional A[1..n] cu elemente numere întregi.
Să se compună un program care va transcrie la începutul tabloului  B[1..n]
în ordine descrescătoare elementele lui nenegative, apoi, în continuare,
pe cele negative în ordine crescătoare.

De exemplu, având A = (4, -8, 7, -6, 0, -7, 5), se va obţine B = (7, 5, 4, 0, -8, -7, -6).
*/
int main() {
    unsigned lungimeArray;
    cout << "Introdu lungimea arrayului: ";
    cin >> lungimeArray;

    int A[lungimeArray], B[lungimeArray];
    int pozitive[lungimeArray], negative[lungimeArray];
    unsigned contorPozitive = 0, contorNegative = 0;

    // Citirea array-ului A
    cout << "Introdu elementele arrayului: ";
    for (unsigned i = 0; i < lungimeArray; i++) {
        cin >> A[i];

        // Separăm elementele în două liste
        if (A[i] >= 0) {
            pozitive[contorPozitive++] = A[i];
        } else {
            negative[contorNegative++] = A[i];
        }
    }

    // Sortare manuală pentru numerele nenegative (Bubble Sort Descrescător)
    for (unsigned i = 0; i < contorPozitive - 1; i++) {
        for (unsigned j = 0; j < contorPozitive - i - 1; j++) {
            if (pozitive[j] < pozitive[j + 1]) {
                swap(pozitive[j], pozitive[j + 1]);
            }
        }
    }

    // Sortare manuală pentru numerele negative (Bubble Sort Crescător)
    for (unsigned i = 0; i < contorNegative - 1; i++) {
        for (unsigned j = 0; j < contorNegative - i - 1; j++) {
            if (negative[j] > negative[j + 1]) {
                swap(negative[j], negative[j + 1]);
            }
        }
    }

    // Combinăm listele în B
    unsigned index = 0;
    for (unsigned i = 0; i < contorPozitive; i++) {
        B[index++] = pozitive[i];
    }
    for (unsigned i = 0; i < contorNegative; i++) {
        B[index++] = negative[i];
    }

    // Afisarea array-ului B
    cout << "Array-ul sortat B: ";
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
