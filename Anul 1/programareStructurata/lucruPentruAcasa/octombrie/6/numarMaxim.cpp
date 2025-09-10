#include <iostream>

using namespace std;

// Aflarea celui mai mare nr. dintre 3 numere
int main() {
    // Declararea variabilelor si a celui mai mare nr.
    int a, b, c, biggestNumber;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu a: ";
    cin >> a;
    cout << "Introdu b: ";
    cin >> b;
    cout << "Introdu c: ";
    cin >> c;

    // Aflarea celui mai mare nr. dintre cele 3
    if (a > b && a > c) biggestNumber = a;
    else if (b > a && b > c) biggestNumber = b;
    else biggestNumber = c;

    // Afisarea rezultatlului
    cout << "Cel mai mare numar este: " << biggestNumber << endl;

    return 0;
}