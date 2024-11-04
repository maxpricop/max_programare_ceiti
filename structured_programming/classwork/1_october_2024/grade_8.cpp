#include <iostream>
#include <cmath>

using namespace std;

void ex24()
{
    unsigned int n;
    cout << "Introdu nr. n: "; cin >> n;

    // N zile
    float oreZ = n * 24;
    float minuteZ = oreZ * 60;
    float secundeZ = minuteZ * 60;
    cout << "Ore in n zile: " << oreZ << endl;
    cout << "Minute in n zile: " << minuteZ << endl;
    cout << "Secunde in n zile: " << secundeZ << endl;

    // N saptamani
    float zileS = n * 7;
    float oreS = zileS * 24;
    float minuteS = oreZ * 60;
    float secundeS = minuteZ * 60;
    cout << "Ore in n saptamani: " << oreS << endl;
    cout << "Minute in n saptamani: " << minuteS << endl;
    cout << "Secunde in n saptamani: " << secundeS << endl;

    // Luna mai
    unsigned int days = 31;
    float oreM = days * 24;
    float minuteM = oreZ * 60;
    float secundeM = minuteZ * 60;
    cout << "Ore in luna mai: " << oreM << endl;
    cout << "Minute in luna mai: " << minuteM << endl;
    cout << "Secunde in luna mai: " << secundeM << endl;
}

void ex25()
{
    unsigned int n;
    
    // n > d
    cout << "Introdu nr. n: "; cin >> n;

    cout << "n metri in cm: " << n * 100 << endl;
    cout << "n kg in miligrame: " << n * 1000000 << endl;
    cout << "tone in n kg: " << n / 1000 << endl;

    int months = n * 12;
    int weeks = n * 52;
    int days = n * 365;
    cout << "luni in n ani: " << months << endl;
    cout << "saptamani in n ani: " << weeks << endl;
    cout << "zile in n ani: " << days << endl;
}

void ex27()
{
    int a, b, temp;

    cout << "Introdu nr. a: "; cin >> a;
    cout << "Introdu nr. b: "; cin >> b;

    temp = a;
    a = b;
    b = temp;

    cout << "a dupa schimbare: " << a << endl;
    cout << "b dupa schimbare: " << b << endl;
}


int main()
{
    cout << "------Exercitiul 24 ------" << endl;
    ex24();

    cout << "------Exercitiul 25 ------" << endl;
    ex25();

    cout << "------Exercitiul 27 ------" << endl;
    ex27();

    return 0;
}