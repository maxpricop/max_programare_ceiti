import model.FileStatistics;
import services.FileAnalysisService;
import services.FileService;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        FileService fileService = new FileService();
        FileAnalysisService analysisService = new FileAnalysisService();

        // File Paths
        String dataDir = "data";
        String textFile = dataDir + "/text1.txt";
        String resultFile = dataDir + "/rezultat.txt";
        String copyFile = dataDir + "/copie_text1.txt";

        // Asigurăm existența directorului data/
        new File(dataDir).mkdirs();

        try (Scanner scanner = new Scanner(System.in)) {
            // Sarcina 1: Crează și scrie în data/text1.txt cu FileWriter
            fileService.createAndWriteFile(textFile);

            // Sarcina 2: Informații despre fișier (clasa File)
            fileService.displayFileInfo(textFile);

            // Sarcina 3: Citire caracter cu caracter (FileReader)
            fileService.readCharByChar(textFile);

            // Sarcina 4: Citire linie cu linie (BufferedReader)
            fileService.readLineByLine(textFile);

            // Sarcina 5: Statistici fișier (linii, cuvinte, caractere)
            FileStatistics stats = analysisService.analyzeFileStatistics(textFile);

            // Sarcina 6: Caută un cuvânt și numără aparițiile
            System.out.print("\n(Sarcina 6) Introduceți cuvântul pentru căutare: ");
            String searchWord = scanner.nextLine();

            int wordOccurrences = analysisService.countWordOccurrences(textFile, searchWord);
            stats.setSearchedWord(searchWord);
            stats.setWordOccurrences(wordOccurrences);

            // Sarcina 7: Salvează statisticile în data/rezultat.txt
            fileService.saveStatistics(resultFile, stats);

            // Sarcina 8: Listează fișierele .txt din directorul data/
            fileService.listTxtFiles(dataDir);

            // Sarcina 9: Copiază text1.txt -> data/copie_text1.txt
            fileService.copyFile(textFile, copyFile);

            /*
             * Sarcina 10
             * FileReader citește direct caractere din fișier, fără un buffer suplimentar,
             * fiind potrivit pentru exemple simple sau fișiere mici.
             * 
             * BufferedReader folosește un buffer intern, ceea ce reduce numărul de accesări
             * la disc și îmbunătățește performanța, mai ales la fișiere mari.
             * 
             * În practică, BufferedReader este de obicei mai eficient pentru citire repetată,
             * în special când lucrăm linie cu linie prin metoda readLine().
             */
        } catch (IOException e) {
            System.err.println("Eroare la operația cu fișiere: " + e.getMessage());
        }
    }
}
