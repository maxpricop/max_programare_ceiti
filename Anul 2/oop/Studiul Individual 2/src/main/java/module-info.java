module studiul_individual_2 {
    requires javafx.controls;
    requires javafx.fxml;

    opens studiul_individual_2 to javafx.graphics;
    opens studiul_individual_2.controllers to javafx.fxml;
}
