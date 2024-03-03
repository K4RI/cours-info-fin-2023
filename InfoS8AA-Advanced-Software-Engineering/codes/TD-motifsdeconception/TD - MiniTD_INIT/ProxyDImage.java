import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import javax.swing.border.*;
import java.util.Date;
import java.util.*;

// h�rite de JPanel et impl�mente Runnable
class ProxyDImage //

	private MediaTracker monTracker;
	private Image img;
	private int width;
	private int height;
	private String imageName;
	private Thread temporisateur;
	private JFrame maFrame; // la "Frame" dans laquelle on se trouve

	// 2 param�tres : le nom et la "Frame" utilis�
	public ProxyDImage(String monNom, JFrame tempFrame) {
		System.out.println("proxy cr��");
		// la "Frame" dans laquelle on est
		// le nom de l'image
		
		setLayout(new GridBagLayout());
		EmptyBorder eb = new EmptyBorder(5, 5, 5, 5);
		setBorder(new CompoundBorder(eb, new BevelBorder(BevelBorder.LOWERED)));
		Font font = new Font("serif", Font.PLAIN, 10);

	}
	public void start() {
		System.out.println("temporisateur demarre");
		// nouveau temporisateur: un Thread
		// on le d�marre
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
		// Dans la m�thode run on initialise le MediaTracker
		// on charge l'image (voir dans Toolkit, getDefaultToolkit la m�thode getImage()
		img = //;
		System.out.println("L'image est" + img.getHeight(this));
		// on ajoute l'imahe au "MediaTracker" avec l'ID 0
		try {
			on attend le chargement de l'image
		} catch (InterruptedException e) {
			System.out.println("erreur");
		}
		System.out.println("L'image est" + img.getHeight(this));
	}

	public void paint(Graphics g) {

		// l'image a ete chargee
		System.out.println("painting");
		if (// on v�rifie que l'image n' pas �t� charg�e dans le MediaTracker
			System.out.println("L'image est en train de charger");
			// mettre la couleur de fond en "lightGray"
			// un rectangle gris�
			// on dessine l'image

		} else {
			// image est en attente
			System.out.println("L'image est en attente");

			// Couleur Magenta
			// Rectangle plein
			// rectangle rouge et deux lignes rouges en forme de croix
		}

	}

	public void actionPerformed(ActionEvent e) {
		//System.out.println("action!");
		//start();
	}

}

