package lectia9.model;

public class Intern extends Employee {
    private String mentorName;

    public Intern(String name, int age, double salary, String mentorName) {
        super(name, age, salary);
        this.mentorName = mentorName;
    }

    public String getMentorName() {
        return mentorName;
    }

    public void setMentorName(String mentorName) {
        this.mentorName = mentorName;
    }

    @Override
    public double calculateSalary() {
        return getSalary() * 0.8;
    }

    @Override
    public String info() {
        return "Intern: " + getName() + " - mentor: " + mentorName;
    }
}
