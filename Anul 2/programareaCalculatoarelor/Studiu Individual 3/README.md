# Studiul Individual 3 – Algoritmul lui Dijkstra

Acest proiect implementează algoritmul lui Dijkstra pentru determinarea costului minim al drumurilor într-un graf orientat ponderat, pornind de la un nod sursă specificat.

---

## Structura proiectului

Studiul individual conține doar 1 fișier:

- `src/main.cpp` – implementarea programului.

---

## Cerința problemei

Se dă un graf orientat ponderat – în care fiecare arc are asociat un cost, număr natural strict pozitiv, și un nod p. Să se determine, folosind algoritmul lui Dijkstra, costul minim al drumului de la p la fiecare nod al grafului.

---

## Funcționalități

- **Citire robustă a intrării**: programul citește numărul de noduri, muchii și nodul sursă, apoi muchiile (origine, destinație, greutate).
- **Dijkstra eficient**: implementare cu coadă de priorități (`std::priority_queue` cu comparator inversat) și vector de distanțe inițializate cu `INF`.
- **Validare noduri**: muchiile către noduri în afara intervalului sunt ignorate pentru a evita accesări invalide.
- **Ieșire clară**: pentru fiecare nod se afișează distanța minimă sau `-1` dacă nodul nu este accesibil.

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
