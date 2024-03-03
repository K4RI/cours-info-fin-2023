public class CounterDisplayer implements CounterListener {
    @Override
    public void changed(final Counter c){
        System.out.println(c.getValue());
    }
}