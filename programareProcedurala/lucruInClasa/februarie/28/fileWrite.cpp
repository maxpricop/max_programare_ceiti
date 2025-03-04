#include <fstream>

int main() {
    std::fstream file;
    int numar1, numar2, numar3;

    file.open("fileWrite.txt", std::ios::in);
    file >> numar1 >> numar2 >> numar3;
    file.close();

    file.open("fileWrite.txt", std::ios::app);
    file << "\nSuma numerelor: " << numar1 + numar2 + numar3;
    file << "\nProdusul numerelor: " << numar1 * numar2 * numar3;
    file.close();

    return 0;
}