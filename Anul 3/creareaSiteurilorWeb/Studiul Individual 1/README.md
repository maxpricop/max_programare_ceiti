# Orbit — Explorarea spațiului

Studiul individual 1: site școlar în limba română, cu trei pagini și o singură foaie de stil.
Folosește exclusiv HTML și CSS, fără JavaScript extern sau încorporat în pagini.

## Deschidere

Deschide `index.html` într-un browser. Nu este necesară instalarea sau pornirea unui server.
Imaginile, videoclipul și sunetul sunt locale. Doar resursele externe necesită internet.

## Structură

- `index.html`: Starship, Artemis, New Glenn, comparație, audio și video.
- `misiuni.html`: viitoarele misiuni Artemis, Blue Moon și stațiile Orbital Reef, Axiom Station și Starlab.
- `formular.html`: formular cu nume, email, select, radio, checkbox, textarea și butoane submit/reset.
- `style.css`: toate stilurile; dimensiuni relative, Grid și Flexbox, fără px sau @media.
- `images/` și `media/`: fotografii JPEG, filmare WebM și audio WAV.

Fiecare pagină are h1/h2/h3, paragrafe, liste ul/ol, imagine cu alt, tabel cu minimum
trei rânduri de date și trei coloane, linkuri și meniu comun.

Formularul folosește validarea HTML pentru câmpurile obligatorii și formatul emailului.
Butonul „Verifică formularul” declanșează validarea nativă a browserului; dacă datele sunt valide,
formularul redeschide `formular.html` prin metoda GET, cu valorile în adresa URL.
Nu există procesare pe server, răspuns generat sau trimitere de email.
Butonul „Resetează” readuce câmpurile la valorile inițiale prin HTML.

## Media și surse

Fotografiile, videoclipul și sunetul provin din surse online și sunt păstrate local.
Fișierele originale nu au fost modificate; previzualizarea video este un cadru extras din filmare.

- `images/starship.jpg`: „Full Stack starship”, 16 aprilie 2023, Jenny Hautmann pentru Supercluster.
  [Fotografia originală](https://commons.wikimedia.org/wiki/File:Full_Stack_starship.jpg),
  [licență CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/). Fără modificări.
- `images/new-glenn.jpg`: lansarea New Glenn pe timp de zi, 13 noiembrie 2025, U.S. Space Force / Samuel Becker.
  [Fotografia și statutul de domeniu public](https://commons.wikimedia.org/wiki/File:Blue_Origin_New_Glenn_flight_2.jpg).
- `images/artemis.jpg`: lansarea Artemis I, 16 noiembrie 2022, NASA / Bill Ingalls.
  [Pagina NASA](https://www.nasa.gov/image-article/artemis-i-launch-5/).
- `images/iss.jpg`: panourile solare ale ISS deasupra Pacificului, 20 iunie 2020, NASA.
  [Pagina NASA](https://www.nasa.gov/image-article/international-space-station-above-pacific-ocean/).

- `media/starship-catch.webm`: filmare de 45,45 secunde a capturării boosterului Super Heavy
  la zborul Starship 5, pe 13 octombrie 2024, de la Isla Blanca Park. Autor: TimBunning1.
  [Pagina sursă și licența CC0](https://commons.wikimedia.org/wiki/File:Space_X_Starship_Flight_5_Booster_Landing.webm).
  [Fișier original](https://upload.wikimedia.org/wikipedia/commons/1/12/Space_X_Starship_Flight_5_Booster_Landing.webm).
- `images/starship-catch.jpg`: cadru extras la secunda 38 din aceeași filmare, folosit ca previzualizare.
- `media/sun-sonification.wav`: „Sun Sonification”, 82,8 secunde, publicat de NASA.
  Date ESA/NASA SOHO, procesate de A. Kosovichev, Stanford Experimental Physics Lab.
  Este o sonificare a datelor solare, nu o înregistrare cu microfonul în vid.
  [Sursă și credite](https://www.nasa.gov/solar-system/sounds-of-the-sun/).
  [Fișier original](https://www.nasa.gov/wp-content/uploads/2018/07/sun_sonification.wav).

Creditele media sunt păstrate în acest README. Nu există redare automată.

Informațiile despre viitor sunt planuri, nu rezultate garantate. Consultate la 18 octombrie 2026:

- [SpaceX — Starship](https://www.spacex.com/vehicles/starship/)
- [NASA — Artemis III](https://www.nasa.gov/mission/artemis-iii/)
- [NASA — Artemis IV](https://www.nasa.gov/mission/artemis-iv/)
- [Blue Origin — New Glenn](https://www.blueorigin.com/new-glenn)
- [Blue Origin — Blue Moon](https://www.blueorigin.com/blue-moon)
- [NASA — stații comerciale](https://www.nasa.gov/humans-in-space/commercial-space/commercial-space-stations/)

Aprobarea temei de către profesor se face separat, conform cerințelor școlare.
