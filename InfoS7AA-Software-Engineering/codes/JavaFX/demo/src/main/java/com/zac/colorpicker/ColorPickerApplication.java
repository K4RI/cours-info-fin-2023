package com.zac.colorpicker;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;

public class ColorPickerApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        URL url = new URL("file:/C:/Users/USER/Documents/TRAVAIL/2A/slides_des_cours_auxquels_j_aurais_du_etre_plus_attentif_en_2021/InfoS7AA_Software_Engineering/codes/JavaFX/demo/target/classes/com/zac/colorpicker/colorpicker-view.fxml");
        FXMLLoader fxmlLoader = new FXMLLoader(ColorPickerApplication.class.getResource("colorpicker-view.fxml"));
        // FXMLLoader fxmlLoader = new FXMLLoader(url);
        Scene scene = new Scene(fxmlLoader.load(), 640, 360);
        stage.setTitle("Hello World");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}