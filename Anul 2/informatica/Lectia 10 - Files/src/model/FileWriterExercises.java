package model;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriterExercises {
	public void writeGreeting() {
		String filePath = "data/fileWriter/salut.txt";

		try (FileWriter writer = new FileWriter(filePath)) {
			writer.write("Buna ziua!\n");
			writer.write("Acesta este primul meu fisier.\n");
			System.out.println("File written successfully: " + filePath);
		} catch (IOException e) {
			System.out.println("Error writing file: " + e.getMessage());
		}
	}

	public void writeUsername(Scanner scanner) {
		String filePath = "data/fileWriter/utilizator.txt";

		System.out.print("Enter your name: ");
		String username = scanner.nextLine();

		try (FileWriter writer = new FileWriter(filePath)) {
			writer.write(username);
			System.out.println("Name written to file: " + filePath);
		} catch (IOException e) {
			System.out.println("Error writing file: " + e.getMessage());
		}
	}
}
