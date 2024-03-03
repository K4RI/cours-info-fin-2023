public class ArbreBinaire {
    public static class Noeud{
        int val;
        Noeud gauche;
        Noeud droite;
        public Noeud(int data){    
            this.val = data;
            this.gauche = null;    
            this.droite = null;    
            }
        public String toString(){
            if (gauche == null){
                if (droite == null){
                    return String.valueOf(val);
                } else {
                    return "{" + String.valueOf(val) + ", X, " + this.droite + "}";
                }                
            } else {
                if (droite == null){
                    return "{" + String.valueOf(val) + ", " + this.gauche + ", X}";
                } else {
                    return "{" + String.valueOf(val) + ", " + this.gauche + ", " + this.droite + "}";
                }
            }
        }
    }

    public Noeud racine;
    public ArbreBinaire(int val) {
        this.racine = new Noeud(val);
    }
    public String toString(){
        return racine.toString();
    }

    public void insert(int val){
        insert_rec(racine, val);
    }

    public void insert_rec(Noeud noeud, int val){
        if (val < noeud.val){
            if (noeud.gauche != null){
                insert_rec(noeud.gauche, val);
            } else {
                noeud.gauche = new Noeud(val);
            }
        } else {
            if (noeud.droite != null){
                insert_rec(noeud.droite, val);
            } else {
                noeud.droite = new Noeud(val);
            }
        }
    }

    public static void main(String[] args){
        ArbreBinaire abr = new ArbreBinaire(25);
        System.out.println(abr);
        abr.insert(11);
        abr.insert(15);
        abr.insert(16);
        abr.insert(23);
        abr.insert(79);
        System.out.println(abr);
    }
}