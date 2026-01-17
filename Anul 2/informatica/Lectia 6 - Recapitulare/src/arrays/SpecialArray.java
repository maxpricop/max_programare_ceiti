package arrays;

import java.util.Arrays;

public class SpecialArray {
	private int[] array;

	public SpecialArray() {
		this.array = new int[0];
	}

	public void setArray(int[] newArray) {
		this.array = newArray;
	}

	public int[] getArray() {
		return this.array;
	}

	public int getMaxElement() {
		if (this.array == null || this.array.length == 0) return 0;

		int max = this.array[0];

		for (int element : this.array) {
			if (element > max) max = element;
		}

		return max;
	}

	public int getMinElement() {
		if (this.array == null || this.array.length == 0) return 0;

		int min = this.array[0];

		for (int element : this.array) {
			if (element < min) min = element;
		}

		return min;
	}

	public int countElement(int chosenElement) {
		if (this.array == null || this.array.length == 0) return 0;

		int counter = 0;

		for (int element : this.array) {
			if (element == chosenElement) counter++;
		}

		return counter;
	}

	public int[] getIndexesOfElement(int chosenElement) {
		int[] indexes = new int[0];
		if (this.array == null || this.array.length == 0) return indexes;

		for (int i = 0; i < this.array.length; i++) {
			if (this.array[i] != chosenElement) continue;

			indexes = Arrays.copyOf(indexes, indexes.length + 1);
			indexes[indexes.length - 1] = i;
		}

		return indexes;
	}

	public int getMaxElementUnderLimit(int limit) {
		if (this.array == null || this.array.length == 0) return 0;

		int max = this.array[0];

		for (int element : this.array) {
			if (element > max && element <= limit) max = element;
		}

		return max;
	}
}
