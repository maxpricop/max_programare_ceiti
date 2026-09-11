# Lecția 1 — Media de concurs și media elevului

Aplicație de consolă C# cu două exerciții în [Program.cs](Program.cs), organizate în clasele private
`MediaDeConcurs` și `MediaElevului`, incluse în clasa `Program`. Pentru rulare este necesar SDK-ul .NET 10.

Din rădăcina repository-ului, execută:

```sh
dotnet run --project "Anul 3/programareaVizuala/Lectia 1 - Media de concurs/MediaDeConcurs.csproj"
```

La pornire, introdu `1` pentru primul exercițiu sau `2` pentru al doilea.
Dacă opțiunea este invalidă, meniul se repetă. După executarea exercițiului ales, programul se încheie.

## Exercițiul 1 — Media de concurs

Primul exercițiu calculează media de concurs în funcție de specialitatea aleasă.
Programul citește specialitatea, media examenelor de absolvire a gimnaziului și mediile disciplinelor de profil.
Specialitățile Programare, Web și Rețele aparțin profilului real și folosesc limba de instruire,
limba străină, matematica și informatica. Secretariat și Contabilitate aparțin profilului uman,
unde informatica este înlocuită cu istoria. Pentru Operator se folosesc doar matematica și informatica.

Formula este **MC = 0,6 × MDNP + 0,4 × MNEA**, unde **MC** reprezintă media de concurs,
**MDNP** este media aritmetică a disciplinelor de profil, iar **MNEA** este media examenelor de gimnaziu.
Notele trebuie să fie între 1 și 10 inclusiv. O specialitate sau o notă invalidă este cerută din nou.
La final, programul afișează profilul, media disciplinelor de profil, media examenelor și media de concurs.

De exemplu, pentru Operator, cu media examenelor `8`, matematica `9` și informatica `10`,
media disciplinelor de profil este `9,5`, iar media de concurs este `0,6 × 9,5 + 0,4 × 8 = 8,9`.

## Exercițiul 2 — Media elevului

Al doilea exercițiu citește numele elevului, numărul de obiecte și câte o notă pentru fiecare obiect.
Dacă apeși Enter fără să introduci numărul de obiecte, se folosesc 3 obiecte.
Numele nu poate fi gol, numărul de obiecte trebuie să fie un întreg pozitiv, iar notele trebuie să fie
între 1 și 10 inclusiv. Datele invalide sunt cerute din nou.

Programul calculează media aritmetică a notelor și stabilește statutul elevului.
O medie sub 5 înseamnă **Restanță**, iar o medie de la 5 inclusiv până la 7 exclusiv înseamnă **Binișor**.
Pentru o medie de la 7 inclusiv până la 8 exclusiv se acordă **Bursă gr. III**,
de la 8 inclusiv până la 9 exclusiv — **Bursă gr. II**, iar de la 9 până la 10 inclusiv — **Bursă gr. I**.
Aceste intervale includ și valorile de la praguri, omise în enunțul inițial.

La final, sunt afișate numele elevului, numărul de obiecte, media și statutul.
Statutul se stabilește folosind media calculată, fără rotunjire prealabilă.
De exemplu, pentru Ana Popescu, cu notele `7`, `8` și `9`, media este `8`, iar statutul este **Bursă gr. II**.
