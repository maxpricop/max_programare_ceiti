package model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BufferedReaderExercises {
	public void readLineByLine() {
		String filePath = "data/bufferedReader/text.txt";

		try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
			String line;

			while ((line = reader.readLine()) != null) {
				System.out.println(line);
			}
		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		}
	}

	public void sumNumbers() {
		String filePath = "data/bufferedReader/numere.txt";

		int sum = 0;
		try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
			String line;

			while ((line = reader.readLine()) != null) {
				line = line.trim();

				if (!line.isEmpty()) sum += Integer.parseInt(line);
			}

			System.out.println("Sum of numbers: " + sum);
		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		} catch (NumberFormatException e) {
			System.out.println("Invalid number format: " + e.getMessage());
		}
	}
}
