public class Chocolat extends MetImpl {

    @Override
    public String toString() {
        return "Chocolat";
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
        // une tablette de chocolat noir
        return 500;
    }
    
}
