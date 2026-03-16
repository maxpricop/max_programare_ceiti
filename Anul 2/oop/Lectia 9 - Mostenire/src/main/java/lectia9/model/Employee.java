package lectia9.model;

public class Employee extends Person {
    private double salary;

    public Employee(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double calculateSalary(double bonus) {
        return salary + bonus;
    }

    public double calculateSalary() {
        return calculateSalary(0);
    }

    @Override
    public String info() {
        return super.info() + ", Salary: " + salary;
    }
}
