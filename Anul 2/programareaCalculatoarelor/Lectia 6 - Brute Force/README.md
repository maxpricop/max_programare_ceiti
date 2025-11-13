# Lectia 6 - Brute Force

Acesta este un proiect simplu realizat în cadrul unei lecții, care ilustrează tehnica **brute-force** în C++. Proiectul este **modular**, fiind împărțit în câteva fișiere mici pentru a păstra codul clar și ușor de întreținut. Conține un singur exercițiu (numere prime într-un interval).

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/exercises/Exercises.hpp` – Fișierul header care declară funcțiile de exerciții (`ex1()`).
- `src/ex1.cpp` – Implementarea exercițiului: funcția `isPrime` și logica pentru listarea numerelor prime dintr-un interval.
- `src/main.cpp` – Programul principal cu un mic meniu interactiv care permite rularea exercițiului sau ieșirea din program.

---

## Cerința temei

Scopul acestui proiect a fost să:

1. Implementaţi o funcție `isPrime(long long)` care determină dacă un număr este prim.
2. Citiți de la utilizator un interval `[start, end]` (schimbați valorile dacă sunt introduse invers).
3. Verifică individual dacă fiecare număr este prim.
4. Colectați și afișați toate numerele prime din interval.
5. Tratați cazurile speciale (de ex. capătul intervalului < 2) și asigurați validarea minimă a intrării.

---

## Funcționalități

- **Modularitate**: Codul este împărțit între header și fișierele sursă (`ex1.cpp`, `main.cpp`) pentru claritate și reuzabilitate.
- **Verificare primalitate optimizată**: Funcția `isPrime` folosește verificări pentru 2 și 3, reducând numărul divizorilor încercați.
- **Brute-force aplicat**: Pentru fiecare număr din interval se aplică testul de primalitate (metodă directă, exhaustivă pentru fiecare element din interval).
- **Interactivitate**: `main.cpp` oferă un meniu simplu în consolă (alege exercițiul sau ieşire).
- **Colectare eficientă**: Numerele prime găsite sunt stocate într-un `std::vector<long long>` și afișate la final.
- **Tratări de margine**: Programul face `swap` dacă `start > end` și tratează cazul când nu există numere prime în interval (de ex. `end < 2`).

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
./out/build/clang-linux-debug/BruteForce
```
