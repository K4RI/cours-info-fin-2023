public class Addition extends NoeudBinaire {
    public Addition(Noeud n1, Noeud n2) {
        super(n1, n2);
    }

    public String toString(){
        return "(" + n1.toString() + "+" + n2.toString() + ")";
    }

    public int eval(){
        return n1.eval()+n2.eval();
    }
}