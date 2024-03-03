public class Carotte extends MetImpl {

    @Override
    public String toString() {
        return "Carotte";
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
        return 40;
    }
    
}
