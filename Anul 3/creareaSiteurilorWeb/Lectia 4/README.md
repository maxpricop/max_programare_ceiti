# Lecția 4 - Formulare și taguri semantice

Minisite pentru evenimentul fictiv "Atelierul web CEITI", realizat după fișa de laborator.
Autor: Maxim Pricop, CEITI, anul III.

Deschide [index.html](index.html) în browser. Paginile folosesc HTML și un fișier comun [style.css](style.css), fără
JavaScript sau dependențe externe. CSS-ul adaugă spațiere, culori discrete, o lățime de lectură și câmpuri mai lizibile.
La cererea autorului, această variantă include puțin CSS, deși fișa inițială cerea numai HTML.

## Cerințe realizate

| Sarcina | Implementare |
| --- | --- |
| 1 | Pagina principală conține `header`, `nav`, `main`, secțiunile Despre și Program, un anunț de trei propoziții, `aside` cu trei informații utile și `footer`. |
| 2 | `contact.html` conține nume, e-mail și mesaj obligatorii, etichete asociate, atribute `name`, butoane Submit și Reset. |
| 3 | Înscrierea include `text`, `email`, `password`, `number`, `date`, `tel` și atributele de validare cerute. |
| 4 | Grup radio obligatoriu, checkbox-uri independente și un select obligatoriu cu două grupuri de câte două opțiuni. Comentariul explică `checked`. |
| 5 | Oraș cu patru sugestii în `datalist`, fișier PDF/JPG/PNG, culoare și mesaj de maximum 200 de caractere. |
| 6 | Trei grupuri principale cu `fieldset` și `legend`, câmp ascuns pentru eveniment, confirmare obligatorie și butoane Submit și Reset. |
| 7 | Navigare relativă între toate paginile, două articole cu întrebări frecvente și un link de contact în `aside`. |
| 8 | Câmp suplimentar `type="url"` pentru portofoliu și comentarii HTML despre două probleme de validare reproduse la testare. |

## Testare în browser

Verificat automat în Firefox: cazurile invalide, formularele valide, câmpurile opționale goale, selecțiile multiple,
Reset și navigarea. La verificarea butoanelor Submit, testul a interceptat trimiterea pentru a evita o cerere POST.

Folosește exclusiv date fictive. Exemplu valid: `Participant Test`, `ana@example.com`, parola `fictiva123`, vârsta `18`, data `2026-10-24`.
Alege un mod de participare, un atelier și bifează confirmarea. Telefonul și detaliile suplimentare pot rămâne necompletate.

- Încearcă trimiterea formularelor fără câmpurile obligatorii.
- Introdu un e-mail invalid, vârsta `13` sau `26`, o parolă de șapte caractere și un telefon cu litere ori cu doar opt cifre.
- Lasă neales grupul radio sau atelierul și nebifată confirmarea.
- Introdu o adresă invalidă în câmpul opțional pentru portofoliu.
- Bifează mai multe activități și schimbă modul de participare. Numai un buton radio poate rămâne selectat.
- Apasă Reset. Câmpurile fără valori inițiale se golesc, Atelier practic redevine bifat și culoarea revine la `#7c3aed`.
- Verifică linkurile între pagini și ancorele Despre și Program.

`placeholder` afișează un indiciu, fără să completeze câmpul. `value` stabilește o valoare inițială.
`datalist` oferă sugestii, dar permite și alte orașe. `accept` filtrează tipurile propuse de selectorul de fișiere.

Formularele au `method="post"` și `action="#"`, conform cerinței. Browserul verifică datele înainte de trimitere.
Nu există un server care să primească sau să salveze datele. Cu toate câmpurile valide, trimiterea poate afișa o eroare
la deschiderea locală sau pe un server static; aceasta nu reprezintă o confirmare de înscriere.
Formularul de înscriere include `enctype="multipart/form-data"` pentru câmpul de fișier.

## Predare

Arhiva `Pricop_Maxim_Formulare.zip` conține cele trei pagini, `index.html`, `inscriere.html` și `contact.html`, plus `style.css`.
Extrage toate cele patru fișiere în același dosar pentru a păstra navigarea și aspectul paginilor.
Arhiva este pregătită pentru încărcarea în activitatea indicată de profesor.
