package studiul_individual_2;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

/**
 * JavaFX application entry point.
 */
public class App extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        Parent root = loadFXML("main-view");
        Scene scene = new Scene(root, 1220, 760);
        scene.getStylesheets().add(
                Objects.requireNonNull(
                        App.class.getResource("styles/dark-theme.css"),
                        "The dark theme stylesheet is missing."
                ).toExternalForm()
        );

        stage.setTitle("Sistem de transport public");
        stage.setMinWidth(1060);
        stage.setMinHeight(700);
        stage.setScene(scene);
        stage.show();
    }

    private Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
