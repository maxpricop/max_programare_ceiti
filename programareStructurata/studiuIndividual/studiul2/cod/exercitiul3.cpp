#include <iostream>

using namespace std;

/*Eu sunt numarul 26 in catalog, fac exercitiul 26
Se consideră şirul de caractere S.
Să se compună un program care transformă literele mici în literele respective mari.*/
int main() {
    // Declararea variabilei ce va avea lungimea s[];
    unsigned lungime;

    // Introduerea lungimii de utilizator
    cout << "Introdu lungimea sirului s[]: ";
    cin >> lungime;

    /*Curatarea bufferului inainte de a citi textul.
    Permite utilizatorului sa scrie deoarece normal textul este acoperit de \n
    si fara el inputul va fi \n, adica 0 text va fi introdus*/
    cin.ignore();

    /*Declararea array-ului de caractere
    E nevoie de lungime + 1 pentru caracterul final null*/
    char s[lungime + 1];

    // Introducerea textului
    cout << "Introdu sirul de caractere: ";

    /*Limitarea textului la lungimea array-ului + 1 pentru elementul null din array.
    Functia get transfroma ultimul element valid in null
    si permite ca utilizatorul sa introduca cu 1 caracter mai putin decat specificat in ea.*/
    cin.get(s, lungime + 1);

    // Iterarea prin fiecare element al s[], cu exceptie ultimul element null de la final
    for (unsigned i = 0; i < lungime; i++) {
        // Transforma literele mici in litere mari
        if (islower(s[i])) s[i] = toupper(s[i]);
    }

    // Afisarea rezultatului final
    cout << "Sirul de caractere dupa schimbare: " << s << endl;

    return 0;
}