package services;

import model.FileStatistics;

import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileAnalysisService {

    /**
     * Sarcina 5
     * Analizează fișierul și returnează statisticile sale de bază:
     * numărul de linii, cuvinte și caractere.
     *
     * @param filePath calea către fișierul de analizat
     * @return un obiect {@link FileStatistics} cu linii, cuvinte și caractere completate
     * @throws IOException dacă fișierul nu poate fi deschis sau citit
     */
    public FileStatistics analyzeFileStatistics(String filePath) throws IOException {
        int lines = 0;
        int words = 0;
        int characters = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            while ((line = br.readLine()) != null) {
                lines++;
                characters += line.length();

                // Număr de cuvinte pe linie (separat prin spații albe)
                String[] tokens = line.trim().split("\\s+");
                if (!line.trim().isEmpty()) words += tokens.length;
            }
        }

        System.out.println("\n[Sarcina 5]");
        System.out.println("Statistici fișier:");
        System.out.println("Număr de linii:     " + lines);
        System.out.println("Număr de cuvinte:   " + words);
        System.out.println("Număr de caractere: " + characters);

        FileStatistics statistics = new FileStatistics();
        statistics.setLines(lines);
        statistics.setWords(words);
        statistics.setCharacters(characters);

        return statistics;
    }

    /**
     * Sarcina 6
     * Caută un cuvânt în fișier și returnează numărul de apariții.
     * Căutarea este case-insensitive și se face la nivel de cuvânt întreg.
     *
     * @param filePath calea către fișierul în care se face căutarea
     * @param searchWord cuvântul de căutat în text
     * @return numărul de apariții ale cuvântului căutat
     * @throws IOException dacă fișierul nu poate fi deschis sau citit
     */
    public int countWordOccurrences(String filePath, String searchWord) throws IOException {
        if (searchWord == null || searchWord.isBlank()) {
            System.out.println("\n[Sarcina 6]");
            System.out.println("Cuvânt căutat invalid (null sau gol). Număr de apariții: 0");

            return 0;
        }

        int occurrences = 0;
        Pattern searchPattern = Pattern.compile("\\b" + Pattern.quote(searchWord) + "\\b", Pattern.CASE_INSENSITIVE);

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            while ((line = br.readLine()) != null) {
                Matcher matcher = searchPattern.matcher(line);

                while (matcher.find()) {
                    occurrences++;
                }
            }
        }

        System.out.println("\n[Sarcina 6]");
        System.out.println("Cuvânt căutat: \"" + searchWord + "\"");
        System.out.println("Număr de apariții: " + occurrences);

        return occurrences;
    }
}
