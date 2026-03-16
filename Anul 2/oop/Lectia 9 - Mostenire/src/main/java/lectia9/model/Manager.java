package lectia9.model;

public class Manager extends Employee implements Bonusable {
    private int teamSize;

    public Manager(String name, int age, double salary, int teamSize) {
        super(name, age, salary);
        this.teamSize = teamSize;
    }

    public int getTeamSize() {
        return teamSize;
    }

    public void setTeamSize(int teamSize) {
        this.teamSize = teamSize;
    }

    @Override
    public double calculateBonus() {
        return teamSize * 500.0;
    }

    @Override
    public double calculateSalary() {
        return getSalary() + calculateBonus();
    }

    @Override
    public String info() {
        return "Manager: " + getName() + " - team " + teamSize;
    }
}
