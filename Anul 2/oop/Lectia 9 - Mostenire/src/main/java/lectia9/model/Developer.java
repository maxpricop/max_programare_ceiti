package lectia9.model;

public class Developer extends Employee implements Bonusable {
    private String programmingLanguage;

    public Developer(String name, int age, double salary, String programmingLanguage) {
        super(name, age, salary);
        this.programmingLanguage = programmingLanguage;
    }

    public String getProgrammingLanguage() {
        return programmingLanguage;
    }

    public void setProgrammingLanguage(String programmingLanguage) {
        this.programmingLanguage = programmingLanguage;
    }

    @Override
    public double calculateBonus() {
        return getSalary() * 0.15;
    }

    @Override
    public double calculateSalary() {
        return getSalary() + calculateBonus();
    }

    @Override
    public String info() {
        return "Developer: " + getName() + " - " + programmingLanguage;
    }
}
