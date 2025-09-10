#include <iostream>

using namespace std;

// Sa se afle daca anul introdus este bisect
int main() {
    int an;

    // Introducerea variabilei de catre utilizator
    cout << "Introdu un an: ";
    cin >> an;

    // Anul bisect este odata la 4 ani, cu exceptia anilor ce se impart la 100, cu exceptia la 400 de ani.
    if (an % 4 != 0 || (an % 100 == 0 && an % 400 != 0)) cout << "Anul nu este bisect" << endl;
    else cout << "Anul este bisect" << endl;

    return 0;
}