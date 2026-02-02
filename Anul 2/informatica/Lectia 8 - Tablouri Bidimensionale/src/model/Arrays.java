package model;

public class Arrays {
	private int[][] array;

	public Arrays(int[][] initialArray) {
		this.array = initialArray;
	}

	public void setArray(int[][] newArray) {
		this.array = newArray;
	}

	public int[][] getArray() {
		return this.array;
	}

	public int getArrayLength() {
		return this.array.length;
	}

	public int getSubArrayLength(int index) throws IndexOutOfBoundsException {
		if (index < 0 || index >= array.length) throw new IndexOutOfBoundsException("Indexul este in afara limitelor array-ului.");
		return this.array[index].length;
	}

	public int getSumEvenNumbers() {
		int sum = 0;

		for (int i = 0; i < this.array.length; i++) {
			for (int j = 0; j < this.array[i].length; j++) {
				if (this.array[i][j] % 2 == 0) sum += this.array[i][j];
			}
		}

		return sum;
	}

	public int getSumOddNumbers() {
		int sum = 0;

		for (int i = 0; i < this.array.length; i++) {
			for (int j = 0; j < this.array[i].length; j++) {
				if (this.array[i][j] % 2 != 0) sum += this.array[i][j];
			}
		}

		return sum;
	}

	public int getMaxInRow(int rowIndex) throws IllegalArgumentException, IndexOutOfBoundsException {
		if (rowIndex < 0 || rowIndex >= array.length) throw new IndexOutOfBoundsException("Indexul este in afara limitelor array-ului.");

		if (this.array[rowIndex].length == 0) throw new IllegalArgumentException("Array-ul de la indexul specificat este gol.");

		int maxValue = this.array[rowIndex][0];

		for (int j = 1; j < this.array[rowIndex].length; j++) {
			if (this.array[rowIndex][j] > maxValue) maxValue = this.array[rowIndex][j];
		}

		return maxValue;
	}

	public void displayArray() {
		for (int i = 0; i < this.array.length; i++) {
			System.out.print("Array " + i + ": ");

			for (int j = 0; j < this.array[i].length; j++) {
				System.out.print(this.array[i][j] + " ");
			}

			System.out.println();
		}
	}

	public void displayLengths() {
		System.out.println("Lungimile array-urilor bidimensionale:");

		for (int i = 0; i < this.array.length; i++) {
			System.out.println("Lungimea array-ului " + i + " este: " + this.array[i].length);
		}
	}

	public void displaySumEvenNumbers() {
		int sum = getSumEvenNumbers();

		System.out.println("Suma numerelor pare din array este: " + sum);
	}

	public void displaySumOddNumbers() {
		int sum = getSumOddNumbers();

		System.out.println("Suma numerelor impare din array este: " + sum);
	}

	public void displayMaxInRows() {
		System.out.println("Valorile maxime pe fiecare rand:");

		for (int i = 0; i < this.array.length; i++) {
			try {
				int maxValue = getMaxInRow(i);
				System.out.println("Valoarea maxima in randul " + i + " este: " + maxValue);
			} catch (IllegalArgumentException e) {
				System.out.println("Randul " + i + " este gol.");
			}
		}
	}

	// Codul original mutat in constructor si metode de mai sus
	// public void biArray() {
	// int[][] array = new int[][] { {}, { 3, 5, 7, 68 }, { 2, 6, 5, 8, 10 } };

	// System.out.println("Strings" + array.length);

	// for (int i = 0; i < array.length; i++) {
	// System.out.println("Nr de eleme " + i + " este " + array[i].length);
	// }

	// System.out.print("----");

	// for (int i = 0; i < array.length; i++) {
	// System.out.print("\nString nr " + i + ":\t");
	// for (int j = 0; j < array[i].length; j++) {
	// System.out.print(array[i][j] + " ");
	// }
	// }

	// System.out.println("\n----");

	// int sNp = 0;
	// for (int[] ints : array) {
	// for (int amInt : ints) {
	// if (amInt % 2 == 0) sNp += amInt;
	// }
	// }

	// System.out.println("Suma numerelor pare: " + sNp);

	// System.out.println("----");

	// for (int[] row : array) {
	// if (row.length == 0) { System.out.println("Randul este gol"); continue; }

	// int maxValue = row[0];

	// for (int value : row) {
	// if (value > maxValue) maxValue = value;
	// }

	// System.out.println("Valoarea maxima pe rand este: " + maxValue);
	// }
	// }
}
