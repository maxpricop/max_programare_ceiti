// The homework for 5 november -> 12 november
#include <iostream>

using namespace std;

/*
Sarcina:
Sa se calculeze suma primelor N numere intregi pozitive.
N este introdus de la tastatura.
Utilizati o instructiune for.
*/
int main() {
    unsigned n = 1; // Cate numere pare trebuie sa fie calculate
    unsigned long long sum = 0; // Suma a numerelor pare
    cout << "Introdu cate numere pare vrei sa aduni: "; cin >> n;

    // I este orice nr. natural, iar conditia verifica daca mai este nevoie de calculat inca mai multe nr. pare
    for (unsigned long long i = 1; n > 0; i++) {
        // Verifica daca numarul este par
        if (i % 2 == 0) {
            sum += i; // Nr. este adaugat la suma
            n--; // N se scade cu 1, semnificand ca trebuie de calculat cu un nr. mai putin
        };
    };

    cout << "Suma este " << sum << endl;
    return 0;
};