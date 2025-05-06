#include "insertionSort.cpp"
#include <iostream>
using namespace std;

int main() {
    int test[3][10] = {
        {3, 8, 9, 1, 0, 23, 7, 3, 2, 5}, {1, 4, 2, 7, 3, 9, 6, 10, 69, 96}, {3, 2, 8, 9, 5, 6, 10, 1, 4, 7}};

    sorteaza(test[0], 10);
    sorteaza(test[1], 10);
    sorteaza(test[2], 10);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << test[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}