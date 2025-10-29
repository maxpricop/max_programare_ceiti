# Lectia 3 - Lucrare Practica Structuri de control

Acest proiect conține exerciții practice care ilustrează utilizarea structurilor de control (switch, if/else) și a citirii de la tastatură în Java. Scopul este de a exersa ramificarea, manipularea numerelor întregi și reale, precum și separarea logicii în metode distincte.

---

## Structura proiectului

- `src/Main.java` – Program principal cu meniul text și implementarea celor 3 exerciții (plus opțiunea de ieșire).

---

## Ce face programul (pe scurt)

- Afișează un meniu cu 4 opțiuni și citește alegerea utilizatorului (1..4).
- Opțiunile disponibile:
	1. Calcularea bursei în funcție de media notelor.
	2. Afișarea lunilor care au un anumit număr de zile (28/29/30/31).
	3. Determinarea animalului corespunzător unui an în calendarul japonez (ciclu de 12 ani).
	4. Ieșire din program.

---

## Cerințele implementate (detaliat)

### Opțiunea 1 — Calcularea bursei
1. Citește media notelor (float).
2. Verifică validitatea mediei (1..10).
3. Calculează bursa conform regulilor:
	 - dacă media ∈ [5, 7): bursa = 100;
	 - dacă media ∈ [7, 8): bursa = 20 * media;
	 - dacă media ∈ [8, 10): bursa = 25 * media;
	 - dacă media == 10: bursa = 300;
4. Afișează bursa calculată sau un mesaj de eroare dacă media nu este validă.

### Opțiunea 2 — Lunile cu n zile
1. Citește un număr de zile (short): 28, 29, 30 sau 31.
2. Folosește un `switch` pentru a afișa numele lunilor care au acel număr de zile. Pentru alte valori afișează un mesaj corespunzător.

### Opțiunea 3 — Calendar japonez (anii animalelor)
1. Citește anul (int / short).
2. Determină indexul anului în ciclul de 12 ani și mapează indexul la animalul corespunzător (Sobolan, Bou, Tigru, Iepure, Dragon, Sarpe, Cal, Oaie, Maimuta, Cocos, Caine, Porc).
3. Afișează rezultatul într-un mesaj clar.

### Opțiunea 4 — Ieșire
- Închide programul curent și afișează un mesaj de confirmare.

---

## Funcționalități & concepte abordate

- **Structuri de control:** `switch`, `if-else` pentru ramificare.
- **Interactivitate:** citire de la tastatură prin `Scanner`.
- **Modularitate:** fiecare opțiune este implementată într-o metodă separată (`exercise1`, `exercise2`, `exercise3`).
- **Tipuri primare:** folosire de `short`, `int`, `float` și `String`.
