# Studiul Individual 2 – Ghicire a unui număr ascuns (C++)

Acesta este **Studiul Individual nr. 2**, o implementare simplă, în C++, a unui joc în care un jucător (calculatorul/programul) se "gândește" la un număr natural x în intervalul [1, n], iar celălalt încearcă să-l ghicească punând întrebări la care se răspunde doar cu "Da" sau "Nu".

---

## Structura proiectului

Studiul individual conține doar 1 fișier:

- `src/main.cpp` – implementarea programului care simulează jocul de ghicire.

---

## Cerințele temei

Parafrazare clară a cerinței:

- Implementați un program care simulează un joc de ghicire a unui număr natural x din intervalul [1, n]. Un jucător "se gândește" la număr, iar celălalt pune întrebări la care se răspunde cu "Da" sau "Nu". Întrebările permise sunt:
  - "Numărul este egal cu ... ?"
  - "Numărul este mai mare decât ... ?"
  - "Numărul este mai mic decât ... ?"
- Programul trebuie să genereze (sau să rețină) un număr ascuns în intervalul [1, n] și să permită interacțiunea până când numărul este ghicit sau utilizatorul se predă.

---

## Funcționalități

- Generare aleatorie a numărului ascuns între `1` și `n`.
- Meniu interactiv pentru întrebările permise: egal, mai mare, mai mic, sau opțiunea de a se preda.
- Validare robustă a intrărilor (opțiuni invalide, date ne-numerice) cu mesaje clare și cerere de reîncercare.
- Răspunsuri explicite "Da" / "Nu" pentru întrebările despre relația dintre numărul ascuns și valoarea introdusă.

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
