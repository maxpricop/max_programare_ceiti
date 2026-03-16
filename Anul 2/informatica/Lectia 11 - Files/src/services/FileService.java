package services;

import model.FileStatistics;

import java.io.*;

public class FileService {

    /**
     * Sarcina 1
     * Crează fișierul specificat și scrie câteva paragrafe în el folosind {@link FileWriter}.
     * 
     * @param filePath calea către fișierul ce va fi creat
     * @throws IOException dacă fișierul nu poate fi creat sau scris
     */
    public void createAndWriteFile(String filePath) throws IOException {
        try (FileWriter fw = new FileWriter(filePath)) {
            fw.write("Afara este primavara.\n");
            fw.write("Absentele cresc drastic.\n");
            fw.write("Absentele trebuie motivate.\n");
        }

        System.out.println("[Sarcina 1]");
        System.out.println("Fișierul \"" + filePath + "\" a fost creat și scris cu succes.");
    }

    /**
     * Sarcina 2
     * Afișează informații despre fișier folosind clasa {@link File}:
     * nume, cale absolută, dimensiune și drepturi de citire/scriere.
     *
     * @param filePath calea către fișierul de inspectat
     */
    public void displayFileInfo(String filePath) {
        File file = new File(filePath);

        System.out.println("\n[Sarcina 2]");
        System.out.println("Informații despre fișier:");
        System.out.println("Nume:            " + file.getName());
        System.out.println("Cale absolută:   " + file.getAbsolutePath());
        System.out.println("Dimensiune:      " + file.length() + " bytes");
        System.out.println("Drept de citire: " + (file.canRead() ? "Da" : "Nu"));
        System.out.println("Drept de scriere:" + (file.canWrite() ? "Da" : "Nu"));
        System.out.println("Există:          " + (file.exists() ? "Da" : "Nu"));
    }

    /**
     * Sarcina 3
     * Citește și afișează conținutul fișierului caracter cu caracter folosind {@link FileReader}.
     *
     * @param filePath calea către fișierul de citit
     * @throws IOException dacă fișierul nu poate fi deschis sau citit
     */
    public void readCharByChar(String filePath) throws IOException {
        System.out.println("\n[Sarcina 3]");
        System.out.println("Citire caracter cu caracter (FileReader):");

        System.out.println("------------------------------------------------------");
        try (FileReader fr = new FileReader(filePath)) {
            int ch;

            while ((ch = fr.read()) != -1) {
                System.out.print((char) ch);
            }
        }
        System.out.println("------------------------------------------------------");
    }

    /**
     * Sarcina 4
     * Citește și afișează conținutul fișierului linie cu linie folosind {@link BufferedReader}.
     *
     * @param filePath calea către fișierul de citit
     * @throws IOException dacă fișierul nu poate fi deschis sau citit
     */
    public void readLineByLine(String filePath) throws IOException {
        System.out.println("\n[Sarcina 4]");
        System.out.println("Citire linie cu linie (BufferedReader):");

        System.out.println("-----------------------------------------------------");
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }
        System.out.println("-----------------------------------------------------");
    }

    /**
     * Sarcina 7
     * Salvează statisticile textului analizat într-un fișier folosind {@link FileWriter}.
     *
     * @param filePath calea către fișierul de ieșire (ex. {@code rezultat.txt})
     * @param stats obiectul {@link FileStatistics} ce conține datele de salvat
     * @throws IOException dacă fișierul nu poate fi creat sau scris
     */
    public void saveStatistics(String filePath, FileStatistics stats) throws IOException {
        try (FileWriter fw = new FileWriter(filePath)) {
            fw.write(stats.toString());
            fw.write("\n");
        }

        System.out.println("\n[Sarcina 7]");
        System.out.println("Statisticile au fost salvate în fișierul: " + filePath);
    }

    /**
     * Sarcina 8
     * Listează toate fișierele {@code .txt} din directorul specificat folosind {@link File}.
     *
     * @param directoryPath calea către directorul de scanat
     */
    public void listTxtFiles(String directoryPath) {
        File dir = new File(directoryPath);

        System.out.println("\n[Sarcina 8]");
        System.out.println("Fișiere .txt în directorul: " + directoryPath);

        File[] txtFiles = dir.listFiles((d, name) -> name.toLowerCase().endsWith(".txt"));

        if (txtFiles == null || txtFiles.length == 0) {
            System.out.println("Nu au fost găsite fișiere .txt.");

            return;
        }

        for (File f : txtFiles) {
            System.out.println(f.getName() + " - " + f.length() + " bytes");
        }

    }

    /**
     * Sarcina 9
     * Copiază un fișier de la sursă la destinație folosind {@link FileInputStream} și {@link FileOutputStream}.
     *
     * @param sourcePath calea fișierului sursă
     * @param destinationPath calea fișierului destinație
     * @throws IOException dacă sursa nu poate fi citită sau destinația nu poate fi scrisă
     */
    public void copyFile(String sourcePath, String destinationPath) throws IOException {
        try (FileInputStream fis = new FileInputStream(sourcePath); FileOutputStream fos = new FileOutputStream(destinationPath)) {
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }
        }

        System.out.println("\n[Sarcina 9]");
        System.out.println("Fișierul a fost copiat cu succes.");
        System.out.println("Sursă: " + sourcePath);
        System.out.println("Destinație: " + destinationPath);
    }
}
