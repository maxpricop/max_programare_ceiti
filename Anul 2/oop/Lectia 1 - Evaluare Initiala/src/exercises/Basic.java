package exercises;

public class Basic {
	public static String studentDiscount(boolean isStudent) {
		return isStudent ? "Discount aplicat!" : "Pret intreg!";
	}

	public static String osFact(String os) {
		switch (os) {
			case "Windows": {
				return "Windows a fost creat de Microsoft";
			}
			case "Linux": {
				return "Linux a fost creat de Linus";
			}
			case "Mac": {
				return "Mac OS a fost creat de Apple";
			}
			default: {
				return "";
			}
		}
	}

	public static String invertString(String original) {
		String inversat = "";

		int i = original.length() - 1;
		while (i >= 0) {
			inversat += original.charAt(i);
			i--;
		}

		return inversat;
	}

	public static int maxArrayValue(int[] array) {
		int max = array[0];

		for (int element : array) {
			if (element > max) max = element;
		}

		return max;
	}
}
