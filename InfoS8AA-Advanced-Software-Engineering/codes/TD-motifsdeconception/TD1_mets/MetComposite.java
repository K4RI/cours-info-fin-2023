import java.util.ArrayList;

public class MetComposite extends MetImpl {

    private ArrayList<Met> ingredients = new ArrayList<Met>();

    public void ajouter(Met met) {
        ingredients.add(met);
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder("{");
        for (Met met : ingredients) {
            s.append(met.toString() + " + ");
        }
        s.setLength(s.length() - 3);
        s.append("}");
        return s.toString();
    }

    @Override
    public boolean estSucre() {
        for (Met met : ingredients) {
            if (met.estSucre()) {
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean estSale() {
        for (Met met : ingredients) {
            if (met.estSale()) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int nombreDeCalories() {
        int sum = 0;
        for (Met met : ingredients) {
            sum += met.nombreDeCalories();
        }
        return sum;
    }
}
