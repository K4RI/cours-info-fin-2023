public class Veau extends MetImpl {

    @Override
    public String toString() {
        return "Veau";
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
        return 150;
    }
    
}
