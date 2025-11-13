# Lectia 8 - Backtracking

Acesta este un proiect realizat în cadrul unei lecții care ilustrează tehnica **backtracking** în C++. Proiectul este **modular**, împărțit în fișiere clare pentru a păstra codul ușor de întreținut. Conține două exerciții care exemplifică două utilizări tipice ale backtracking-ului: generarea tuturor permutărilor cifrelor și generarea cuvintelor respectând o restricție (fără două vocale alăturate).

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/exercises/Exercises.hpp` – Declară funcțiile de exerciții (`ex1()` și `ex2()`).
- `src/ex1.cpp` – Exercițiul 1: generarea tuturor permutărilor numerelor `1..n` (cu cifre unice) și salvarea acestora într-un fișier (`perm.txt`) folosind backtracking (swap + backtrack).
- `src/ex2.cpp` – Exercițiul 2: generarea în ordine lexicografică a tuturor cuvintelor de lungime 4 din alfabetul `{a,b,c,d,e}` fără două vocale alăturate (vocale: `a`, `e`), folosind backtracking poziție-cu-poziție.
- `src/main.cpp` – Programul principal cu un meniu pentru a rula exercițiile sau a ieși din program.

---

## Cerința temei

Scopul acestui proiect a fost să:

1. Demonstrați metoda **backtracking** în două contexte practice:
   - Generare permutări complete (exhaustive) cu salvare în fișier.
   - Generare combinatorică cu constrângeri locale (fără două vocale consecutive).
2. Implementați `ex1()` care:
   - Primește `n` de la utilizator (1 ≤ n ≤ 9).
   - Construiește string-ul inițial `"123...n"`.
   - Generează toate permutările folosind backtracking (swap pentru poziţia curentă) și le scrie în `perm.txt` (fiecare permutare cu elementele separate prin spațiu).
   - Afișează calea completă a fișierului rezultat și numărul de permutări generate.
3. Implementați `ex2()` care:
   - Construiește toate șirurile de lungime 4 din alfabetul `{'a','b','c','d','e'}` în ordine lexicografică.
   - Aplică regula: nu sunt permise două vocale alăturate (`a` și `e` considerate vocale).
   - Afișează fiecare cuvânt generat și totalul acestora la final.
4. Asigurați validarea minimă a intrărilor și comunicarea erorilor (ex: `n` invalid, eroare la deschiderea fișierului).

---

## Funcționalități

- **Backtracking (permutari)**: `ex1()` folosește metoda clasică de generare a permutărilor prin swap + recursie (index curent → permutari ale restului). Toate permutările sunt scrise în fișierul `perm.txt`.
- **Backtracking (constrângeri locale)**: `ex2()` construiește șirurile poziție cu poziție, încercând literele în ordine lexicografică și aplicând regula de restricție înainte de recursie.

---

## Instructiuni de compilare si rulare

Proiectul folosește **CMake** cu **presets** pentru Windows și Linux.

### Configurarea proiectului

Configurează proiectul folosind presetul dorit:

- **Windows Clang:**
    ```bash
    cmake --preset=clang-win
    ```

- **Linux Clang Debug:**
    ```bash
    cmake --preset=clang-linux-debug
    ```

- **Linux Clang Release:**
    ```bash
    cmake --preset=clang-linux-release
    ```

---

### Construirea proiectului

- **Windows Debug:**
    ```bash
    cmake --build --preset=clang-win-debug-build
    ```

- **Windows Release:**
    ```bash
    cmake --build --preset=clang-win-release-build
    ```

- **Linux Debug / Release:**
    ```bash
    cmake --build out/build/clang-linux-debug
    ```
    ```bash
    cmake --build out/build/clang-linux-release
    ```

---

## Rularea aplicației

Executabilul va fi generat în folderul corespunzător presetului:

```bash
./out/build/clang-linux-debug/Backtracking
```
