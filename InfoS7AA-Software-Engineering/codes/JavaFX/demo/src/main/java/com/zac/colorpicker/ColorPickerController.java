package com.zac.colorpicker;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Slider;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;

public class ColorPickerController {
    @FXML
    public Canvas canvasColorPick;
    public Canvas canvas;
    public Slider sliderColorR;
    public Slider sliderColorG;
    public Slider sliderColorB;

    private Number red = 0;
    private Number green = 0;
    private Number blue = 0;
    private Color color;

    @FXML
    public void clearImage() {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.WHITE);
        gc.fillRect(0,0,canvas.getWidth(),canvas.getHeight());
    }

    private void setColor(){
        GraphicsContext gc = canvasColorPick.getGraphicsContext2D();
        color = Color.rgb(red.intValue(),green.intValue(), blue.intValue());
        gc.setFill(color);
        gc.fillRect(0,0,canvasColorPick.getWidth(),canvasColorPick.getHeight());
    }

    public void initialize(){
        EventHandler<MouseEvent> drawEventHandler =
            new EventHandler<javafx.scene.input.MouseEvent>() {
                @Override
                public void handle(javafx.scene.input.MouseEvent e) {
                    GraphicsContext gc = canvas.getGraphicsContext2D();
                    gc.setFill(color);
                    gc.fillOval(e.getX()-10, e.getY()-10, 20, 20);
                }
            };
        canvas.addEventHandler(javafx.scene.input.MouseEvent.MOUSE_CLICKED, drawEventHandler);

        sliderColorR.valueProperty().addListener((observable, oldValue, newValue) ->
        {
            red = newValue;
            setColor();
        });
        sliderColorG.valueProperty().addListener((observable, oldValue, newValue) ->
        {
            green = newValue;
            setColor();
        });
        sliderColorB.valueProperty().addListener((observable, oldValue, newValue) ->
        {
            blue = newValue;
            setColor();
        });

        clearImage();
        setColor();
    }
}