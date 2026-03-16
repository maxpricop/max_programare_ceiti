package lectia9.controllers;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;

import lectia9.model.*;
import lectia9.services.EmployeeService;

public class MainController {

    @FXML
    private TableView<Employee> employeeTable;
    @FXML
    private TableColumn<Employee, String> typeColumn;
    @FXML
    private TableColumn<Employee, String> nameColumn;
    @FXML
    private TableColumn<Employee, String> ageColumn;
    @FXML
    private TableColumn<Employee, String> salaryColumn;
    @FXML
    private TableColumn<Employee, String> totalSalaryColumn;
    @FXML
    private TableColumn<Employee, String> detailsColumn;
    @FXML
    private TableColumn<Employee, String> bonusColumn;

    @FXML
    private ComboBox<String> typeComboBox;
    @FXML
    private TextField nameField;
    @FXML
    private TextField ageField;
    @FXML
    private TextField salaryField;
    @FXML
    private Label extraLabel;
    @FXML
    private TextField extraField;

    @FXML
    private Label totalSalaryLabel;

    private final EmployeeService employeeService = new EmployeeService();
    private final ObservableList<Employee> tableData = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        typeComboBox.setItems(FXCollections.observableArrayList("Developer", "Manager", "Intern"));
        typeComboBox.getSelectionModel().selectFirst();
        updateExtraLabel("Developer");

        typeComboBox.getSelectionModel().selectedItemProperty().addListener((obs, oldVal, newVal) -> updateExtraLabel(newVal));

        typeColumn.setCellValueFactory(data -> {
            Employee e = data.getValue();
            if (e instanceof Developer) return new SimpleStringProperty("Developer");
            if (e instanceof Manager) return new SimpleStringProperty("Manager");
            if (e instanceof Intern) return new SimpleStringProperty("Intern");
            return new SimpleStringProperty("Employee");
        });

        nameColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getName()));

        ageColumn.setCellValueFactory(data -> new SimpleStringProperty(String.valueOf(data.getValue().getAge())));

        salaryColumn.setCellValueFactory(data -> new SimpleStringProperty(String.format("%.2f", data.getValue().getSalary())));

        totalSalaryColumn.setCellValueFactory(data -> new SimpleStringProperty(String.format("%.2f", data.getValue().calculateSalary())));

        detailsColumn.setCellValueFactory(data -> {
            Employee e = data.getValue();
            if (e instanceof Developer) return new SimpleStringProperty(((Developer) e).getProgrammingLanguage());
            if (e instanceof Manager) return new SimpleStringProperty("Team: " + ((Manager) e).getTeamSize());
            if (e instanceof Intern) return new SimpleStringProperty("Mentor: " + ((Intern) e).getMentorName());
            return new SimpleStringProperty("-");
        });

        bonusColumn.setCellValueFactory(data -> {
            Employee e = data.getValue();
            if (e instanceof Bonusable) { return new SimpleStringProperty(String.format("%.2f", ((Bonusable) e).calculateBonus())); }
            return new SimpleStringProperty("N/A");
        });

        tableData.addAll(employeeService.getAllEmployees());
        employeeTable.setItems(tableData);

        refreshTotal();
    }

    private void updateExtraLabel(String type) {
        if (type == null) return;

        switch (type) {
            case "Developer": {
                extraLabel.setText("Programming Language:");
                extraField.setPromptText("e.g. Java");
                break;
            }
            case "Manager": {
                extraLabel.setText("Team Size:");
                extraField.setPromptText("e.g. 5");
                break;
            }
            case "Intern": {
                extraLabel.setText("Mentor Name:");
                extraField.setPromptText("e.g. Ion");
                break;
            }
        }
    }

    @FXML
    private void handleAdd() {
        String type = typeComboBox.getValue();
        String name = nameField.getText().trim();
        String ageStr = ageField.getText().trim();
        String salStr = salaryField.getText().trim();
        String extra = extraField.getText().trim();

        if (name.isEmpty() || ageStr.isEmpty() || salStr.isEmpty() || extra.isEmpty()) {
            showAlert("Validation Error", "All fields are required.");
            return;
        }

        int age;
        double salary;
        try {
            age = Integer.parseInt(ageStr);
            salary = Double.parseDouble(salStr);
        } catch (NumberFormatException ex) {
            showAlert("Validation Error", "Age must be a whole number and salary must be a number.");
            return;
        }

        Employee employee;
        switch (type) {
            case "Developer": {
                employee = new Developer(name, age, salary, extra);
                break;
            }
            case "Manager": {
                int teamSize;

                try {
                    teamSize = Integer.parseInt(extra);
                } catch (NumberFormatException ex) {
                    showAlert("Validation Error", "Team size must be a whole number.");
                    return;
                }

                employee = new Manager(name, age, salary, teamSize);
                break;
            }
            case "Intern": {
                employee = new Intern(name, age, salary, extra);
                break;
            }
            default: {
                return;
            }
        }

        employeeService.addEmployee(employee);
        tableData.add(employee);

        refreshTotal();
        clearForm();
    }

    @FXML
    private void handleRemove() {
        Employee selected = employeeTable.getSelectionModel().getSelectedItem();

        if (selected == null) {
            showAlert("No Selection", "Please select an employee to remove.");

            return;
        }

        employeeService.removeEmployee(selected);
        tableData.remove(selected);
        refreshTotal();
    }

    @FXML
    private void handleCalculateTotal() {
        refreshTotal();
    }

    private void refreshTotal() {
        totalSalaryLabel.setText(String.format("%.2f", employeeService.getTotalSalary()));
    }

    private void clearForm() {
        nameField.clear();
        ageField.clear();
        salaryField.clear();
        extraField.clear();
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(AlertType.WARNING);

        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
