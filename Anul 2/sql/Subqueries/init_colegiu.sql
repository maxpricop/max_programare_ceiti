DROP DATABASE IF EXISTS colegiu;
CREATE DATABASE colegiu;
USE colegiu;

CREATE TABLE Discipline (
    Id_disciplina SERIAL PRIMARY KEY,
    Denumire_disciplina VARCHAR(100) NOT NULL,
    Nr_ore_disciplina INT UNSIGNED NOT NULL
) ENGINE=InnoDB;

CREATE TABLE Profesori (
    Id_profesor SERIAL PRIMARY KEY,
    Nume_prof VARCHAR(50) NOT NULL,
    Pren_prof VARCHAR(50) NOT NULL,
    Telefon_profes VARCHAR(20) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE Studenti (
    Id_student SERIAL PRIMARY KEY,
    Nume_student VARCHAR(50) NOT NULL,
    Pren_student VARCHAR(50) NOT NULL,
    Data_nastere DATE NOT NULL,
    Adresa VARCHAR(255) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE Grupe (
    Id_grupa SERIAL PRIMARY KEY,
    Cod_grupa VARCHAR(20) NOT NULL,
    Specialitatea VARCHAR(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE Reusita (
    Id_student BIGINT UNSIGNED NOT NULL,
    Id_disciplina BIGINT UNSIGNED NOT NULL,
    Id_profesor BIGINT UNSIGNED NOT NULL,
    Id_grupa BIGINT UNSIGNED NOT NULL,
    Tip_evaluare VARCHAR(30) NOT NULL,
    Nota TINYINT UNSIGNED,
    Data_evaluare DATE,
    PRIMARY KEY (Id_student, Id_disciplina, Id_profesor, Id_grupa),
    CONSTRAINT FK_Reusita_Studenti FOREIGN KEY (Id_student) REFERENCES Studenti (Id_student),
    CONSTRAINT FK_Reusita_Discipline FOREIGN KEY (Id_disciplina) REFERENCES Discipline (Id_disciplina),
    CONSTRAINT FK_Reusita_Profesori FOREIGN KEY (Id_profesor) REFERENCES Profesori (Id_profesor),
    CONSTRAINT FK_Reusita_Grupe FOREIGN KEY (Id_grupa) REFERENCES Grupe (Id_grupa)
) ENGINE=InnoDB;

INSERT INTO Grupe (Id_grupa, Cod_grupa, Specialitatea)
VALUES
    (1, 'INF-1A', 'Informatică'),
    (2, 'MAT-2B', 'Matematică'),
    (3, 'ECO-3C', 'Economie'),
    (4, 'FIZ-1D', 'Fizică'),
    (5, 'BIO-2E', 'Biologie');

INSERT INTO Studenti (Id_student, Nume_student, Pren_student, Data_nastere, Adresa)
VALUES
    (1, 'Popescu', 'Ion', '2000-05-10', 'Str. Mihai Viteazu, nr. 10'),
    (2, 'Ionescu', 'Maria', '1999-08-15', 'Str. Libertății, nr. 25'),
    (3, 'Dragomir', 'Alexandru', '2001-02-28', 'Bd. Republicii, nr. 5'),
    (4, 'Dumitru', 'Elena', '2000-11-20', 'Str. Crinului, nr. 8'),
    (5, 'Constantinescu', 'Ana', '1998-04-03', 'Bd. Unirii, nr. 12');

INSERT INTO Profesori (Id_profesor, Nume_prof, Pren_prof, Telefon_profes)
VALUES
    (1, 'Popa', 'Mihai', '0722123456'),
    (2, 'Ionescu', 'Ana', '0733123456'),
    (3, 'Radu', 'George', '0764123456'),
    (4, 'Dragomirescu', 'Maria', '0725123456'),
    (5, 'Dumitrescu', 'Ion', '0726123456');

INSERT INTO Discipline (Id_disciplina, Denumire_disciplina, Nr_ore_disciplina)
VALUES
    (1, 'Matematică', 60),
    (2, 'Informatică', 80),
    (3, 'Fizică', 50),
    (4, 'Chimie', 45),
    (5, 'Biologie', 55);

INSERT INTO Reusita (
    Id_student,
    Id_disciplina,
    Id_profesor,
    Id_grupa,
    Tip_evaluare,
    Nota,
    Data_evaluare
)
VALUES
    (1, 1, 1, 1, 'Examen', 8, '2023-05-15'),
    (2, 2, 2, 2, 'Examen', 7, '2023-05-20'),
    (3, 3, 3, 3, 'Examen', 9, '2023-05-18'),
    (4, 4, 4, 4, 'Examen', 6, '2023-05-25'),
    (5, 5, 5, 5, 'Examen', 8, '2023-05-22');
