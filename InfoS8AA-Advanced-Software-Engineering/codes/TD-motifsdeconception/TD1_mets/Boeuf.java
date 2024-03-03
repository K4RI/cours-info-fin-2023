public class Boeuf extends MetImpl {

    @Override
    public String toString() {
        return "Boeuf";
    }

    @Override
    public boolean estSucre() {
        return false;
    }

    @Override
    public boolean estSale() {
        return true;
    }

    @Override
    public int nombreDeCalories() {
        return 250;
    }
    
}
