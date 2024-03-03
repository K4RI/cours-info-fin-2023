package TD_motifsdeconception.snippets;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

class MyCanvas extends Canvas {
    Image iImageCanvas;
    int nNumeroCanvas;
    int nLong;
    int nLarg;

    public MyCanvas(Image i, int n, int nlong, int nlarg) {
        iImageCanvas = i;
        nNumeroCanvas = n;
        nLong = nlong;
        nLarg = nlarg;
    }

    public MyCanvas(int longueur, int larg) {
	nLong = longueur;
	nLarg = larg;
    }

    public void paint(Graphics g) {
        g.drawImage(iImageCanvas, 0, 0, nLong, nLarg, this);
    }

    public Dimension minimumSize() {
        return new Dimension(nLong,nLarg);
    }

    public Dimension preferredSize() {
        return minimumSize();
    }
}

class MyPanel extends Panel implements ActionListener {
    JRadioButton cbPanel;
    MyCanvas mcPanel;
    int nPanel;
    MyCanvas mcTracker;

    public MyPanel(Image i, int n, String s, MyCanvas mc, int nlong, int nlarg) {
	setLayout(new GridLayout(2,1));
	nPanel = n;
    mcPanel = new MyCanvas(i, n, nlong, nlarg);
	cbPanel = new JRadioButton(s);
	mcTracker = mc;
	add(mcPanel);
    add(cbPanel);
    cbPanel.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() instanceof JRadioButton) 
        {
	        System.out.println("CheckBox " + nPanel + " appuye : " +
            cbPanel.getActionCommand());
            mcTracker.iImageCanvas = mcPanel.iImageCanvas;
            mcTracker.repaint();
        } 
    } 
}

public class ButtonsTracker extends JPanel
{
    MediaTracker MT;

    public ButtonsTracker() {
        Image iImage[] = new Image[5];  // Tableau de 5 images
        MyCanvas mcTracker = new MyCanvas(300, 300);
        String sImage = "TD-MiniTD/tests/images/anim";
        int nNbImage = 5;

        addItem("Nom: "+sImage+"\n"+"Nombre: "+nNbImage);
	
        // On declare un nouveau MediaTracker. A priori on en a besoin que
        // d'un seul. Le component utilise est ici l'applet (qui est une
        // classe deriv�e de component) donc on met this.
        MT = new MediaTracker(this);
        ButtonGroup buttonGroup = new ButtonGroup();
        for (int i = 0; i < nNbImage; i++) 
        {
            // On declare une nouvelle image. getImage ne lance pas le
            // chargement de l'image � partir de l'URL. Il associe
            // simplement l'image et l'URL.
            try {
                iImage[i] = ImageIO.read(new File(sImage + i + ".gif"));
                if(iImage[i] != null)
                    addItem("getImage de "+ sImage + i + ".gif");
            }

            catch (Exception e) {
                addItem("Echec de getImage, " + sImage + i + ".gif");
            }
            // On ajoute cette image au MediaTracker. On lui donne l'index
            // i, ce qui va permettre de l'identifier de maniere
            // unique. Note: on peut mettre plusieurs images � un m�me
            // index. Cela signifie seulement que les images sont
            // indissociables. Ici, nous voulons que les images soient
            // toutes ind�pendantes les unes des autres.
            MT.addImage(iImage[i], i);
            MyPanel p = new MyPanel(iImage[i], i, "Image" + i + ".gif", mcTracker, 75, 75);
            buttonGroup.add(p.cbPanel);
 	        add(p);
        }
        // Maintenant, nous pouvons commencer � charger les images. Le
        // true indique que les images doivent se charger.
        MT.checkAll(true);
 
	    add(mcTracker);
        setVisible(true);
        addItem("initializing...");
    }

    public void start() {
        addItem("starting...");
    }

    public void stop() {
        addItem("stopping...");
    }

    public void destroy() {
        addItem("preparing for unloading...");
    }
    
    public void addItem(String newWord) {
        System.out.println(newWord);
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Demarrage");
        JFrame maFrame = new JFrame("Exemple");
        maFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int WIDTH = 800, HEIGHT = 600;
        maFrame.setSize(WIDTH, HEIGHT);
        maFrame.setVisible(true);
        
        ButtonsTracker track = new ButtonsTracker();
        /*JButton b = new JButton("Cliquer");
        b.addActionListener(track);
        maFrame.getContentPane().add(b); */
        maFrame.getContentPane().add(track);

        maFrame.setVisible(true);
    }
}

