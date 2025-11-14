# Lectia 9 - Dynamic Programming

Acesta este un proiect realizat în cadrul unei lecții care ilustrează tehnici de **programare dinamică (Dynamic Programming)** în C++. Proiectul este **modular**, împărțit în mai multe fișiere pentru claritate și ușurință în întreținere. Conține patru exerciții care acoperă probleme clasice rezolvate eficient cu DP.

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/exercises/Exercises.hpp` – Declară funcțiile de exerciții: `ex1()`, `ex2()`, `ex3()`, `ex4()`.
- `src/ex1.cpp` – Generare triunghiul lui Pascal (primele `n` rânduri).
- `src/ex2.cpp` – Climbing Stairs: numărul de moduri de a urca `n` trepte (pași de 1 sau 2).
- `src/ex3.cpp` – Maximum Repeating Substring: determină de câte ori apare consecutiv un `word` în `sequence` (soluție DP).
- `src/ex4.cpp` – Minimum Path Sum in Triangle: suma minimă de la vârf la bază folosind DP bottom-up.
- `src/main.cpp` – Meniul interactiv care permite rularea fiecărui exercițiu sau ieșirea din program.

---

## Cerința temei

1. Implementați o funcție pentru generarea primelor `n` rânduri ale triunghiului lui Pascal; programa trebuie să primească `n` de la utilizator și să afișeze rândurile.
2. Determinați numărul de moduri de a urca `n` trepte când puteți urca 1 sau 2 trepte pe pas (problema Climbing Stairs).
3. Pentru două șiruri (`sequence` și `searchWord`) calculați valoarea maximă `k` astfel încât `searchWord` concatenat `k` ori apare ca substring în `sequence` (implementare DP cu vector `dp`).
4. Dat un triunghi (vector de vectori), calculați suma minimă de la vârf la bază (fiecare pas: jos sau jos-dreapta) folosind o abordare bottom-up.

---

## Funcționalități

- **Modularitate**: Codul este organizat în header și fișiere sursă pentru fiecare exercițiu, ușor de extins și testat.
- **ex1 (Pascal)**: generează rândurile iterative bazate pe rândul precedent; complexitate O(n^2).
- **ex2 (Climbing Stairs)**: implementare cu complexitate O(n) și spațiu O(1) folosind două variabile (rolling).
- **ex3 (Maximum Repeating Substring)**: DP în care `dp[i]` reprezintă numărul consecutiv de apariții ale `searchWord` care se termină la poziția `i`; complexitate O(n * m).
- **ex4 (Triangle Minimum Path Sum)**: DP bottom-up care calculează minimul pe fiecare poziție; complexitate O(N^2).

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
./out/build/clang-linux-debug/DynamicProgramming
```
