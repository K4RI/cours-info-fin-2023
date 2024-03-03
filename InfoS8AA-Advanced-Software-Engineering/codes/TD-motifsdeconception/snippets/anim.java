package TD_motifsdeconception.snippets;

// https://users.polytech.unice.fr/~buffa/cours/java/javaMINFO96_97/TP4/index.html

// Ces import ne sont pas necessaires � strictement parler, mais ils
// permettent de mentionner les classes directement (MediaTracker au
// lieu de java.awt.MediaTracker)
import java.applet.*;
import java.awt.*;

// Notre class est une extension de Applet puisque c'est une
// applette. Elle implemente quelque chose qui fonctionne, avec un
// debut et une fin.
@SuppressWarnings("deprecation")
public class anim extends Applet implements Runnable {

  MediaTracker MT;
  int index;
  Image im[] = new Image[5];  // Tableau de 5 images
  Thread AnimImages = null;

public void init()
  {
    
    // On declare un nouveau MediaTracker. A priori on en a besoin que
    // d'un seul. Le component utilise est ici l'applet (qui est une
    // classe deriv�e de component) donc on met this.
    MT = new MediaTracker(this); 
    for (int i = 0; i < 5; i++) 
      {
	// On declare une nouvelle image. getImage ne lance pas le
	// chargement de l'image � partir de l'URL. Il associe
	// simplement l'image et l'URL.
	try {
	  im[i] = getImage(getDocumentBase(), "im" + i + ".gif");
	}
	catch (Exception e)
	  {
	    System.out.println("failed loading Image: " 
			       + getDocumentBase() + "im" + i + ".gif");
	  }
	// On ajoute cette image au MediaTracker. On lui donne l'index
	// i, ce qui va permettre de l'identifier de maniere
	// unique. Note: on peut mettre plusieurs images � un m�me
	// index. Cela signifie seulement que les images sont
	// indissociables. Ici, nous voulons que les images soient
	// toutes ind�pendantes les unes des autres.
	MT.addImage(im[i], i);

      }
    // Maintenant, nous pouvons commencer � charger les images. Le
    // true indique que les images doivent se charger.
    MT.checkAll(true);
  }
  
public void start()
  {
    // Si elle n'est pas lanc�e, d�marre la Thread qui va animer les
    // images. La Thread principale va �tre ici seulement pour
    // controler la situation.
    if (AnimImages == null)
      {
	AnimImages = new Thread(this);
	AnimImages.start();
      }
  }
  
public void run()
  {
    // La Thread de base ne fait rien. Elle est la seulement pour
    // attraper le pseudo evenement d'iconification et de lancement
    // (start et stop). La suite n'est donc valable que si la Thread
    // courante est celle de l'animation.
    index = 0;
    // Pour toujours. Mais on peut en sortir par break;
    while (true)
      {
	// ne depassons pas le nombre d'images autoris�.
	if (index >= im.length) 
	  index = 0;
	// Si l'image numero index est charg�e et si il n'y a pas
	// eu d'erreur sur cette image
	if (MT.checkID(index) && !MT.isErrorID(index))
	  // peint la zone qui nous interresse (cad peint l'image)
	  repaint();
	// Dors 100 ms pour que les autres Threads aient le CPU si
	// elles le veulent.
	try { Thread.sleep(100); }
	catch (InterruptedException e)
	  { 
	    // Sort de la boucle while(). Cette exception est
	    // lev�e par AnimImages.stop();
	    break; 
	  }
	// Change d'image
	index++;
      }
  }
  
  
public void stop()
  {
    // arr�te l'animation des images. En fait, envoie une
    // InterruptedException au run() qui tourne.
    if (AnimImages != null)
      {
	AnimImages.stop();
	AnimImages = null;
      }
  }
  
public void paint(Graphics g)
  {
    // affiche l'image en (0,0). Plus simple tu meurs. this est
    // present car la classe anim herite de ImageObserver. Pas tr�s
    // important, c'est une formule magique.
    g.drawImage(im[index], 0, 0, this);
  }
  
public void update(Graphics g)
  {
    // Normalement Update fait clear puis paint. Ici, nous n'avons pas
    // besoin du clear qui donne un espece de flickering (francais
    // ?). Pour voir, essayer de commenter cette fonction.
    paint(g);
  }

public boolean mouseDown(Event e, int x, int y)
  {
    // Cette fonction a �t� rajout� pour �tre gentil avec les
    // ressources de la machine. Un pression de souris arr�te
    // l'animation (comme stop()), une pression de souris la
    // red�marre.
    if (AnimImages != null)
      {
	AnimImages.stop();
	AnimImages = null;
      }
    else
      {
	AnimImages = new Thread(this);
	AnimImages.start();
      }
    return(true);
  } 
}
