#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file;
    int numar1, numar2, numar3;

    file.open("test.txt", ios::in);
    file >> numar1 >> numar2 >> numar3;
    file.close();

    file.open("test.txt", ios::app);
    file << endl << "Suma numerelor: " << numar1 + numar2 + numar3 << endl;
    file << "Produsul numerelor: " << numar1 * numar2 * numar3;
    file.close();

    return 0;
}