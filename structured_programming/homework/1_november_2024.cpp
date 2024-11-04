// The homework for 1 november -> 4 november
#include <iostream>

using namespace std;

// The code for the following progression: 1 + 3 + 5 + 7 + ...
void loop1() {
    // The number of how many numbers will be added from the progresion
    int stopNumber = 1;
    cout << "Introdu suma a cator numere vrei sa afli din acest sir: "; cin >> stopNumber;

    // Preventing impossible results
    if (stopNumber < 1) {
        cout << "Numarul introdus trebuie sa fie mai mare sau egal ca 1" << endl;
        return;
    };

    // The final sum that will be displayed when the code finishes
    int sum = 0;
    for (int i = 1; i <= stopNumber; ++i) {
        // The formula for the progression is 2n - 1
        sum += 2 * i - 1;
    };

    // Displaying the final sum
    cout << "Suma a " << stopNumber << " numere din aceasta progresie este: " << sum << endl;
};

// The code for the following progression: 4 * 8 * 12 * ...
void loop2() {
    // The number of how many numbers will be added from the progresion
    int stopNumber = 1;
    cout << "Introdu produsul a cator numere vrei sa afli din acest sir: "; cin >> stopNumber;

    // Preventing impossible results
    if (stopNumber < 1) {
        cout << "Numarul introdus trebuie sa fie mai mare sau egal ca 1" << endl;
        return;
    };

    // The final result that will be displayed when the code finishes
    int product = 1;
    for (int i = 1; i <= stopNumber; ++i) {
        // The formula for the progression is 4n
        product *= 4 * i;
    };

    // Displaying the final result
    cout << "Produsul a " << stopNumber << " numere din aceasta progresie este: " << product << endl;
};

int main() {
    // Executing the first progression
    cout << "\n----- Progresia 1 + 3 + 5 + 7 + ... -----" << endl;
    loop1();

    // Executing the second progression
    cout << "\n----- Progresia 4 * 8 * 12 * ... -----" << endl;
    loop2();

    return 0;
};