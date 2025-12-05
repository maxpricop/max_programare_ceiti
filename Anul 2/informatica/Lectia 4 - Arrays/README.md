# Lectia 4 - Arrays

Acest proiect conține exerciții practice care ilustrează utilizarea array-urilor (tablouri), a buclelor și a colecțiilor simple în Java. Scopul este de a exersa operații uzuale asupra unui array: parcurgere, agregare, filtrare și eliminare duplicate.

---

## Structura proiectului

- `src/Main.java` – Program principal care citește un array de la tastatură și efectuează mai multe operații asupra lui.

---

## Ce face programul (pe scurt)

- Cere utilizatorului să introducă dimensiunea unui array și elementele sale (numere întregi).
- Calculează și afișează diverse informații: media aritmetică, produsul elementelor pare, numărul elementelor pare, suma elementelor impare.
- Afișează elementele în ordine, în ordine inversă și lista elementelor unice (fără duplicate).

---

## Cerințele implementate (detaliat)

1. Citește dimensiunea array-ului (`int n`) de la tastatură și validează (n >= 0).
2. Citește `n` elemente întregi și le stochează într-un `int[]`.
3. Calculează media aritmetică a elementelor și o afișează cu precizie float.
4. Calculează produsul elementelor pare.
5. Numără elementele pare și afișează acest număr.
6. Calculează suma elementelor impare și o afișează.
7. Afișează elementele array-ului în ordine (de la index 0 la n-1).
8. Afișează elementele array-ului în ordine inversă (de la n-1 la 0).
9. Afișează elementele unice (fără duplicate) în ordinea primei apariții, folosind `LinkedHashSet`.

---

## Funcționalități & concepte abordate

- **Array-uri:** declarare, alocare, accesare și parcurgere.
- **Bucle:** `for` și `for-each` pentru agregări și afisări.
- **Colecții:** `Set` / `LinkedHashSet` pentru eliminarea duplicatelor păstrând ordinea.
- **I/O:** citire de la tastatură cu `Scanner`.
- **Tipuri primare:** utilizare de `int`, `float` și conversii acolo unde e nevoie.
- **Modularitate:** logica principală este extrasă într-o metodă (`exercise`) care poate fi adaptată sau reutilizată.
