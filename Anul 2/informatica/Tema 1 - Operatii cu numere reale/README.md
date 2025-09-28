# Tema 1 – Operatii cu numere reale

Acesta este prima temă pentru acasă, având ca scop înțelegerea și exersarea lucrului cu **numere reale** (`float`) și aplicarea funcțiilor matematice de bază (`Math.round`).
<br/>
Programul este unul introductiv și pune accent pe împărțirea unui număr real în componente și pe interacțiunea cu utilizatorul printr-un **meniu text**.

---

## Structura proiectului

Proiectul este alcătuit dintr-un singur fișier:

- `src/Main.java` – Program principal, care conține un **meniu text** și două variante de rezolvare a exercițiului:
  - versiunea fară input (numărul este introdus direct în cod);
  - versiunea cu input de la tastatură (folosind clasa `Scanner`).

---

## Cerințele temei

Proiectul implementează următorul exercițiu:
<br/>
Se dă un număr real `n`. Să se afișeze:
1. **Partea întreagă** a numărului.  
2. **Partea fracționară** a numărului.  
3. **Rotunjirea** numărului la cel mai apropiat întreg.  

Programul oferă două modalități de rezolvare:
- cu valoarea introdusă direct în cod;
- cu valoarea introdusă de utilizator prin tastatură.

---

## Funcționalități & concepte abordate

- **Interactivitate:** meniu text, selecție prin `Scanner`.  
- **Modularitate locală:** fiecare variantă este izolată într-o metodă (`exerciseWithScanner`, `exerciseWithoutScanner`).  
- **Utilizare `Math`:** `Math.round` pentru rotunjire.  
