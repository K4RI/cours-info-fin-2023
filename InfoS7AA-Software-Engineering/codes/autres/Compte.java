
public class Compte {
    private int id;
    private float solde;
    private Personne proprio;

    public Compte(int id, Personne proprio) {
        this.id = id;
        this.solde = 0;
        this.proprio = proprio;
        proprio.addCompte(this);
    }

    public String toString(){
        return String.valueOf(id);
    }
    public Personne getProprio() { return this.proprio; }
    public float getSolde() { return this.solde; }
    public void debiter(float val) {
        this.solde -= val;}    
    public void crediter(float val) {
        this.solde += val;}

    public static void main(String[] args) {
        Personne jej = new Personne("Jej", "Zac");
        Compte c = new Compte(1, jej);       
        System.out.println(c.getProprio());
        System.out.println(jej.getComptes());
        c.crediter((20));
        System.out.println(c.getSolde());
        c.debiter((10));
        System.out.println(c.getSolde());

    }
}

