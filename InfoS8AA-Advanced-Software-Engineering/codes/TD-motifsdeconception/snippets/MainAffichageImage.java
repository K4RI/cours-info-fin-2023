package TD_motifsdeconception.snippets;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MainAffichageImage {    
    public static void main(String[] args){
        System.out.println("Demarrage");
		JFrame maFrame = new JFrame("Exemple");
        maFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		int WIDTH = 800, HEIGHT = 600;
		maFrame.setSize(WIDTH, HEIGHT);
		maFrame.setVisible(true);
        String src = "TD-MiniTD/Images/anim0.jpg";
        //Image image = ImageIO.read(new File(src));
        ImageIcon icone = new ImageIcon(src);
        maFrame.getContentPane().add(new JLabel(icone));
		maFrame.setVisible(true);
    }
}