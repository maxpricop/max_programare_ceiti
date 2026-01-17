package exercises;

public class Student {
	private String name;
	private int[] grades;

	public Student(String originalName, int[] originalGrades) {
		this.name = originalName;
		this.grades = originalGrades;
	}

	public void setName(String newName) {
		this.name = newName;
	}

	public void setGrades(int[] newGrades) {
		this.grades = newGrades;
	}

	public String getName() {
		return this.name;
	}

	public int[] getGrades() {
		return this.grades;
	}

	public double gradeAvereage() {
		if (this.grades == null || this.grades.length == 0) return 0.0;

		double gradesCombined = 0.0;

		for (int grade : this.grades) {
			gradesCombined += grade;
		}

		double avereage = gradesCombined / this.grades.length;
		return avereage;
	}
}
