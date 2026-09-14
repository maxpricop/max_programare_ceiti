# Lecția 2 - Liste în HTML

Deschide [index.html](index.html) într-un browser. Pagina conține sarcinile 4–12 despre liste ordonate, numerotare personalizată și liste imbricate, cu text îngroșat, înclinat și subliniat.

Lecția folosește exclusiv HTML, fără CSS sau JavaScript, și funcționează local, fără instalare sau server. Numerele și literele listelor sunt generate de browser, nu scrise manual în textul elementelor.

## Exerciții și noțiuni

| Sarcina | Exemplu | Elemente și atribute |
| --- | --- | --- |
| 4 | Clasament de tehnologii, de la 10 la 1 | `ol reversed` |
| 5 | Clasament de produse, de la 15 la 8 | `ol reversed start="15"` |
| 6 | Numerotare cu salturi la 10 și 20 | `li value` |
| 7 | Litere mari, de la D la I | `ol type="A" start="4"` |
| 8 | Cifre romane, de la IV la X | `ol type="I" start="4"` |
| 9 | Discipline și subdiscipline | Trei niveluri: `I`, `A`, `1` |
| 10 | Categorii dintr-un magazin online | Patru niveluri, litere mici și subliste cu `start` |
| 11 | Programul unei excursii, zilele III–V | Subliste alfabetice și salt de la 6 la 10 |
| 12 | Dezvoltarea unui site, de la 20 la 17 | Listă descrescătoare cu subliste crescătoare și valori speciale |

Fiecare sublistă este inclusă în elementul `li` căruia îi aparține. Atributul `start` primește un număr întreg inclusiv pentru listele alfabetice și romane. `value` schimbă numărul unui element și continuarea numerotării. În sarcina 4, `reversed` fără `start` începe numerotarea de la numărul de elemente din listă: 10.

Elementele `b`, `i` și `u` afișează text îngroșat, înclinat și subliniat. Comentariile HTML marchează fiecare sarcină prin numărul ei.
