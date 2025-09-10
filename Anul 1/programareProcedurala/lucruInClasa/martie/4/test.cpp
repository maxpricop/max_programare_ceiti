#include <fstream>

int main() {
    std::ofstream file("1.txt");

    char litera = 'Z';
    for (short unsigned i = 0; i < 26; i++, litera--) {
        file << litera << " ";
    }
    file.close();

    return 0;
}