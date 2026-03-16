package model;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterExercises {
	public void writeStudentList() {
		String filePath = "data/bufferedWriter/lista.txt";
		String[] students = { "Alexandru Ionescu", "Maria Popescu", "Andrei Constantin", "Elena Dumitrescu", "Mihai Popa" };

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
			for (String student : students) {
				writer.write(student);
				writer.newLine();
			}

			System.out.println("Student list written to: " + filePath);
		} catch (IOException e) {
			System.out.println("Error writing file: " + e.getMessage());
		}
	}

	public void writeNumbers() {
		String filePath = "data/bufferedWriter/numere.txt";

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
			for (int i = 1; i <= 10; i++) {
				writer.write(String.valueOf(i));
				writer.newLine();
			}

			System.out.println("Numbers 1-10 written to: " + filePath);
		} catch (IOException e) {
			System.out.println("Error writing file: " + e.getMessage());
		}
	}
}
