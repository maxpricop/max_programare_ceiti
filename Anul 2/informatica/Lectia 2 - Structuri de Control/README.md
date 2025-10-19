# Lectia 2 - Structuri de control

Acest proiect este o continuare practică a lecțiilor introductive de Java. Scopul este exersarea citirii de la tastatură, a operării cu valori reale (`double`) și a scrierii de funcții generice de **min** / **max**. Programul oferă un meniu simplu care rulează două exerciții diferite (cu 2, respectiv 3 numere).

---

## Structura proiectului

- `src/Main.java` – Program principal cu meniul text, implementarea exercițiilor și funcțiile `min`/`max`.

---

## Ce face programul (pe scurt)

- Afișează un meniu și citește opțiunea utilizatorului (1 sau 2).
- `Exercitiul 1` — primește două numere și afișează expresii care folosesc `min` și `max` pentru 2 argumente.
- `Exercitiul 2` — primește trei numere și afișează expresii care folosesc `min` și `max` pentru 3 argumente.
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
   - `4 - 2 * max(a, b, a + b - c)`.

---

## Funcționalități & concepte abordate

- **Interactivitate:** meniu text și citire prin `Scanner`.
- **Varargs:** `public static double max(double... numbers)` și `min(double... numbers)` (intern sunt `double[]`).
- **Modularitate:** fiecare exercițiu este separat într-o metodă (`exercise1`, `exercise2`).
