#include "insertionSort.h"

void sorteaza(int *array, int size) {
    for (int *p = array + 1; p < array + size; ++p) {
        int key = *p;
        int *q = p - 1;

        while (q >= array && *q > key) {
            *(q + 1) = *q;
            --q;
        }

        *(q + 1) = key;
    }
};