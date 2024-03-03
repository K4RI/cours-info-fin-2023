public class Sucre extends MetImpl {

    @Override
    public String toString() {
        return "Sucre";
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
        return 400;
    }
    
}
