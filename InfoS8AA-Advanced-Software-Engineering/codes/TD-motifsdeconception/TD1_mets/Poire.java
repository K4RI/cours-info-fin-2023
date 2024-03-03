public class Poire extends MetImpl {

    @Override
    public String toString() {
        return "Poire";
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
        return 60;
    }
    
}
