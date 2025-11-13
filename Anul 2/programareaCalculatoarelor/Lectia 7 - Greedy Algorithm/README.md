# Lectia 7 - Greedy Algorithm

Acesta este un proiect mic realizat în cadrul unei lecții, care ilustrează tehnica **greedy (algoritm lacom)** în C++. Proiectul este **modular**, împărțit în fișiere simple pentru claritate. Conține un singur exercițiu: returnarea unei sume cu un set fix de bancnote folosind o strategie greedy (ales cele mai mari bancnote posibile pe rând).

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/exercises/Exercises.hpp` – Fișierul header care declară funcțiile de exerciții (`ex1()`).
- `src/ex1.cpp` – Implementarea exercițiului: logica pentru distribuirea unei sume în bancnote folosind metoda greedy (vector de perechi `{valoare, numar}`).
- `src/main.cpp` – Programul principal cu un mic meniu interactiv care permite rularea exercițiului sau ieșirea din program.

---

## Cerința temei

Scopul acestui proiect a fost să:

1. Implementați o funcție `ex1()` care citește o sumă de la utilizator.
2. Folosiți o listă de bancnote ordonată descrescător (`100, 50, 20, 10, 5, 2`) și, pentru fiecare bancnotă, calculați câte bucăți sunt necesare (operând `amount / valoare`) și actualizați restul (`amount %= valoare`).
3. Dacă după procesarea tuturor denominațiilor rămâne un rest nenul, afișați un mesaj că suma nu poate fi returnată exact cu bancnotele disponibile.
4. Dacă suma poate fi returnată exact, afișați numărul de bancnote pentru fiecare denominație.

---

## Funcționalități

- **Modularitate**: Codul este organizat în header și două fișiere sursă (`ex1.cpp`, `main.cpp`) pentru ușurință în întreținere și testare.
- **Algoritm greedy**: Pentru fiecare bancnotă (în ordinea descrescătoare a valorii) se alocă cât mai multe bucăți posibile — aceasta e esenţa strategiei lacome.
- **Detectare imposibilitate**: Deoarece setul de bancnote nu conține bancnote de 1 (cel mai mic este 2), programul verifică dacă rămâne rest; dacă da, raportează că nu se poate returna suma exactă.
- **Validare intrare**: `main.cpp` tratează input-ul nevalid și previne blocarea programului.
- **Complexitate**: Timp O(d), unde d e numărul de denominații (aici 6) — practic constant, foarte eficient.

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
./out/build/clang-linux-debug/Greedy
```
