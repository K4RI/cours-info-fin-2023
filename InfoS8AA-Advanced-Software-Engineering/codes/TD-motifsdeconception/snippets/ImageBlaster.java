package TD_motifsdeconception.snippets;

// https://docs.oracle.com/javase%2F7%2Fdocs%2Fapi%2F%2F/java/awt/MediaTracker.html

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.Color;
import java.awt.Component;
import java.awt.Image;
import java.awt.Graphics;
import java.awt.MediaTracker;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

@SuppressWarnings("deprecation")
public class ImageBlaster extends JPanel implements Runnable, ActionListener {
    MediaTracker tracker;
    Image bg;
    Image anim[] = new Image[5];
    int index;
    Thread animator;
    JFrame frame;

    // Get the images for the background (id == 0)
    // and the animation frames (id == 1)
    // and add them to the MediaTracker
    public ImageBlaster(JFrame jframe) throws IOException {
        frame = jframe;
        tracker = new MediaTracker(this);
        bg = ImageIO.read(new File("TD-MiniTD/tests/images/background.gif"));
        tracker.addImage(bg, 0);
        for (int i = 0; i < 5; i++) {
            anim[i] = ImageIO.read(new File("TD-MiniTD/tests/images/anim"+i+".gif"));
            tracker.addImage(anim[i], 1);
        }
    }

    // Start the animation thread.
    public void start() {
        animator = new Thread(this);
        animator.start();
    }

    // Stop the animation thread.
    public void stop() {
        animator = null;
    }

    // Run the animation thread.
    // First wait for the background image to fully load
    // and paint.  Then wait for all of the animation
    // frames to finish loading. Finally, loop and
    // increment the animation frame index.
    public void run() {
        System.out.println("debut attente...");
        try {
            tracker.waitForID(0);
            tracker.waitForID(1);
        } catch (InterruptedException e) {
            return;
        }
        System.out.println("fin attente...");
        Thread me = Thread.currentThread();
        while (animator == me) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                break;
            }
            synchronized (this) {
                index++;
                if (index >= anim.length) {
                    index = 0;
                }
            }
            repaint();
        }
    }

    // The background image fills the frame so we
    // don't need to clear the applet on repaints.
    // Just call the paint method.
    public void update(Graphics g) {
        paint(g);
    }

    // Paint a large red rectangle if there are any errors
    // loading the images.  Otherwise always paint the
    // background so that it appears incrementally as it
    // is loading.  Finally, only paint the current animation
    // frame if all of the frames (id == 1) are done loading,
    // so that we don't get partial animations.
    public void paint(Graphics g) {
        if ((tracker.statusAll(false) & MediaTracker.ERRORED) != 0) {
            g.setColor(Color.red);
            g.fillRect(0, 0, size().width, size().height);
            return;
        }
        g.drawImage(bg, 0, 0, this);
        if (tracker.statusID(1, false) == MediaTracker.COMPLETE) {
            g.drawImage(anim[index], 10, 10, this);
        }
    }    

	public void actionPerformed(ActionEvent e) {
		String composant = e.getActionCommand();

    	System.out.println("Bouton appuye : " + composant);

        // on enlève le bouton pour le panel
        frame.getContentPane().remove((Component) e.getSource());
        frame.getContentPane().revalidate();
        // qui va se paint() lors de l'ajout
        frame.add(this);
        // puis le start, qui va start le Thread, càd run() le Runnable
		start();
	}

    public static void main(String[] args) throws IOException {
        System.out.println("Demarrage");
        JFrame maFrame = new JFrame("Exemple");
        maFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int WIDTH = 800, HEIGHT = 600;
        maFrame.setSize(WIDTH, HEIGHT);
        maFrame.setVisible(true);
        
        ImageBlaster imageBlaster = new ImageBlaster(maFrame);
        JButton b = new JButton("Cliquer");
        b.addActionListener(imageBlaster);
        maFrame.getContentPane().add(b);
        maFrame.setVisible(true);
    }
}
