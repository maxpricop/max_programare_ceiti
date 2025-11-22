# Lectia 10 - Graphs

Acesta este un proiect realizat în cadrul unei lecții care ilustrează concepte de bază despre **grafuri** în C++. Proiectul conține un program simplu bazat pe matricea de adiacență care citește un graf și determină nodurile izolate.

---

## Structura proiectului

Proiectul este minimalist și conține următoarele fișiere relevante:

- `src/main.cpp` – Citire a matricei de adiacență, afișare antet și determinare a nodurilor izolate.

---

## Cerința lecției

1. Reprezentați un graf folosind o matrice de adiacență (dimensiune n x n, unde `n` e numărul de noduri).
2. Citiți elementele matricei de la tastatură.
3. Determinați și afișați nodurile izolate (noduri fără muchii incidente, toate elementele liniei = 0).

---

## Funcționalități

- **Input:** primește de la utilizator numărul de noduri și matricea de adiacență.
- **Detectare noduri izolate:** parcurge fiecare linie a matricei și afișează nodurile care au toate valorile egale cu 0.
- **Afișare opțională:** codul conține (comentat) un bloc pentru afișarea completă a matricei de adiacență pentru verificare.

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
./out/build/clang-linux-debug/Graph
```
