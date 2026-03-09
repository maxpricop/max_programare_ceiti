module studiul_individual_1 {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive javafx.graphics;
    requires java.sql;

    opens studiul_individual_1 to javafx.fxml;
    opens studiul_individual_1.controllers to javafx.fxml;
    opens studiul_individual_1.model to javafx.fxml;

    exports studiul_individual_1;
}
