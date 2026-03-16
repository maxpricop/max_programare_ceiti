package lectia9.services;

import lectia9.model.*;

import java.util.ArrayList;
import java.util.List;

public class EmployeeService {
    private final ArrayList<Employee> employees = new ArrayList<>();

    public EmployeeService() {
        employees.add(new Developer("Ana", 28, 3000, "Java"));
        employees.add(new Developer("Maria", 32, 4000, "Python"));
        employees.add(new Manager("Ion", 45, 6000, 5));
        employees.add(new Manager("Elena", 38, 5500, 3));
        employees.add(new Developer("Andrei", 25, 2800, "JavaScript"));
        employees.add(new Intern("Alex", 22, 1200, "Ion"));
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public boolean removeEmployee(Employee employee) {
        return employees.remove(employee);
    }

    public List<Employee> getAllEmployees() {
        return employees;
    }

    public double getTotalSalary() {
        double total = 0;

        for (Employee e : employees) {
            total += e.calculateSalary();
        }

        return total;
    }
}
