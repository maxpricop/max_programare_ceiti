# Lecția 1 - Structura unei pagini HTML și formatarea textului

Această lecție introduce structura unui document HTML și elementele folosite pentru organizarea textului într-o pagină web. Exercițiile ilustrează titluri, paragrafe, liste, text preformatat, formule matematice și versuri. CSS-ul adaugă culori, spațiere și aliniere prin exemple simple.

## Deschiderea lecției

Deschide [index.html](index.html) într-un browser. Cuprinsul oferă acces la fiecare exemplu, iar paginile au un link de întoarcere.

Fișierele funcționează local, fără instalare sau server. Lecția folosește HTML și CSS, fără JavaScript.

## Noțiuni studiate

- **Structura documentului:** `<!doctype html>`, `html`, `head` și `body`; titlul din fila browserului, limba paginii și codificarea UTF-8.
- **Organizarea conținutului:** titluri, paragrafe, liste, linkuri între pagini și comentarii HTML pentru delimitarea secțiunilor în sursă.
- **Formatarea textului:** caractere îngroșate și înclinate, subliniere, păstrarea spațiilor cu `pre`, indici cu `sub` și exponenți cu `sup`.
- **Stilizarea cu CSS:** selectori, clase, culori, fundaluri, margini și aliniere. Dimensiunile folosesc unități relative: `rem` & `%`.

## Lucrare practică nr. 2

| Exercițiu | Exemplu | Ce ilustrează |
| --- | --- | --- |
| 1 | [Magazin de rechizite](pages/01-magazin.html) | Titluri `h1` și `h3`, produse aliniate într-un bloc `pre` și o linie orizontală albastră. |
| 2 | [Congruența triunghiurilor](pages/02-teoreme.html) | Două enunțuri înclinate, titluri îngroșate și subliniate, separate printr-o linie roșie centrată. |
| 3 | [Formule matematice](pages/03-formule.html) | Indici, exponenți și formule centrate; scrierea semnului „mai mic” prin `&lt;`. |
| 4a | [Linii aliniate la dreapta](pages/04-linii-dreapta.html) | Cinci elemente `hr` cu lățimi crescătoare și aceeași margine dreaptă. |
| 4b | [Linii centrate](pages/04-linii-centru.html) | Cinci elemente `hr` cu lățimi descrescătoare, centrate prin margini automate. |
| 4c | [Text în trepte](pages/04-trepte.html) | Cuvinte în elemente `span`, afișate pe rânduri separate și deplasate progresiv prin CSS. |
| 5 | [„Adio” de Vasile Alecsandri](pages/05-poezie.html) | Strofe în paragrafe, versuri separate cu `br`, text îngroșat și înclinat, titlu verde pe fundal galben. |

## Lucrare practică nr. 2 - Luceafărul

[luceafarul.html](pages/luceafarul.html) conține primele zece strofe din „Luceafărul” de Mihai Eminescu.
Titlul și autorul apar împreună într-un `h1` roșu, subliniat și centrat. Primele cinci strofe au fonturi,
culori, dimensiuni și stiluri diferite, cu aliniere la stânga, la centru și la dreapta. Ultimele cinci
folosesc `h2`, dimensiunea `medium`, text roșu (`#ff0000`), îngroșat, înclinat și centrat.

Pagina include cel puțin trei alinieri și trei dimensiuni distincte, precum și un paragraf final
despre elementele HTML folosite.

## Organizarea fișierelor

```text
Lectia 1/
├── index.html       # Cuprinsul lecției
├── README.md
├── pages/           # Câte un fișier HTML pentru fiecare exemplu
└── css/
    ├── base.css     # Stiluri comune tuturor paginilor
    ├── index.css    # Stilurile cuprinsului
    ├── magazin.css
    ├── teoreme.css
    ├── formule.css
    ├── linii.css    # Comun celor două exemple cu linii
    ├── trepte.css
    ├── poezie.css
    └── luceafarul.css
```

Fiecare pagină încarcă `base.css` și fișierul CSS al exemplului respectiv. Pentru a studia un exercițiu, deschide împreună fișierul său HTML și foaia de stil asociată: HTML-ul descrie conținutul, iar CSS-ul stabilește aspectul acestuia.
