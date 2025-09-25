# Lecția 1 – Operatori, tipuri de date (Java)

Acesta este un proiect realizat în cadrul **primei lecții de Java**, având ca scop înțelegerea și exersarea **operatorilor aritmetici** și a **tipurilor de date de bază** (`int`, `float`, `double`).
<br>
Programul este unul introductiv și pune accent pe interacțiunea cu utilizatorul și pe prelucrarea datelor citite de la tastatură.

---

## Structura proiectului

Proiectul este alcătuit dintr-un singur fișier:

- `src/Main.java` – Program principal, care conține un **meniu text** și implementările tuturor exercițiilor (ex1–ex9).

---

## Cerințele lecției

Proiectul implementează următoarele exerciții:

### Exercițiul 1
1. Citirea a două numere întregi.  
2. Calculul și afișarea:
   - sumei numerelor;  
   - diferenței numerelor.

### Exercițiul 2
1. Citirea a două numere întregi.  
2. Calculul și afișarea:
   - produsului numerelor;  
   - câtului împărțirii primului număr la al doilea (împărțire reală).

### Exercițiul 3
1. Citirea a două numere naturale.  
2. Calculul și afișarea:
   - mediei aritmetice;  
   - mediei geometrice.

### Exercițiul 4
1. Citirea lungimii laturii unui pătrat.  
2. Calculul și afișarea:
   - ariei pătratului;  
   - perimetrului pătratului.

### Exercițiul 5
1. Citirea lungimii laturii unui cub.  
2. Calculul și afișarea:
   - ariei totale a cubului;  
   - volumului cubului.

### Exercițiul 6
1. Citirea razei unui cerc.  
2. Calculul și afișarea:
   - ariei cercului;  
   - circumferinței cercului.

### Exercițiul 7
1. Citirea lungimii cercului (circumferința).  
2. Calculul și afișarea:
   - razei cercului (din circumferință);  
   - ariei cercului (calculată din rază).

### Exercițiul 8
1. Citirea numărului de laturi `n` al unui poligon regulat și a razei cercului circumscris `R`.  
2. Calculul și afișarea:
   - perimetrului poligonului;  
   - ariei poligonului;  
   - măsurii unghiului interior (grade);  
   - numărului de diagonale;  
   - razei cercului înscris (r).

### Exercițiul 9
1. Citirea coordonatelor a două puncte `A(ax, ay)` și `B(bx, by)`.  
2. Calculul și afișarea:
   - distanței dintre cele două puncte;  
   - coordonatelor mijlocului segmentului AB.

---

## Funcționalități & concepte abordate

- **Interactivitate:** meniu text, selecție prin `Scanner`.  
- **Modularitate locală:** fiecare exercițiu este izolat într-o metodă (`ex1` … `ex9`).  
- **Utilizare `Math`:** `Math.sqrt`, `Math.pow`, `Math.sin`, `Math.cos`, `Math.PI`.  
- **Validări de intrare implementate:** verificare împărțire la zero (ex2), verificare valori naturale (ex3), `n >= 3` și `R > 0` pentru poligon (ex8).  
- **Consistență tipuri:** s-a folosit `double` pentru intrări și calcule pentru a evita pierderea de precizie.

---

Acest proiect reprezintă **primul pas în programarea Java**, punând bazele necesare pentru lecțiile următoare ce vor aborda structuri de control, funcții și concepte de programare orientată pe obiecte.
