package model;

public class FileStatistics {
    private int lines;
    private int words;
    private int characters;
    private String searchedWord;
    private int wordOccurrences;

    public FileStatistics() {}

    public FileStatistics(int lines, int words, int characters, String searchedWord, int wordOccurrences) {
        this.lines = lines;
        this.words = words;
        this.characters = characters;
        this.searchedWord = searchedWord;
        this.wordOccurrences = wordOccurrences;
    }

    public int getLines() {
        return lines;
    }

    public void setLines(int lines) {
        this.lines = lines;
    }

    public int getWords() {
        return words;
    }

    public void setWords(int words) {
        this.words = words;
    }

    public int getCharacters() {
        return characters;
    }

    public void setCharacters(int characters) {
        this.characters = characters;
    }

    public String getSearchedWord() {
        return searchedWord;
    }

    public void setSearchedWord(String searchedWord) {
        this.searchedWord = searchedWord;
    }

    public int getWordOccurrences() {
        return wordOccurrences;
    }

    public void setWordOccurrences(int wordOccurrences) {
        this.wordOccurrences = wordOccurrences;
    }

    @Override
    public String toString() {
        String line1 = "=== Statistici Fișier ===";
        String line2 = "Număr de linii:     " + lines;
        String line3 = "Număr de cuvinte:   " + words;
        String line4 = "Număr de caractere: " + characters;
        String line5 = "Cuvânt căutat:      \"" + searchedWord + '"';
        String line6 = "Apariții cuvânt:    " + wordOccurrences;

        return line1 + '\n' + line2 + '\n' + line3 + '\n' + line4 + '\n' + line5 + '\n' + line6;
    }
}
