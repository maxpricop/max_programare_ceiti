# Lectia 2 - Structuri de control

Acest proiect este o continuare practică a lecțiilor introductive de Java. Scopul este exersarea citirii de la tastatură, a operării cu valori reale (`double`) și a scrierii de funcții generice de **min** / **max**. Programul oferă un meniu text care rulează patru exerciții diferite (cu 2, 3 numere, funcții matematice și verificarea numerelor consecutive).

---

## Structura proiectului

- `src/Main.java` – Program principal cu meniul text, implementarea exercițiilor și funcțiile `min`/`max`.

---

## Ce face programul (pe scurt)

- Afișează un meniu și citește opțiunea utilizatorului (1..4).
- `Exercitiul 1` — primește două numere și afișează expresii care folosesc `min` și `max` pentru 2 argumente.
- `Exercitiul 2` — primește trei numere și afișează expresii care folosesc `min` și `max` pentru 3 argumente (include și o expresie suplimentară bazată pe diferențele dintre numere).
- `Exercitiul 3` — evaluează mai multe funcții matematice definite pe bucăți (comportament condiționat în funcție de `x`).
- `Exercitiul 4` — verifică dacă două numere întregi sunt consecutive (în oricare ordine).
- `min` și `max` sunt implementate cu `double... numbers` și verifică existența cel puțin a unui argument (aruncă `IllegalArgumentException` dacă nu există).

---

## Cerințele implementate (detaliat)

### Exercițiul 1
1. Citirea a două numere reale (`double`).
2. Calculul și afișarea:
   - `max(a, b)`;
   - `min(a, b)`;
   - `max(a, b) + min(a, b)`;
   - `max(a - b, b)`;
   - `min(a + b, b)`;
   - `max(2a, 3b)`.

### Exercițiul 2
1. Citirea a trei numere reale (`double`).
2. Calculul și afișarea:
   - `max(a, b, c)`;
   - `min(a, b, c)`;
   - `max(a, b, c) / min(a, b, c)`;
   - `3 * max(a, b, c)`;
   - `4 - 2 * max(a, b, a + b - c)`;
   - `(max(a - b, b - c, a - c))^2 - 1` (expresie suplimentară adăugată în cod).

---

### Exercițiul 3 (funcții matematice)
1. Citirea unui număr real `x` (`double`).
2. Evaluarea și afișarea a patru funcții diferite definite pe bucăți:
   - Funcția 1: f(x) = x^2 pentru x < -5; f(x) = x + 1 pentru -5 <= x < 2; altfel f(x) = x^3.
   - Funcția 2: f(x) = cos(x) pentru x < 0; f(x) = 4 pentru x == 0; altfel f(x) = sin(x).
   - Funcția 3: f(x) = 3x + |x - 1| pentru x < 1; f(x) = 2 pentru 1 <= x < 6; altfel f(x) = log_3(x).
   - Funcția 4: f(x) = 1 pentru x <= 0; f(x) = x^2 + x pentru 0 < x <= 2; altfel f(x) = sin(pi * x).

---

### Exercițiul 4 (numere consecutive)
1. Citirea a două numere întregi (`int`).
2. Verificarea dacă cele două numere sunt consecutive (în oricare ordine). Dacă sunt, se afișează perechea în ordine crescătoare; altfel se afișează un mesaj corespunzător.

---

## Funcționalități & concepte abordate

- **Interactivitate:** meniu text și citire prin `Scanner`.
- **Varargs:** `public static double max(double... numbers)` și `min(double... numbers)` (intern sunt `double[]`).
- **Modularitate:** fiecare exercițiu este separat într-o metodă (`exercise1`, `exercise2`, `exercise3`, `exercise4`).
