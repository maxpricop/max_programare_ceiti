# LinkedList C++ – Listă simplu înlănțuită

Acesta este un proiect simplu realizat în cadrul unei lecții, care implementează o **listă simplu înlănțuită (singly linked list)** în C++. Proiectul este **modular**, fiind împărțit în mai multe fișiere pentru a menține codul clar și ușor de întreținut.

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/linkedLists/LinkedList.hpp` – Fișierul header care definește clasa `LinkedList` și structura `Node`.
- `src/LinkedList.cpp` – Implementarea funcțiilor clasei `LinkedList`.
- `src/main.cpp` – Program principal pentru interacțiunea cu utilizatorul și testarea listei.

---

## Cerința temei

Scopul acestui proiect a fost să:

1. Creeze o **listă simplu înlănțuită** care poate stoca valori de tip `int`.
2. Permită următoarele operații:
   - Adăugarea unui element la **începutul** listei.
   - Adăugarea unui element la **sfârșitul** listei.
   - Ștergerea unui element după **valoare**.
   - Ștergerea unui element după **poziție**.
   - Afișarea tuturor elementelor listei.
   - Golirea completă a listei.
3. Menținerea unui design modular și ușor de extins.

---

## Funcționalități

- **Modularitate**: Codul este împărțit între fișierul header, implementare și programul principal.
- **Dynamic memory management**: Lista utilizează alocare dinamică (`new` și `delete`) pentru noduri.
- **Siguranță**: Implementarea include verificări pentru poziții invalide sau liste goale.
- **Interactivitate**: `main.cpp` permite utilizatorului să testeze lista printr-un meniu simplu în consolă.
- **Mărimea listei**: Metoda `size()` returnează numărul curent de elemente din listă.
- **Verificare dacă lista este goală**: Metoda `empty()` returnează `true` dacă lista nu conține elemente.

---


## Instrucțiuni de compilare și rulare

Proiectul folosește **CMake** și vine cu **presets** preconfigurate pentru Windows și Linux, în diverse moduri (Debug/Release).

### Configurarea proiectului

Configurează proiectul folosind presetul dorit. Exemple:

- Pentru Windows Clang:
    ```bash
    cmake --preset=clang-win
    ```

- Pentru Linux Clang Debug:
    ```bash
    cmake --preset=clang-linux-debug
    ```

- Pentru Linux Clang Release:
    ```bash
    cmake --preset=clang-linux-release
    ```

### Construirea proiectului

După configurare, construiește proiectul cu presetul de build corespunzător:

- Windows Debug:
    ```bash
    cmake --build --preset=clang-win-debug-build
    ```

- Windows Release:
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

### Rularea aplicației

După ce build-ul s-a terminat cu succes, executabilul va fi generat în folderul `out/build/...` corespunzător presetului ales. De exemplu:

```bash
./out/build/clang-linux-debug/LinkedListApp
```
