# Pregatire Examen

Acestea sunt o colecție de probleme pe care ni le-a dat profesorul ca să ne pregătim pentru examenul de programare. Proiectul conține exerciții scrise în C++ care acoperă tehnici precum backtracking, sortări, greedy și altele.

---

## Structura proiectului

- `include/exercises/Exercises.hpp` – declarațiile funcțiilor `ex1()`..`ex5()`.
- `src/` – cod sursă pentru exerciții și `main.cpp` care oferă un meniu interactiv:
  - `ex1.cpp` – backtracking (generare cuvinte fără vocale alăturate)
  - `ex2.cpp` – produsul maxim pentru un sub‑multime de elemente
  - `ex3.cpp` – număr maxim de mașini reparate într‑un interval T (greedy)
  - `ex4.cpp` – selecția maximă de spectacole (interval scheduling, greedy)
  - `ex5.cpp` – generare drapele tricolore (backtracking + stivă)

---

## Ce face fiecare exercițiu (sumar)

- `ex1()` — generează, prin backtracking, toate cuvintele de lungime 4 din alfabetul {a,b,c,d,e} care nu conțin două vocale consecutive.
- `ex2()` — citește un șir de numere și alege un sub‑multime de elemente cu produs maxim (gestionează cazuri cu zero și negative).
- `ex3()` — citește timpii de reparare ai mașinilor și, pentru un interval total `T`, calculează câte mașini pot fi reparate (sort + greedy).
- `ex4()` — citește intervale (HH:MM) pentru spectacole și alege maximal non‑suprapuse (ordine după final).
- `ex5()` — generează toate drapelele tricolore valide folosind backtracking și o stivă ca structură centrală.

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
./out/build/clang-linux-debug/PregatireExamen
```
