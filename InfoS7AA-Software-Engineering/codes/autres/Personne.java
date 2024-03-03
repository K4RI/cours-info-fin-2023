import java.util.ArrayList;
import java.util.List;

public class Personne {
    private String nom;
    private String prenom;
    private ArrayList<Compte> comptes;

    public Personne(String nom, String prenom) {
        this.nom = nom;
        this.prenom = prenom;
        this.comptes = new ArrayList<>();
    }

    public String toString(){
        return nom + " " + prenom;
    }

    public void addCompte(Compte c) {
        comptes.add(c);
    }
    public List<Compte> getComptes(){return this.comptes;}
}