module lectia6 {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive javafx.graphics;
    requires javafx.base;

    // Allow FXMLLoader reflection access to our packages
    opens lectia6 to javafx.fxml;
    opens lectia6.controllers to javafx.fxml;
    opens lectia6.model to javafx.fxml;
    opens lectia6.storage to javafx.fxml;
    opens lectia6.util to javafx.fxml;

    exports lectia6;
    exports lectia6.data;
    exports lectia6.controllers;
    exports lectia6.model;
    exports lectia6.storage;
    exports lectia6.util;
}
