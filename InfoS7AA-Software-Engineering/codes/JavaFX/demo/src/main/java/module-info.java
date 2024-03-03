module com.zac.colorpicker {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;
    requires javafx.graphics;

    opens com.zac.colorpicker to javafx.fxml;
    exports com.zac.colorpicker;
}