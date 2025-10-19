# Studiul Individual 1 – Liste Circulare (C++)

Acesta este **Studiul Individual nr. 1**, realizat pentru a exersa lucrul cu **liste circulare dublu înlănțuite** în C++. Proiectul este simplu și modular — conține implementarea listei și un program principal cu meniu pentru interacțiune.

---

## Structura proiectului

Fișiere incluse în acest proiect:

- `include/linkedLists/CircularLinkedList.hpp` – header-ul care definește clasa `CircularDoublyLinkedList` și structura internă `Node`.
- `src/CircularLinkedList.cpp` – implementarea metodelor clasei (`push`, `pop`, `removeAll`, `countElementsWithEqualNeighbors`, `clear`, etc.).
- `src/main.cpp` – programul principal cu un meniu text pentru a testa funcționalitățile listei.

---

## Cerințele temei

PImplementarea unei **liste circulare** cu elemente de tip `int` și un program care permite:

- Adăugarea unui element la o poziție dată.
- Ștergerea unui element de la o poziție dată.
- Ștergerea tuturor elementelor cu o anumită valoare.
- Contorizarea elementelor care au **vecinii egali** (criteriu: cele două valori ale vecinilor sunt egale).
- Golirea listei (ștergerea tuturor nodurilor).
- Afișarea conținutului listei și a numărului de elemente.

---

## Funcționalități

- **Listă circulară dublu înlănțuită**:
  - Fiecare nod are `next` și `prev`.
  - `tail` pointează către ultimul nod; `tail->next` este `head`.
- **Operații suportate**:
  - `push(int value, std::size_t position)` – Inserează `value` la indexul `position` (0..size). Returnează `true` dacă inserarea reușește.
  - `pop(std::size_t position)` – Șterge nodul de la index `position`. Returnează `true` dacă ștergerea reușește.
  - `removeAll(int value)` – Șterge toate nodurile cu valoarea dată și returnează numărul de noduri șterse.
  - `countElementsWithEqualNeighbors()` – Numără nodurile ale căror vecini (prev și next) au aceeași valoare între ei.
  - `clear()` – Șterge întreaga listă.
- **Complexitate**:
  - Inserare/ștergere la poziție arbitrară: O(n) în cel mai rău caz (traversare); inserare la cap/coadă poate fi O(1).
  - Operații pe valori (ex. `removeAll`) sunt O(n).

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
./out/build/clang-linux-debug/StudiuIndividual
```
