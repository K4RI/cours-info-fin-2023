public class Sel extends MetImpl {

    @Override
    public String toString() {
        return "Sel";
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
        return 0;
    }
    
}
