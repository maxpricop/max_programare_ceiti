# Doubly Linked List C++ – Listă dublu înlănțuită

Acesta este un proiect realizat în cadrul lecției a doua, care implementează o **listă dublu înlănțuită (doubly linked list)** în C++. Proiectul este **modular**, fiind împărțit în mai multe fișiere pentru claritate și ușurință în întreținere.

---

## Structura proiectului

Proiectul este împărțit în următoarele fișiere:

- `include/linkedLists/LinkedList.hpp` – Fișierul header care definește clasa `LinkedList` și structura `Node`.
- `src/LinkedList.cpp` – Implementarea funcțiilor clasei `LinkedList`.
- `src/main.cpp` – Program principal pentru interacțiunea cu utilizatorul și testarea listei.

---

## Cerința temei

Scopul proiectului:

1. Crearea unei **liste dublu înlănțuite** care stochează valori de tip `int`.
2. Operații disponibile:
   - Adăugarea unui element la **începutul** listei.
   - Adăugarea unui element la o **poziție specificată**.
   - Adăugarea unui element la **sfârșitul** listei.
   - Ștergerea unui element după **valoare**.
   - Ștergerea unui element după **poziție**.
   - Afișarea tuturor elementelor listei.
   - Golirea completă a listei.
3. Menținerea unui design **modular și ușor de extins**.

---

## Funcționalități

- **Modularitate:** Codul este împărțit în header, implementare și program principal.
- **Dynamic memory management:** Nodurile sunt alocate dinamic (`new` / `delete`).
- **Acces optim:** Inserțiile și ștergerile se fac eficient folosind pointeri `next` și `previous`.
- **Siguranță:** Verificări pentru poziții invalide și liste goale.
- **Interactivitate:** `main.cpp` oferă un meniu text simplu.
- **Dimensiunea listei:** Metoda `size()` returnează numărul curent de elemente.
- **Verificarea listei goale:** Metoda `empty()` returnează `true` dacă lista este goală.

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
./out/build/clang-linux-debug/LinkedListApp
```
