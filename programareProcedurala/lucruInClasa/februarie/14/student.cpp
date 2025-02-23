#include <iostream>
#include <string>
using namespace std;

// Creare tipului de student
struct student {
    string nume;
    unsigned short examen1, examen2, bursa;
    float media;
    bool restanta, baiat;
};

int main() {
    unsigned short nrStudenti, nrBaieti = 0;

    // Introducerea numerelor de studenti in clasa de utilizator
    cout << "Introdu numarul de studenti in clasa: ";
    cin >> nrStudenti;

    // Crearea array-ului clasei
    student clasa[nrStudenti];

    // Iterarea prin toate elementele array-ului pentru a introduce elevii
    for (unsigned short i = 0; i < nrStudenti; i++) {
        // Introduerea datelor studentului de catre utilizator
        cout << "Introdu numele studentului: ";
        cin.ignore(); // Ignore characterul de newline scris dupa apasarea enter de la alte cin
        getline(cin, clasa[i].nume);

        cout << "Introdu nota studentului la examenul 1: ";
        cin >> clasa[i].examen1;
        cout << "Introdu nota studentului la examenul 2: ";
        cin >> clasa[i].examen2;
        cin.ignore();

        // Introducerea genului, forteaza utilizatorul sa aleaga din 2 optiuni
        while (true) {
            string gen;
            cout << "Introdu genul stdudentului (baiat/fata): ";
            getline(cin, gen);

            if (gen == "baiat") {
                clasa[i].baiat = true;
                break;
            } else if (gen == "fata") {
                clasa[i].baiat = false;
                break;
            }
        }

        // Calcularea mediei studentului
        clasa[i].media = (clasa[i].examen1 + clasa[i].examen2) / 2;

        // Marirea contorului de baieti daca studentul e baiat
        if (clasa[i].baiat) nrBaieti++;

        // Cazul in care studentul e restantier
        if (clasa[i].examen1 < 5 || clasa[i].examen2 < 5) clasa[i].restanta = true;
        else clasa[i].restanta = false;

        // Determinarea bursei studentului
        if (clasa[i].media < 6 || clasa[i].restanta) clasa[i].bursa = 0;
        else if (clasa[i].media < 7) clasa[i].bursa = 100;
        else clasa[i].bursa = clasa[i].media * 20;
    }

    // Iterarea prin toate elementele array-ului pentru a afisa informatiile despre elevi
    for (unsigned short i = 0; i <= nrStudenti; i++) {
        if (clasa[i].restanta)
            cout << "Studentul " << i << " ( " << clasa[i].nume << " ) " << "este restantier" << endl;
        if (clasa[i].bursa > 0)
            cout << "Studentul " << i << " ( " << clasa[i].nume << " ) " << "are bursa de " << clasa[i].bursa << endl;
    }

    cout << "In clasa se afla " << nrBaieti << " baieti." << endl;
    cout << "In clasa se afla " << nrStudenti - nrBaieti << " fete." << endl;

    return 0;
}