public class Constante extends Noeud {
    int val;

    public Constante(int val){
        this.val = val;
    }

    public String toString(){
        return String.valueOf(val);
    }

    public int eval(){
        return val;
    }
}