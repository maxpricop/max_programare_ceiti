module lectia7 {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive javafx.graphics;

    opens lectia7.controllers to javafx.fxml;

    exports lectia7;
    exports lectia7.model;
    exports lectia7.controllers;
    exports lectia7.storage;
    exports lectia7.util;
}
