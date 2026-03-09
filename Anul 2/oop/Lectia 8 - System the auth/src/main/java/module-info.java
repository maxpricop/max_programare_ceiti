module lectia8 {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive javafx.graphics;
    requires javafx.base;

    opens lectia8.controllers to javafx.fxml;
    opens lectia8 to javafx.fxml;
    opens lectia8.model to javafx.base;

    exports lectia8;
    exports lectia8.controllers;
    exports lectia8.model;
}
