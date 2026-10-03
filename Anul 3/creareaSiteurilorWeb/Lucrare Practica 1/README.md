# Lucrarea practică 1 - Prima evaluare HTML

Primul test la disciplina Crearea site-urilor web. Pagina realizată are tema "Pregătim un picnic" și este marcată ca varianta 26.

## Deschiderea lucrării

Deschide [index.html](index.html) într-un browser. Lucrarea folosește HTML și CSS, fără JavaScript, instalare sau server.

Imaginile, înregistrarea audio și videoclipul sunt locale. Păstrează structura dosarelor când copiezi lucrarea. Fontul Inter se încarcă de pe Google Fonts și necesită internet; fără conexiune, pagina folosește Arial sau fontul sans-serif disponibil în browser.

## Conținutul paginii

| Secțiune | Implementare |
| --- | --- |
| Antet | Titlul "Pregătim un picnic", subtitlu, numărul ediției și o linie decorativă `hr`. |
| Introducere | Imagine principală cu `figure` și `figcaption`, un paragraf despre pregătire și un citat cu `q`. |
| Pregătirea picnicului | O listă neordonată `ul` cu obiectele necesare și o listă ordonată `ol` cu etapele pregătirii, afișate pe două coloane. |
| Detalii și vocabular | A doua imagine cu legendă și o listă de definiții `dl`, `dt`, `dd` pentru picnic, coș de picnic și reciclare. |
| Audio și video | Sunete de păsări în format OGG și un videoclip MP4, cu `controls`; videoclipul folosește imaginea principală drept `poster`. |
| Provocare | O întrebare despre trei lucruri indispensabile la picnic și invitația de a scrie două propoziții. |
| Subsol | Textul "Evaluare practică HTML / Varianta 26". |

Documentul declară limba română și codificarea UTF-8. Conținutul este organizat cu `header`, `main`, `section`, `article`, `aside` și `footer`, iar imaginile au texte alternative `alt`.

[Foaia de stil](styles/style.css) stabilește culorile, tipografia, spațierea și dimensiunile elementelor media. Listele și secțiunea cu imagine și definiții folosesc CSS Grid pentru aranjarea pe două coloane.

## Fișiere

```text
Lucrare Practica 1/
├── README.md
├── index.html
├── styles/
│   └── style.css
├── images/
│   ├── picnic.jpg
│   └── mancare-picnic.jpg
├── audio/
│   └── pasari.ogg
└── video/
    └── picnic.mp4
```
