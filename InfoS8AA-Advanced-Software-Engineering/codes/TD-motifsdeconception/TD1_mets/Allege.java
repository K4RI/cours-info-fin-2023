public class Allege extends MetDecorator {

    public Allege(Met m) {
		super(m);
	}

    @Override
    public String toString() {
        return super.toString() + " allege";
    }

    @Override
    public boolean estDietetique() {
        return true;
    }
    
}
