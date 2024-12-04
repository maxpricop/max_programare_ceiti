#include <iostream>

using namespace std;

/*Exercitiul 10 pagina 14 Turbo Pascal Culegere
Calcularea ariei si perimetrului unui patrat*/
int main()
{
    // Declararea variabilei ce contine latura patratului
    int latura;

    // Introducerea laturei patratului de catre utilizator
    cout << "Introdu latura patratului: ";
    cin >> latura;

    // Calcularea si afisarea rezultatelor
    cout << "Perimetrul patratului: " << latura * 4 << endl;
    cout << "Aria patratului: " << latura * latura << endl;

    return 0;
}