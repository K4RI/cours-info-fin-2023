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
        maFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		int WIDTH = 800, HEIGHT = 600;
		// int WIDTH = 1200, HEIGHT = 700;
		maFrame.setSize(WIDTH, HEIGHT);

		/*
		//exemple avec un bouton
		JButton monBouton = new JButton("toto");
		maFrame.getContentPane().add(monBouton);
		maFrame.setVisible(true);
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
		}
		maFrame.getContentPane().removeAll();
        maFrame.getContentPane().revalidate(); //
		*/

		// on charge un proxy d'image
		// String fileName = "anim0.jpg";
		// String fileName = "anim1.jpg";
		// String fileName = "Collines.jpg";
		// String fileName = "Coucher de soleil.jpg";
		String fileName = "Hiver.jpg";
		// String fileName = "Nénuphars.jpg";
		ProxyDImage monProxy = new ProxyDImage("Images/" + fileName, maFrame);
		// monBouton.addActionListener(monProxy);

		maFrame.getContentPane().setLayout(new BorderLayout());
		maFrame.getContentPane().add(monProxy);		
		maFrame.setVisible(true);
		
		//on demarre le proxy
		monProxy.start();

		System.out.println("Exit");
	}

}
