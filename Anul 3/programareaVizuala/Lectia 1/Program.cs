using System;
using System.IO;

public class Program {
    public static void Main() {
        while (true) {
            Console.WriteLine("Alege exercițiul:");
            Console.WriteLine("1 - Media de concurs");
            Console.WriteLine("2 - Media elevului");
            Console.Write("Introdu 1 sau 2: ");
            string? choice = Console.ReadLine();

            if (choice is null) {
                return;
            }

            switch (choice.Trim()) {
                case "1": {
                    MediaDeConcurs.Run();
                    return;
                }
                case "2": {
                    MediaElevului.Run();
                    return;
                }
                default: {
                    Console.WriteLine("Opțiunea este invalidă. Introdu 1 sau 2.");
                    break;
                }
            }
        }
    }

    private class MediaDeConcurs {
        public static void Run() {
            string profile = ReadProfile();
            double examAverage = ReadGrade("Introdu media la examenele de gimnaziu: ");
            double subjectAverage;

            switch (profile) {
                case "real": {
                    Console.WriteLine("Introdu mediile pentru disciplinele de profil:");
                    double instructionLanguage = ReadGrade("Introdu media la limba de instruire:  ");
                    double foreignLanguage = ReadGrade("Introdu media la limba străină: ");
                    double mathematics = ReadGrade("Introdu media la matematică: ");
                    double informatics = ReadGrade("Introdu media la informatică: ");

                    subjectAverage = (instructionLanguage + foreignLanguage + mathematics + informatics) / 4;
                    break;
                }
                case "uman": {
                    double instructionLanguage = ReadGrade("Introdu media la limba de instruire: ");
                    double foreignLanguage = ReadGrade("Introdu media la limba străină: ");
                    double mathematics = ReadGrade("Introdu media la matematică: ");
                    double history = ReadGrade("Introdu media la istorie: ");

                    subjectAverage = (instructionLanguage + foreignLanguage + mathematics + history) / 4;
                    break;
                }
                case "operator": {
                    double operatorMathematics = ReadGrade("Introdu media la matematică: ");
                    double informatics = ReadGrade("Introdu media la informatică: ");

                    subjectAverage = (operatorMathematics + informatics) / 2;
                    break;
                }
                default: {
                    throw new InvalidOperationException("Profil necunoscut.");
                }
            }

            // MC = 0,6 × MDNP + 0,4 × MNEA.
            double competitionAverage = 0.6 * subjectAverage + 0.4 * examAverage;

            Console.WriteLine();
            Console.WriteLine($"Profil: {profile}");
            Console.WriteLine($"Media disciplinelor de profil (MDNP): {subjectAverage}");
            Console.WriteLine($"Media examenelor (MNEA): {examAverage}");
            Console.WriteLine($"Media de concurs (MC): {competitionAverage}");

        }

        private static string ReadProfile() {
            while (true) {
                Console.WriteLine("Alege specialitatea (Programare, Web, Rețele, Secretariat, Contabilitate, Operator):");
                string specialty = ReadInput().ToLower();

                switch (specialty) {
                    case "programare": {
                        return "real";
                    }
                    case "web": {
                        return "real";
                    }
                    case "retele": {
                        return "real";
                    }
                    case "rețele": {
                        return "real";
                    }
                    case "reţele": {
                        return "real";
                    }
                    case "secretariat": {
                        return "uman";
                    }
                    case "contabilitate": {
                        return "uman";
                    }
                    case "operator": {
                        return "operator";
                    }
                    default: {
                        Console.WriteLine("Specialitatea este invalidă. Alege una dintre specialitățile afișate.");
                        break;
                    }
                }
            }
        }

        private static double ReadGrade(string prompt) {
            while (true) {
                Console.Write(prompt);
                string input = ReadInput().Replace(',', '.');

                if (double.TryParse(input, out double grade) && grade >= 1 && grade <= 10) {
                    return grade;
                }

                Console.WriteLine("Nota este invalidă. Introdu un număr între 1 și 10.");
            }
        }

        private static string ReadInput() {
            string? input = Console.ReadLine() ?? throw new EndOfStreamException();
            return input.Trim();
        }
    }

    private class MediaElevului {
        public static void Run() {
            string studentName = ReadStudentName();
            int subjectCount = ReadSubjectCount();
            double sum = 0;

            for (int index = 0; index < subjectCount; index++) {
                sum += ReadGrade($"Introdu nota pentru obiectul {index + 1}: ");
            }

            double average = sum / subjectCount;
            string status = GetStudentStatus(average);

            Console.WriteLine();
            Console.WriteLine($"Elev: {studentName}");
            Console.WriteLine($"Numărul de obiecte: {subjectCount}");
            Console.WriteLine($"Media notelor: {average}");
            Console.WriteLine($"Statut: {status}");
        }

        private static string ReadStudentName() {
            while (true) {
                Console.Write("Introdu numele elevului: ");
                string studentName = ReadInput();

                if (studentName.Length > 0) {
                    return studentName;
                }

                Console.WriteLine("Numele elevului nu poate fi gol.");
            }
        }

        private static int ReadSubjectCount() {
            while (true) {
                Console.Write("Introdu numărul de obiecte (Enter pentru 3): ");
                string input = ReadInput();

                if (input.Length == 0) {
                    return 3;
                }

                if (int.TryParse(input, out int subjectCount) && subjectCount > 0) {
                    return subjectCount;
                }

                Console.WriteLine("Numărul de obiecte trebuie să fie un număr întreg pozitiv.");
            }
        }

        private static double ReadGrade(string prompt) {
            while (true) {
                Console.Write(prompt);
                string input = ReadInput().Replace(',', '.');

                if (double.TryParse(input, out double grade) && grade >= 1 && grade <= 10) {
                    return grade;
                }

                Console.WriteLine("Nota este invalidă. Introdu un număr între 1 și 10 (de exemplu, 8,5).");
            }
        }

        private static string GetStudentStatus(double average) {
            if (average < 5) {
                return "Restanță";
            } else if (average < 7) {
                return "Binișor";
            } else if (average < 8) {
                return "Bursă gr. III";
            } else if (average < 9) {
                return "Bursă gr. II";
            } else {
                return "Bursă gr. I";
            }
        }

        private static string ReadInput() {
            string? input = Console.ReadLine() ?? throw new EndOfStreamException();
            return input.Trim();
        }
    }
}
