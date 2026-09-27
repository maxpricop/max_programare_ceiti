# Lecția 3 - Obiecte media și cadre interne în HTML

Tema: **Starship: de la lansare la recuperare**.

Deschide `index.html` în browser. Întregul dosar se poate copia pentru predare: imaginile, videoclipurile, sunetul și pagina din iframe sunt locale și funcționează fără internet. Numai linkurile către surse necesită internet.

Pagina folosește HTML și un fișier CSS scurt, fără JavaScript, biblioteci sau instalare.

## Cerințe realizate

| Sarcina | Implementare |
| --- | --- |
| 1 | `h1`, subtitlu `h2`, prezentare de patru propoziții și `hr` |
| 2 | Patru fotografii diferite, atribute `src`, `alt`, `width`, încărcare `lazy` și lățimi diferite |
| 3 | `figure`, `img` și o legendă explicativă în `figcaption` |
| 4 | `picture` cu două fotografii distincte: Starship pe rampă la maximum 800px și în zbor la minimum 801px; `img` este ultimul |
| 5 | Clasa `.imagine-evidentiata`: `width`, `height`, `object-fit`, `border`, `border-radius` |
| 6 | `video` cu MP4 și WebM, `controls`, `width`, `poster` și `preload` |
| 7 | `audio` cu `src` MP3, `controls`, `loop`, `preload` și explicație sub player |
| 8 | `iframe` cu `src`, `title`, `width`, `height`, `loading="lazy"`, care afișează `detalii.html` |
| 9 | Secțiuni în ordinea cerută, fiecare cu titlu și context |

La audio este folosit direct atributul `src`, deci nu sunt necesare două elemente `source`.
Pentru imaginea personalizată, `cover` umple cadrul prin decupare, iar `contain` păstrează întreaga fotografie. Varianta finală folosește `contain`, pentru a păstra vizibil boosterul.

## Fișiere

- `index.html` - pagina principală;
- `detalii.html` - informații suplimentare și creditele materialelor;
- `style.css` - reguli simple de lizibilitate, limitarea lățimii media și clasa cerută;
- `imagini/` - patru fotografii și posterul video; `picture` selectează două fotografii diferite din galerie;
- `video/` - recuperarea boosterului din zborul 5, cu sunet original, în MP4 și WebM;
- `audio/` - 20 de secunde de sunet de la prima lansare de test (2023), dintr-o înregistrare separată.

Fotografiile aparțin lui Steve Jurvetson (CC BY 2.0), videoclipul provine de la TimBunning1 (CC0), iar extrasul audio de la adimifus (CC BY 3.0). Linkurile sursă, licențele și adaptările sunt indicate în `detalii.html`. Aceste materiale își păstrează licențele proprii, separat de licența codului din repository.
