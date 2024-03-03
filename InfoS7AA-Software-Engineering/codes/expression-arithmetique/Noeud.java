public abstract class Noeud {
    public abstract int eval();
    
    public static void main(String[] args) {
        Noeud expr = new Multiplication(new Constante(7), new Addition(new Constante(5), new Constante(3)));
        System.out.println(expr);
        System.out.println(expr.eval());
    }
}