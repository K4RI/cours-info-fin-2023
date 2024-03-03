public abstract class MetDecorator implements Met {
    
    protected Met met;
    public MetDecorator(Met m){
        this.met = m;
    }
    
    // apparemment on doit tout réimplémenter ??
    @Override
    public String toString() {
        return met.toString();
    }

    @Override
    public boolean estSucre() {
        return met.estSucre();
    }

    @Override
    public boolean estSale() {
        return met.estSale();
    }

    @Override
    public boolean estSucreSale() {
        return met.estSucreSale();
    }

    @Override
    public int nombreDeCalories() {
        return met.nombreDeCalories();
    }

    @Override
    public boolean estDietetique() {
        return met.estDietetique();
    }
}
