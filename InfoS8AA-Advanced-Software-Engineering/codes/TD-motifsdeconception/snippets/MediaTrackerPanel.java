package TD_motifsdeconception.snippets;
import java.awt.*;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class MediaTrackerPanel extends JPanel {

    Image img;
    int largeurImage;
    int hauteurImage;

    public MediaTrackerPanel(String src) throws IOException {
        MediaTracker m = new MediaTracker(this);        
        img=ImageIO.read(new File(src));
        m.addImage(img,0);
        try {
            m.waitForID(0);
        } catch (InterruptedException e) {}   
        largeurImage=img.getWidth(this);
        hauteurImage=img.getHeight(this);
    }

    public void ligne(Graphics g, int y) {
        int x=0;
        while (x<getSize().width) {
            g.drawImage(img,x,y,this);
            x=x+10;
        }
    }

    public void paint(Graphics g) {
        if (img!=null) {
            int y=0;
            while (y<getSize().height) {
                ligne(g,y);
                y=y+10;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Demarrage");
		JFrame maFrame = new JFrame("Exemple");
        maFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		int WIDTH = 800, HEIGHT = 600;
		maFrame.setSize(WIDTH, HEIGHT);
		maFrame.setVisible(true);
        String src = "TD-MiniTD/Images/anim0.jpg";
        //Image image = ImageIO.read(new File(src));
        maFrame.getContentPane().add(new MediaTrackerPanel(src));
		maFrame.setVisible(true);
    }
}

