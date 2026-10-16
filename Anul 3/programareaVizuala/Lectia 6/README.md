# Lecția 6: MathGeo Visualizer

Variantă simplă a [laboratorului nr. 6](https://docs.google.com/document/d/1V3cHouEC1327kbkIZNlCC_fYYVumMCrlWdZstC2iHFg/edit).
Folosește Avalonia și .NET 10, ca lecțiile precedente, pentru a rula și pe Linux.

Din rădăcina repository-ului:

```sh
dotnet run --project "Anul 3/programareaVizuala/Lectia 6/Lectia6.csproj"
```

## Utilizare

Alegeți triunghiul, dreptunghiul sau cercul și introduceți dimensiunile în metri.
Aria se afișează în m², iar perimetrul în m, fiecare împreună cu formula sa.
Rezultatele se actualizează la modificarea textului.
Separatorul zecimal urmează setările sistemului.

- Triunghi: trei laturi pozitive care respectă inegalitatea triunghiului.
  Aria folosește formula lui Heron, iar perimetrul este suma laturilor.
  Aplicația indică dacă triunghiul este echilateral, isoscel, oarecare sau dreptunghic.
- Dreptunghi: lățime și înălțime. `A = l × h`, `P = 2 × (l + h)`.
- Cerc: rază. `A = π × r²`, `P = 2 × π × r`.

Un triunghi poate fi simultan isoscel și dreptunghic. Verificarea teoremei lui
Pitagora permite mici diferențe de rotunjire. Câmpurile ascunse sunt ignorate.
La date invalide, apare un mesaj, iar rezultatele și figura precedentă sunt eliminate.
Rezultatele afișează până la trei zecimale. Valorile extreme pot fi respinse dacă
formula nu poate produce un rezultat numeric valid.

## Codul

Interfața este în `MainWindow.axaml`. Un `Grid` așază titlul, câmpurile,
mesajul de eroare, desenul și rezultatele pe rânduri.
Un `WrapPanel` grupează selectorul figurii și dimensiunile orizontal, deasupra desenului.
Fiecare dimensiune are o etichetă și un `TextBox` într-un `StackPanel`.
Formulele și rezultatele apar sub desen. `Border` delimitează câmpurile și zona de desen.
Un `Viewbox` redimensionează uniform un `Canvas` de 500 × 360 pentru a-l încadra în fereastră.

Tot codul lecției este în `MainWindow.axaml.cs`, cu metode obișnuite:

- `FigureComboBox_SelectionChanged` schimbă etichetele și câmpurile vizibile.
- `DimensionTextBox_TextChanged` apelează `Calculate` la modificarea unei dimensiuni.
- `ReadNumber` verifică dacă un câmp conține un număr pozitiv și finit.
- `Calculate` citește datele, aplică formulele, afișează rezultatele și apelează desenarea.
- `DrawFigure` creează un `Polygon`, `Rectangle` sau `Ellipse` în același `Canvas`.
  Aceeași scară pe ambele direcții păstrează proporțiile figurii.

La fiecare calcul se golește `Canvas.Children`, apoi se desenează figura pe un fundal simplu.
Aplicația folosește variabile locale și instrucțiuni `if/else`.

## Verificare

```sh
dotnet run --project "Anul 3/programareaVizuala/Lectia 6/Tests/Lectia6.Tests.csproj"
```

Adăugați `-- --screenshots` pentru imagini în `/tmp/lectia6-simple-*.png`.
Verificările acoperă formulele, clasificarea triunghiurilor, datele invalide,
actualizarea automată a rezultatelor și figurile din Canvas.

## Predare

Copiați proiectul sub numele `Pricop_Maxim_Lab6`, încărcați folderul în Google Drive,
permiteți vizualizarea celor care au linkul și trimiteți linkul ca hiperlink pe Moodle.
Folderele generate `bin/` și `obj/` pot fi omise.
