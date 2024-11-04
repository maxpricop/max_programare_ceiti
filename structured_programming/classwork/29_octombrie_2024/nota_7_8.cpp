// Nota 7-8: problema 40, 43(a)
#include <iostream>
#include <cmath>

using namespace std;

void problema40() {
    int m, n, p;
    cout << "Introdu numarul m: "; cin >> m;
    cout << "Introdu numarul n: "; cin >> n;
    cout << "Introdu numarul p: "; cin >> p;

    int biggestNumber, middleNumber, smallestNumber;
    if (m > n && m > p) biggestNumber = m;
    else if (n > m && n > p) biggestNumber = n;
    else biggestNumber = p;

    if ((n < m && p < n) || (n < p && m < n)) middleNumber = n;
    else if ((m < n && p < m) || (m < p && n < m)) middleNumber = m;
    else middleNumber = p;

    if (p < m && p < n) smallestNumber = p;
    else if (n < m && n < p) smallestNumber = n;
    else smallestNumber = m;

    bool consecutive = false;
    if (abs(biggestNumber - middleNumber) == 1 && abs(middleNumber - smallestNumber) == 1) consecutive = true;

    consecutive ?
    cout << "Numerele introduse sunt consecutive." << endl :
    cout << "Numerele introduse nu sunt consecutive." << endl;
};

int biggerNumber (int a, int b, int c, int d) {
    int biggestNumber;

    if (a > b && a > c && a > d) biggestNumber = a;
    else if (b > a && b > c && b > d) biggestNumber = b;
    else if (c > a && c > b && c > d) biggestNumber = c;
    else biggestNumber = d;

    return biggestNumber;
};
int smallerNumber (int a, int b, int c, int d) {
    int smallestNumber;

    if (a < b && a < c && a < d) smallestNumber = a;
    else if (b < a && b < c && b < d) smallestNumber = b;
    else if (c < a && c < b && c < d) smallestNumber = c;
    else smallestNumber = d;

    return smallestNumber;
}
void problema43() {
    int a, b, c, d;
    cout << "Introdu numarul a: "; cin >> a;
    cout << "Introdu numarul b: "; cin >> b;
    cout << "Introdu numarul c: "; cin >> c;
    cout << "Introdu numarul d: "; cin >> d;

    int n1 = biggerNumber(a, b, c, d);
    int n4 = smallerNumber(a, b, c, d);
    int n2, n3;

    // Valori din mijloc posibile: AB, AC, AD, BA, BC, BC, CA, CB, CD, DA, DB, DC
    // Valori din mijloc posibile fara duplicates: AB, AC, AD, BC, BD, CD (6 cazuri)

    if ((a != n1 && a != n4) && (b != n1 && b != n4)) {
        // Cand A si B sunt valorile din mijloc
        n2 = (a > b) ? a : b;
        n3 = (a < b) ? a : b;
    } else if ((a != n1 && a != n4) && (c != n1 && c != n4)) {
        // Cand A si C sunt valorile din mijloc
        n2 = (a > c) ? a : c;
        n3 = (a < c) ? a : c;
    } else if ((a != n1 && a != n4) && (d != n1 && d != n4)) {
        // Cand A si D sunt valorile din mijloc
        n2 = (a > d) ? a : d;
        n3 = (a < d) ? a : d;
    } else if ((b != n1 && b != n4) && (c != n1 && c != n4)) {
        // Cand B si C sunt valorile din mijloc
        n2 = (b > c) ? b : c;
        n3 = (b < c) ? b : c;
    } else if ((b != n1 && b != n4) && (d != n1 && d != n4)) {
        // Cand B si D sunt valorile din mijloc
        n2 = (b > d) ? b : d;
        n3 = (b < d) ? b : d;
    } else {
        // Cand C si D sunt valorile din mijloc
        n2 = (c > d) ? c : d;
        n3 = (c < d) ? c : d;
    };

    cout << "Numerele in ordine descrescatoare sunt: " << n1 << ", " << n2 << ", " << n3 << ", " << n4 << endl;
    cout << "Numerele in ordine crescatoare sunt: " << n4 << ", " << n3 << ", " << n2 << ", " << n1 << endl;
};

int main() {
    cout << "\n----- Problema 40 -----" << endl;
    problema40();

    cout << "\n----- Problema 43 -----" << endl;
    problema43();

    return 0;
};