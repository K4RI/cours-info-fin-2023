import java.util.ArrayList;

public class Counter {
    private int value;
    private ArrayList<CounterListener> listeners;

    public Counter(){
        this.value = 0;
        this.listeners = new ArrayList<CounterListener>();
    }

    public int getValue(){
        return value;
    }

    public void increment(){
        this.value++;
        for (CounterListener x: this.listeners) {x.changed(this);}
    }

    public void addListener(CounterListener v){
        listeners.add(v);
    }

    public void removeListener(CounterListener v){
        listeners.remove(v);
    }

    public static void main(final String[] args){
        final Counter c = new Counter();
        final CounterListener v = new CounterDisplayer();
        /*final CounterListener v = (cc) -> {
            System.out.println(cc.getValue());
        }; */
        c.addListener(v);

        c.increment(); // 1
        c.increment(); // 2
    }
}