package model;

import java.io.FileReader;
import java.io.IOException;

public class FileReaderExercises {
	public void readCharByChar() {
		String filePath = "data/fileReader/date.txt";

		try (FileReader reader = new FileReader(filePath)) {
			int charCode;

			while ((charCode = reader.read()) != -1) {
				System.out.print((char) charCode);
			}

			System.out.println();
		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		}
	}

	public void countCharacters() {
		String filePath = "data/fileReader/mesaj.txt";

		int totalChars = 0;
		try (FileReader reader = new FileReader(filePath)) {
			while (reader.read() != -1) {
				totalChars++;
			}

			System.out.println("Total characters in file: " + totalChars);
		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		}
	}
}
