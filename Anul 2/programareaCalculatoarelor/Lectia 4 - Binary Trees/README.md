# Lecția 4 — Binary Trees

Acest proiect conține o implementare simplă a unui arbore binar de căutare (BST) și un meniu interactiv pentru a testa operațiile de bază: inserare, căutare, ștergere, parcurgeri (preordine, inordine, postordine) și golirea arborelui.

---

## Structura proiectului

Fișiere principale observate în directorul lecției:

- `include/binaryTree/BinaryTree.hpp` — declarațiile clasei `BinaryTree`.
- `src/binaryTree.cpp` — implementarea metodelor pentru BST (inserare, căutare, ștergere, parcurgeri, golire).
- `src/main.cpp` — meniu interactiv pentru testarea funcționalităților.

---

## Cerința temei

1. Implementarea structurii de date Arbore Binar de Căutare (BST) cu operațiile de bază.
2. Parcurgeri iterative: preordine, inordine și postordine (fără recursie pentru acele parcurgeri).
3. Operații auxiliare: `insert`, `search`, `remove`, `clear`.
4. Interfață simplă în `main.cpp` pentru a interacționa cu arborele.

---

## Funcționalități observate

- Inserare de noduri (valorile duplicate sunt inserate în subarborele drept).
- Căutare pentru o valoare dată.
- Ștergere a unei valori (gestionare cazuri: frunză, nod cu un copil, nod cu doi copii — se folosește succesorul in-order).
- Parcurgeri iterative: `preorder`, `inorder`, `postorder` (implementate cu `std::stack`).
- Golirea arborelui (`clear`) implementată iterativ.

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
./out/build/clang-linux-debug/BinaryTrees
```
