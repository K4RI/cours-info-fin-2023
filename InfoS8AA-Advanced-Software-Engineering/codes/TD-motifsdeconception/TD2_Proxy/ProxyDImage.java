import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import javax.swing.border.*;
import java.util.Date;
import java.util.*;

// herite de JPanel et implemente Runnable
class ProxyDImage extends JPanel implements Runnable, ActionListener{

	private MediaTracker monTracker;
	private Image img;
	private int width;
	private int height;
	private String imageName;
	private Thread temporisateur;
	private JFrame maFrame; // la "Frame" dans laquelle on se trouve

	// 2 parametres : le nom et la "Frame" utilise
	public ProxyDImage(String monNom, JFrame tempFrame) {
		System.out.println("proxy cree");
		// la "Frame" dans laquelle on est
		maFrame = tempFrame;
		// le nom de l'image
		imageName = monNom;
		
		setLayout(new GridBagLayout());
		EmptyBorder eb = new EmptyBorder(5, 5, 5, 5);
		setBorder(new CompoundBorder(eb, new BevelBorder(BevelBorder.LOWERED)));
		Font font = new Font("serif", Font.PLAIN, 10);

	}
	public void start() {
		System.out.println("temporisateur demarre");
		// nouveau temporisateur: un Thread
		temporisateur = new Thread(this);
		// on le demarre
		temporisateur.start();
	}

	public synchronized void stop() {
		if (temporisateur != null) {
			temporisateur.interrupt();
		}
		temporisateur = null;
		notifyAll();
	}

	public void run() {
		System.out.println("running");
		// Dans la methode run on initialise le MediaTracker
		monTracker = new MediaTracker(this);

		// on charge l'image (voir dans Toolkit, getDefaultToolkit la methode getImage()
		img = Toolkit.getDefaultToolkit().getImage(imageName);
		System.out.println(imageName + " : " + img.getWidth(this)); // ???
		System.out.println(imageName + " : " + img.getWidth(this)); // ???
		// apparemment ça marche pas sans ces lignes ???
		width = img.getWidth(this);
		height = img.getHeight(this);

		// on ajoute l'image au "MediaTracker" avec l'ID 0
		monTracker.addImage(img, 0);
		try {
			//on attend le chargement de l'image
			monTracker.waitForID(0);
		} catch (InterruptedException e) {
			System.out.println("erreur");
		}
		System.out.println("L'image est " + img.getHeight(this));
	}

	public void paint(Graphics g) {
		// l'image a ete chargee
		System.out.println("painting");
		if (monTracker != null && monTracker.checkID(0)){// on verifie que l'image n'a pas ete chargee dans le MediaTracker
			System.out.println("L'image est en train de charger");
			// mettre la couleur de fond en "lightGray"
			maFrame.setBackground(Color.LIGHT_GRAY); // là c bon
			// un rectangle gris
			g.setColor(Color.GRAY);
			g.fillRect(0, 0, width, height);
			// on dessine l'image
			g.drawImage(img, 0, 0, width, height, null);

		} else {
			// image est en attente
			System.out.println("L'image est en attente");
			// Couleur Magenta
			g.setColor(Color.magenta);
			// Rectangle plein
			g.fillRect(0, 0, width, height);
			// rectangle rouge et deux lignes rouges en forme de croix
			g.setColor(Color.RED);
			g.drawRect(0, 0, width, height);
			g.drawLine(0, 0, width, height);
			g.drawLine(0, height, width, 0);
		}
	}

	public void actionPerformed(ActionEvent e) {
		String composant = e.getActionCommand();
    	System.out.println("Action sur le composant : " + composant);

        maFrame.getContentPane().remove((Component) e.getSource());
        maFrame.getContentPane().revalidate();
        maFrame.add(this);
		start();
	}
}

