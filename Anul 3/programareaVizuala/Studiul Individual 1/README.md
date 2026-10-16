# Tura Barbershop

Studiul individual nr. 1, Programare vizuală. Maxim Pricop, P-2433.

Aplicație desktop în C# și Avalonia, pentru evidența programărilor unei frizerii.
Interfața este definită în XAML, iar acțiunile sunt scrise în evenimentele controalelor.

## Pornire

Este necesar .NET SDK 10. Din acest dosar:

```bash
dotnet restore BarberDesk.csproj
dotnet run --project BarberDesk.csproj
```

## Ce face aplicația

- Adaugă, editează și șterge programări.
- Caută după numele sau telefonul clientului; filtrează după dată, frizer și stare.
- Afișează prețul și durata serviciului ales.
- Folosește stările Programată, Finalizată și Anulată.
- Verifică numele, telefonul, formatul orei, programul 09:00–18:00 și suprapunerile.
- Păstrează observații pe mai multe rânduri.
- Adaugă, editează și șterge servicii, prețuri și durate din Administrare.
- Gestionează lista frizerilor. Corectarea numelui se aplică și programărilor existente.
- Calculează un rezumat al listei filtrate: programate, finalizate, anulate și valoarea serviciilor finalizate.
- Exportă lista filtrată în CSV, cu alegerea fișierului prin dialogul sistemului.
- Resetează toate filtrele la ziua curentă din meniul Programări.

Datele sunt păstrate într-un `List<Appointment>`, numai în memorie. La fiecare pornire
apar trei exemple fictive. Modificările se pierd la închidere. Catalogul pornește cu trei
servicii și trei frizeri, care pot fi modificați în Administrare. Programul de lucru este același
în fiecare zi. Nu există autentificare, plăți sau trimitere de mesaje.

O programare anulată rămâne în listă, dar nu mai ocupă intervalul. Ștergerea elimină
elementul după confirmare. Două programări consecutive sunt permise, de exemplu
10:00–10:30 și 10:30–11:00. Pentru verificarea clientului se compară telefonul introdus;
folosiți același format al numărului pentru același client.

Modificarea unui serviciu înlocuiește obiectul din catalog. Programările existente
păstrează serviciul rezervat, cu prețul și durata de atunci. La editarea unei programări
vechi, tariful rezervat rămâne selectat; poate fi înlocuit explicit cu un serviciu din
catalogul actual. Ștergerea unui serviciu nu șterge programările.

Un frizer cu programări nu poate fi șters. Numele lui poate fi corectat. Catalogul trebuie
să păstreze cel puțin un serviciu și un frizer.

Exportul conține numai rezultatele filtrelor curente, inclusiv observațiile. CSV-ul este
scris în UTF-8, cu separator `;`. Nu este un fișier de salvare care poate fi reîncărcat
în aplicație. Pentru a păstra zerourile inițiale, importați coloana Telefon ca text în
programul de calcul tabelar. Rezumatul arată valoarea serviciilor marcate Finalizată;
nu reprezintă confirmarea unor plăți.

## Cum este organizat codul

- `Models/Appointment.cs`: câmpurile unei programări și textele afișate în listă.
- `Models/Service.cs`: numele, durata și prețul serviciului.
- `Data/ShopData.cs`: listele, exemplele inițiale și verificarea unei programări.
- `Views/MainWindow.axaml` și `.axaml.cs`: lista, filtrele și butoanele principale.
- `Views/AppointmentWindow.axaml` și `.axaml.cs`: formularul comun pentru adăugare și editare.
- `Views/CatalogWindow`, `BarbersWindow`: formularele de administrare.
- `Views/ConfirmWindow`: confirmarea ștergerii.
- `Data/CsvExport.cs`: formatarea datelor pentru export.
- `App.axaml`: câteva culori și dimensiuni comune.
- `Documentation/`: capturile versiunii actuale.
- `Tests/`: verificări separate; nu sunt necesare pentru pornirea aplicației.

Pentru studierea codului, începeți cu `Appointment`, apoi cu `ShopData`, `Add_Click`
și `Save_Click`. `foreach` parcurge lista, `if` verifică datele, iar `TryParseExact`
transformă ora introdusă în text. `await ShowDialog` așteaptă răspunsul din formular
fără să blocheze interfața. Nu sunt folosite MVVM, comenzi, baze de date sau salvare JSON.

## Legătura cu raportul

Lucrarea acoperă părțile I și II: plasarea componentelor, proprietăți, metode,
evenimente, butoane, editare simplă și multilinie, etichete, meniu, gruparea opțiunilor,
modificarea stării controalelor și conversia șirurilor.

Cerința despre ferestre este adaptată la Avalonia prin ferestre și dialoguri cu
`ShowDialog` și `Close`. Aceasta nu este o implementare MDI clasică, cu ferestre copil
în interiorul unei ferestre părinte. Gruparea stărilor folosește `Border`, `StackPanel`
și `RadioButton` cu același `GroupName`.

Conectarea la baza de date este lăsată pentru studiul individual nr. 2.

[Raportul privat în Google Docs](https://docs.google.com/document/d/10Wz8dRmSupf7jUnolrsKqDm1oot_MLpLQiUhdLK4QyA/edit)

Contul Google conectat: **baiatulnurofencontact@gmail.com**. Raportul are cuprins cu
legături. Cuprinsul automat și câmpurile cu numărul paginii vor fi adăugate manual,
conform deciziei autorului. Proiectul nu a fost încărcat și nu a fost trimis profesorului.

## Verificare

```bash
dotnet build BarberDesk.csproj
dotnet run --project Tests/BarberDesk.Tests.csproj
```

Pentru a regenera capturile:

```bash
dotnet run --project Tests/BarberDesk.Tests.csproj -- Documentation
```

Verificările acoperă regulile de programare și interacțiunile cu formularele:
adăugare, editare, renunțare, confirmarea ștergerii, filtrare și mesaje de eroare.
Sunt verificate și păstrarea tarifelor rezervate, administrarea frizerilor, rezumatul
și formatarea CSV. La ultima verificare au trecut toate cele 58 de cazuri.
