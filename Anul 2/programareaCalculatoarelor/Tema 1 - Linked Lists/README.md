# Tema 1 – Liste simplu înlănțuite (C++)

Acesta este un proiect realizat ca **temă de casă** pentru a exersa lucrul cu **liste simplu înlănțuite (singly linked lists)** în C++.
Proiectul este **modular**, fiind împărțit în mai multe fișiere pentru claritate și ușurință în întreținere.

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/linkedLists/LinkedList.hpp` – Fișierul header care definește clasa `LinkedList` și structura `Node`.
- `include/exercises/Exercises.hpp` – Header auxiliar pentru legarea implementărilor exercițiilor.
- `src/LinkedList.cpp` – Implementarea funcțiilor clasei `LinkedList`.
- `src/ex14.cpp` – Implementarea cerinței din **exercițiul 14**.
- `src/ex15.cpp` – Implementarea cerinței din **exercițiul 15**.
- `src/ex16.cpp` – Implementarea cerinței din **exercițiul 16**.
- `src/main.cpp` – Program principal cu un **meniu** din care utilizatorul poate alege ce exercițiu să ruleze.

---

## Cerințele temei

Proiectul implementează următoarele exerciții:

### Exercițiul 14
1. Citirea de la tastatură a unui șir de numere întregi până la întâlnirea unei valori **negative**.
2. Crearea unei liste unidirecționale cu numerele citite.
3. Operații:
   - Afișarea listei create.
   - Afișarea elementelor impare.
   - Contorizarea divizorilor numărului 25 din listă.
   - Ștergerea elementelor ce conțin valoarea `17`.

---

### Exercițiul 15
1. Citirea de la tastatură a unui șir de numere întregi până la întâlnirea valorii **10**.
2. Crearea unei liste liniare cu numerele citite.
3. Operații:
   - Afișarea listei create.
   - Contorizarea elementelor divizibile cu 5.
   - Afișarea elementelor **nenegative**.
   - Ștergerea nodurilor cu informația `13`.

---

### Exercițiul 16
1. Citirea de la tastatură a unei secvențe de numere întregi până la întâlnirea valorii **0**.
2. Crearea unei liste liniare cu numerele citite.
3. Operații:
   - Afișarea multipliilor lui 7.
   - Găsirea elementului minim din listă.
   - Contorizarea elementelor **negative**.
   - Ștergerea nodurilor cu informația `5`.

---

## Funcționalități

- **Modularitate:** Fiecare exercițiu este implementat într-un fișier separat, iar logica listei este concentrată într-un modul dedicat.
- **Dynamic memory management:** Nodurile sunt gestionate dinamic folosind `new` și `delete`.
- **Interactivitate:** `main.cpp` oferă un **meniu text** pentru a selecta ce exercițiu să ruleze.

---

## Instrucțiuni de compilare și rulare

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

### Rularea aplicației

Executabilul va fi generat în folderul corespunzător presetului:

```bash
./out/build/clang-linux-debug/Tema1
```
