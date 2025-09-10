#include <cmath>
#include <iostream>
using namespace std;

float calcArea(float lat1, float lat2, float lat3, float lat4, float diagonala) {
    // Folosim formula pentru calcularea aria unui triunghi.
    // Folosind diagonala, impartim patrulaterul in 2 triunghiuri,
    // Aflam aria la fiecare triunghi individual si le combinam pentru a afla aria finala;

    float sp1 = (lat1 + lat2 + diagonala) / 2;
    float sp2 = (lat3 + lat4 + diagonala) / 2;

    float area1 = sqrt(sp1 * (sp1 - lat1) * (sp1 - lat2) * (sp1 - diagonala));
    float area2 = sqrt(sp2 * (sp2 - lat3) * (sp2 - lat4) * (sp2 - diagonala));

    return area1 + area2;
};

int main() {
    float latura1, latura2, latura3, latura4, diagonala;

    cout << "Introdu lungimea laturei 1: ";
    cin >> latura1;
    cout << "Introdu lungimea laturei 2: ";
    cin >> latura2;
    cout << "Introdu lungimea laturei 3: ";
    cin >> latura3;
    cout << "Introdu lungimea laturei 4: ";
    cin >> latura4;
    cout << "Introdu lungimea diagonalei: ";
    cin >> diagonala;

    cout << "Aria patrulaterului este: " << calcArea(latura1, latura2, latura3, latura4, diagonala);

    return 0;
}