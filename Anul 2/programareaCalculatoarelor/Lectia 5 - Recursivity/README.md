# Lectia 5 - Recursivity

Acest proiect conține exerciții practice care ilustrează utilizarea recursivității în probleme clasice: Tower of Hanoi, descompunerea în factori primi și verificarea unui palindrom. Scopul este exersarea definirea funcțiilor recursive, alegerea unei condiții de oprire potrivite și înțelegerea complexității recurente.

---

## Structura proiectului

Fișiere principale observate în directorul lecției:

- `include/exercises/Exercises.hpp` — declarațiile funcțiilor exercițiilor (`towerOfHanoi`, `primeFactors`, `palindromeCheck`).
- `src/towerOfHanoi.cpp` — implementarea soluției recursive pentru Tower of Hanoi (afișează mutările).
- `src/primeFactors.cpp` — funcție recursivă care afișează factorii primi ai unui număr.
- `src/palindromeCheck.cpp` — verificare recursivă a unui palindrom.
- `src/main.cpp` — meniu interactiv care permite rularea fiecărui exercițiu.

---

## Cerința temei

1. Implementarea algoritmilor recursivi corespunzători fiecărui exercițiu.
2. Definirea clară a cazului de bază și a cazului recursiv pentru fiecare problemă.
3. Interfață simplă pentru testare prin `main.cpp`.

---

## Funcționalități observate

- Tower of Hanoi: afișează pașii pentru mutarea `n` discuri între stâlpi.
- Factori primi: funcție recursivă care împarte repetat numărul la cel mai mic divizor prim găsit și afișează factorii.
- Verificare palindrom: funcție recursivă care compară caracterele de la capete spre centru.
- Meniu interactiv pentru alegerea exercițiului și introducerea datelor.

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
./out/build/clang-linux-debug/Recursivity
```
