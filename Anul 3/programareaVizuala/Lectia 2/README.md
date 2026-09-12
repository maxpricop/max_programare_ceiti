# Lecția 2 — Media de concurs în Avalonia

Exercițiul „Media de concurs” din lecția 1, transcris într-o fereastră. Necesită SDK-ul .NET 10.
Din rădăcina repository-ului:

```sh
dotnet run --project "Anul 3/programareaVizuala/Lectia 2/Lectia2.csproj"
```

## Cum este construită interfața

În `MainWindow.axaml` descriem controalele și poziția lor:

- `ScrollViewer` permite derularea când fereastra este prea mică pentru tot conținutul.
- `StackPanel` așază titlul, formularul, butonul și rezultatul unul sub altul.
- Formularul este un singur `Grid` cu două coloane și șase rânduri `Auto`.
  Toate etichetele și câmpurile sunt copii direcți ai acestui grid.
- `ColumnDefinitions="Auto,*"` rezervă lățimea necesară etichetelor și oferă
  câmpurilor spațiul rămas. Toate câmpurile sunt astfel aliniate.
- `Grid.Row` și `Grid.Column` aleg celula, cu numerotarea de la **0**.
- `RowSpacing="10"` stabilește spațiul dintre rânduri, iar `ColumnSpacing="16"`
  stabilește spațiul dintre coloane. Nu folosim margini între rânduri.
  Gridul păstrează spațiul dintre rândurile definite chiar dacă unele câmpuri sunt ascunse.
- `x:Name` permite accesarea unui control din C#.

[Documentația Avalonia despre Grid](https://docs.avaloniaui.net/docs/how-to/grid-how-to)
explică dimensiunile și pozițiile în grid.

## Cum funcționează codul C#

Logica se află în `MainWindow.axaml.cs`, în clasa ferestrei. Pentru această lecție
folosim direct evenimente și controale, fără MVVM sau clase suplimentare.

1. Constructorul apelează `InitializeComponent()` pentru a crea controalele din XAML,
   apoi selectează implicit Programare.
2. `SelectionChanged` apelează `SpecialtyComboBox_SelectionChanged`. Acesta stabilește
   profilul și modifică `IsVisible` pentru etichetele și câmpurile necesare.
   Informatica și istoria ocupă același rând, dar numai una este vizibilă.
3. `Click` apelează `CalculateButton_Click`. În loc de `Console.ReadLine()`, citim
   proprietatea `Text` a fiecărui `TextBox`. `TryReadGrade` verifică dacă valoarea
   este un număr între 1 și 10; la o eroare, afișează un mesaj și selectează câmpul.
   `return` oprește calculul până când utilizatorul corectează datele și apasă din nou.
4. Calculăm media și scriem rezultatele în proprietățile `Text` ale controalelor
   `TextBlock`, în loc de `Console.WriteLine()`.
5. `TextChanged` ascunde rezultatul precedent când se modifică o notă.

`TryReadGrade` oferă două informații: rezultatul `bool` arată dacă nota este validă,
iar `out double grade` transmite nota către variabila apelantului. Folosim nota
doar când metoda întoarce `true`. Prefixul `Try` urmează modelul lui `double.TryParse`.
Un câmp gol sau o notă invalidă este o situație obișnuită într-un formular, deci
afișăm un mesaj și întoarcem `false`, fără să fie necesar un `try/catch`.
`CultureInfo.InvariantCulture` interpretează punctul ca separator zecimal după
înlocuirea virgulei, indiferent de limba sistemului.

## Reguli și exemple de verificare

| Specialități | Profil | Discipline pentru MDNP |
| --- | --- | --- |
| Programare, Web, Rețele | real | Limba de instruire, limba străină, matematică, informatică |
| Secretariat, Contabilitate | uman | Limba de instruire, limba străină, matematică, istorie |
| Operator | operator | Matematică, informatică |

**MC = 0,6 × MDNP + 0,4 × MNEA**, unde MDNP este media aritmetică a disciplinelor
de profil, iar MNEA este media examenelor de gimnaziu. Câmpurile ascunse nu participă
la calcul. Valorile se păstrează la schimbarea specialității, dar rezultatul se ascunde.

- Operator: examene `8`, matematică `9`, informatică `10` → MDNP `9,50`, MC **8,90**.
- Programare: examene `8`, limbi `9` și `8`, matematică `10`, informatică `9`
  → MDNP `9,00`, MC **8,60**.
- Secretariat: aceleași valori, dar istorie `7` → MDNP `8,50`, MC **8,30**.
- Încearcă un câmp gol, `abc`, `0` sau `11`: trebuie să apară o eroare.
  Valorile `1` și `10` sunt acceptate, la fel ca `8,5` și `8.5`.
- După un calcul, schimbă o notă sau specialitatea: rezultatul vechi trebuie să dispară.

Formatul `F2` afișează două zecimale; calculul folosește valorile nerotunjite.
Separatorul zecimal al rezultatului urmează setările sistemului.
