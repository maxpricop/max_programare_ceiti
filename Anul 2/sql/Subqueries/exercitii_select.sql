USE colegiu;

-- EXERCITIUL 1
-- Studentii care au luat nota mai mare decat media tuturor notelor.
SELECT DISTINCT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume,
    r.Nota
FROM Studenti AS s
INNER JOIN Reusita AS r
    ON r.Id_student = s.Id_student
WHERE r.Nota > (
    SELECT AVG(r2.Nota)
    FROM Reusita AS r2
    WHERE r2.Nota IS NOT NULL
)
ORDER BY s.Nume_student, s.Pren_student, r.Nota DESC;

-- EXERCITIUL 2
-- Numele si prenumele studentilor care au obtinut nota maxima.
SELECT DISTINCT
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume
FROM Studenti AS s
INNER JOIN Reusita AS r
    ON r.Id_student = s.Id_student
WHERE r.Nota = (
    SELECT MAX(r2.Nota)
    FROM Reusita AS r2
    WHERE r2.Nota IS NOT NULL
)
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 3
-- Disciplinele la care s-au luat note sub 7.
SELECT DISTINCT
    d.Id_disciplina AS ID,
    d.Denumire_disciplina AS Disciplina
FROM Discipline AS d
WHERE d.Id_disciplina IN (
    SELECT r.Id_disciplina
    FROM Reusita AS r
    WHERE r.Nota < 7
)
ORDER BY d.Denumire_disciplina;

-- EXERCITIUL 4
-- Profesorii care au evaluat mai mult de un student.
SELECT
    p.Id_profesor AS ID,
    p.Nume_prof AS Nume,
    p.Pren_prof AS Prenume
FROM Profesori AS p
WHERE p.Id_profesor IN (
    SELECT r.Id_profesor
    FROM Reusita AS r
    GROUP BY r.Id_profesor
    HAVING COUNT(DISTINCT r.Id_student) > 1
)
ORDER BY p.Nume_prof, p.Pren_prof;

-- EXERCITIUL 5
-- Studentii care au sustinut examenul la disciplina "Matematica".
SELECT DISTINCT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume
FROM Studenti AS s
WHERE s.Id_student IN (
    SELECT r.Id_student
    FROM Reusita AS r
    WHERE r.Tip_evaluare = 'Examen'
      AND r.Id_disciplina IN (
          SELECT d.Id_disciplina
          FROM Discipline AS d
          WHERE d.Denumire_disciplina LIKE 'Matematic%'
      )
)
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 6
-- Grupele la care s-a dat nota minima.
SELECT DISTINCT
    g.Id_grupa AS ID,
    g.Cod_grupa,
    g.Specialitatea
FROM Grupe AS g
WHERE g.Id_grupa IN (
    SELECT r.Id_grupa
    FROM Reusita AS r
    WHERE r.Nota = (
        SELECT MIN(r2.Nota)
        FROM Reusita AS r2
        WHERE r2.Nota IS NOT NULL
    )
)
ORDER BY g.Cod_grupa;

-- EXERCITIUL 7
-- Studentii care locuiesc pe strazi ce contin "Bd.".
SELECT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume,
    s.Adresa
FROM Studenti AS s
WHERE s.Adresa LIKE '%Bd.%'
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 8
-- Disciplinele predate de profesorul "Ionescu Ana".
SELECT DISTINCT
    d.Id_disciplina AS ID,
    d.Denumire_disciplina AS Disciplina
FROM Discipline AS d
WHERE d.Id_disciplina IN (
    SELECT r.Id_disciplina
    FROM Reusita AS r
    WHERE r.Id_profesor IN (
        SELECT p.Id_profesor
        FROM Profesori AS p
        WHERE p.Nume_prof = 'Ionescu'
          AND p.Pren_prof = 'Ana'
    )
)
ORDER BY d.Denumire_disciplina;

-- EXERCITIUL 9
-- Studentii nascuti dupa anul 2000.
SELECT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume,
    s.Data_nastere
FROM Studenti AS s
WHERE YEAR(s.Data_nastere) > 2000
ORDER BY s.Data_nastere, s.Nume_student, s.Pren_student;

-- EXERCITIUL 10
-- Studentii care au obtinut nota 8.
SELECT DISTINCT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume
FROM Studenti AS s
WHERE s.Id_student IN (
    SELECT r.Id_student
    FROM Reusita AS r
    WHERE r.Nota = 8
)
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 11
-- Numele profesorului care a evaluat studentul "Ionescu Maria".
SELECT DISTINCT
    p.Nume_prof AS Nume,
    p.Pren_prof AS Prenume
FROM Profesori AS p
WHERE p.Id_profesor IN (
    SELECT r.Id_profesor
    FROM Reusita AS r
    WHERE r.Id_student IN (
        SELECT s.Id_student
        FROM Studenti AS s
        WHERE s.Nume_student = 'Ionescu'
          AND s.Pren_student = 'Maria'
    )
)
ORDER BY p.Nume_prof, p.Pren_prof;

-- EXERCITIUL 12
-- Studentii care au dat examen la disciplina cu cele mai multe ore.
SELECT DISTINCT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume
FROM Studenti AS s
WHERE s.Id_student IN (
    SELECT r.Id_student
    FROM Reusita AS r
    WHERE r.Tip_evaluare = 'Examen'
      AND r.Id_disciplina IN (
          SELECT d.Id_disciplina
          FROM Discipline AS d
          WHERE d.Nr_ore_disciplina = (
              SELECT MAX(d2.Nr_ore_disciplina)
              FROM Discipline AS d2
          )
      )
)
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 13
-- Grupele care au studenti cu nota peste 7.
SELECT DISTINCT
    g.Id_grupa AS ID,
    g.Cod_grupa,
    g.Specialitatea
FROM Grupe AS g
WHERE g.Id_grupa IN (
    SELECT r.Id_grupa
    FROM Reusita AS r
    WHERE r.Nota > 7
)
ORDER BY g.Cod_grupa;

-- EXERCITIUL 14
-- Studentii care au luat nota egala cu media notelor lor proprii.
SELECT DISTINCT
    s.Id_student AS ID,
    s.Nume_student AS Nume,
    s.Pren_student AS Prenume
FROM Studenti AS s
WHERE EXISTS (
    SELECT 1
    FROM Reusita AS r
    WHERE r.Id_student = s.Id_student
      AND r.Nota = (
          SELECT AVG(r2.Nota)
          FROM Reusita AS r2
          WHERE r2.Id_student = s.Id_student
            AND r2.Nota IS NOT NULL
      )
)
ORDER BY s.Nume_student, s.Pren_student;

-- EXERCITIUL 15
-- Disciplina la care s-a sustinut examenul cel mai recent.
SELECT DISTINCT
    d.Id_disciplina AS ID,
    d.Denumire_disciplina AS Disciplina
FROM Discipline AS d
WHERE d.Id_disciplina IN (
    SELECT r.Id_disciplina
    FROM Reusita AS r
    WHERE r.Tip_evaluare = 'Examen'
      AND r.Data_evaluare = (
          SELECT MAX(r2.Data_evaluare)
          FROM Reusita AS r2
          WHERE r2.Tip_evaluare = 'Examen'
      )
)
ORDER BY d.Denumire_disciplina;
