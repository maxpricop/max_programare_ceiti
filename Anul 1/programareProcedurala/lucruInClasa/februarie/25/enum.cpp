#include <cstring>
#include <iostream>
using namespace std;

enum ziSaptamana {
    Luni,
    Marti,
    Miercuri,
    Joi,
    Vineri,
    Sambata,
    Duminica
};

int main() {
    char ziSaptamanaNume[9];
    enum ziSaptamana zi;

    cout << "Introdu ziua saptamanii: ";
    cin.getline(ziSaptamanaNume, 9);

    if (strcmp(ziSaptamanaNume, "luni") == 0) zi = Luni;
    else if (strcmp(ziSaptamanaNume, "marti") == 0) zi = Marti;
    else if (strcmp(ziSaptamanaNume, "miercuri") == 0) zi = Miercuri;
    else if (strcmp(ziSaptamanaNume, "joi") == 0) zi = Joi;
    else if (strcmp(ziSaptamanaNume, "vineri") == 0) zi = Vineri;
    else if (strcmp(ziSaptamanaNume, "sambata") == 0) zi = Sambata;
    else if (strcmp(ziSaptamanaNume, "duminica") == 0) zi = Duminica;
    else {
        cout << "Zi invalida." << endl;
        return 0;
    }

    unsigned short ora, minut;
    switch (zi) {
        case Luni: {
            ora = 14;
            minut = 10;
            break;
        }
        case Marti: {
            ora = 15;
            minut = 40;
            break;
        }
        case Miercuri: {
            ora = 10;
            minut = 50;
            break;
        }
        case Joi: {
            ora = 14;
            minut = 10;
            break;
        }
        case Vineri: {
            ora = 14;
            minut = 10;
            break;
        }
        default: {
            ora = 0;
            minut = 0;
        }
    }

    if (ora == 0 || minut == 0) cout << "Azi nu ai lectii." << endl;
    else cout << "Ai termini lectiile la " << ora << ":" << minut << endl;

    return 0;
}