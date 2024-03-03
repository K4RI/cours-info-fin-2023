import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import javax.swing.border.*;
import java.util.Date;
import java.util.*;


public class MainProxy {

	public static void main(String[] args) {
		System.out.println("Demarrage");
		JFrame maFrame = new JFrame("TD Design Patterns");
		int WIDTH = 800, HEIGHT = 600;
		maFrame.setSize(WIDTH, HEIGHT);

		//exemple avec un bouton
		JButton monBouton = new JButton("toto");
		maFrame.getContentPane().add(monBouton);
		maFrame.setVisible(true);
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
		}
		maFrame.getContentPane().removeAll();

		// on charge un proxy d'image
		
		maFrame.getContentPane().setLayout(new BorderLayout());
		maFrame.getContentPane().add(// � compl�ter );
		maFrame.setVisible(true);
		//on d�marre le proxy

		System.out.println("Exit");
	}

}
