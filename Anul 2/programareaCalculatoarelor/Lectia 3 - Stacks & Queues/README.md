# Lecția 3 — Stacks & Queues

Acest proiect conține exerciții și implementări simple pentru structurile de date fundamentale: stiva (LIFO) și coada (FIFO). Scopul lecției este înțelegerea operațiilor de bază, a implementărilor statice/dinamice și aplicarea lor în exerciții practice.

---

## Structura proiectului

Fișiere principale observate în directorul lecției:

- `include/`
  - `include/stack/StaticStack.hpp` — header pentru o implementare statică de stivă (array).
  - `include/exercises/Exercises.hpp` — declarații pentru funcțiile exercițiilor (ex1..ex8).
- `src/`
  - `src/main.cpp` — meniu interactiv pentru rularea exercițiilor.
  - `src/StaticStack.cpp` — implementare pentru StaticStack.
  - `src/ex1.cpp`, `src/ex1Static.cpp`, `src/ex2.cpp`, `src/ex3.cpp`, `src/ex4.cpp`, `src/ex5.cpp`, `src/ex6.cpp`, `src/ex7.cpp`, `src/ex8.cpp` — implementări pentru exercițiile din lecție.

---

## Cerința temei

1. Înțelegerea diferenței dintre LIFO și FIFO.
2. Implementarea și utilizarea stivei și cozii:
   - Operații stivă: push, pop, top/peek, isEmpty (dacă este cazul).
   - Operații coadă: enqueue/push, dequeue/pop, front/peek, isEmpty.
3. Compararea unei implementări statice (StaticStack) cu cea din STL (std::stack) și demonstrarea comportamentului prin exerciții.
4. Exercițiile din proiect urmăresc simularea de operații (AD/EL/OUT/PUSH/POP) și afișarea rezultatelor.

---

## Funcționalități observate

- Demonstrarea operațiilor de bază pe stivă și coadă.
- Folosirea containerelor STL (std::stack, std::queue) pentru majoritatea exercițiilor.
- Implementare proprie pentru o stivă statică (dimensiune fixă, mesaje de eroare dacă e plină/golă).

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
./out/build/clang-linux-debug/StackQueue
```
