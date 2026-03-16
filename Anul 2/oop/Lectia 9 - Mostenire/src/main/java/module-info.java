module lectia9 {
    requires transitive javafx.graphics;
    requires javafx.controls;
    requires javafx.fxml;

    opens lectia9 to javafx.fxml;
    opens lectia9.controllers to javafx.fxml;

    exports lectia9;
    exports lectia9.model;
    exports lectia9.services;
    exports lectia9.controllers;
}
