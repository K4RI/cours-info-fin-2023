public class Framboise extends MetImpl {

    @Override
    public String toString() {
        return "Framboise";
    }

    @Override
    public boolean estSucre() {
        return true;
    }

    @Override
    public boolean estSale() {
        return false;
    }

    @Override
    public int nombreDeCalories() {
        return 50;
    }
    
}
