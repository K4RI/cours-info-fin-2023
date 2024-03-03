package container;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class IntPriorityQueue implements Queue<Integer> {
    private int capacity;
    private int size;
    private Integer[] tableau;
    private Comparator<Integer> c;

    public IntPriorityQueue(int capacity, Comparator<Integer> comparator){
        this.capacity = capacity;
        this.c = comparator;
        this.size = 0;
        this.tableau = new Integer[capacity];
    }

    public static final void swap (Integer[] a, Integer i, Integer j) {
        Integer t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    
    public boolean insertElement(Integer e){
        if (size == capacity){
            Integer[] newTableau = new Integer[capacity+1];
            System.arraycopy(tableau, 0, newTableau, 0, capacity);
            tableau = newTableau;
            capacity++;
        }
        tableau[size] = e;
        int index = size;
        while (c.compare(tableau[(index-1)/2], tableau[index]) < 0) {
            swap(tableau, index, (index-1)/2);
            index = (index-1)/2;
        }
        size++;
        return true;
    }

    public Integer element(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        return tableau[0];
    }

    public Integer popElement(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        Integer popped = tableau[0];
        swap(tableau, 0, size-1); // on supplante le premier élément par le dernier
        tableau[size-1] = null;
        size--;
        int index = 0;
        boolean flag = true;
        while (flag) { // puis on fait descendre ledit "dernier" autant que besoin
            if (2*index+1 > size-1){ // ni fils gauche ni fils droit
                flag = false;
            } else if (2*index+1 == size-1){ // fils gauche mais pas de fils droit
                if (c.compare(tableau[2*index+1], tableau[index])>0){
                    swap(tableau, index, 2*index+1);
                    index = 2*index+1;
                } else {
                    flag = false;}
            } else { // fils gauche et fils droit
                if (c.compare(tableau[2*index+1], Math.max(tableau[2*index+2], tableau[index])) >= 0){
                    swap(tableau, index, 2*index+1);
                    index = 2*index+1;
                } else if (c.compare(tableau[2*index+2], Math.max(tableau[2*index+1], tableau[index])) >= 0) {
                    swap(tableau, index, 2*index+2);
                    index = 2*index+2;
                } else {
                    flag = false;
                }
            }
        }
        return popped;
    }

    public boolean isEmpty(){
        return (size == 0);
    }

    public int size(){
        return size;
    }

    @Override
    public Iterator<Integer> iterator() {
        Integer[] newTableau = new Integer[size];
        System.arraycopy(tableau, 0, newTableau, 0, size);
        return Arrays.stream(newTableau).iterator();
    }


    public static void main(String[] arg) {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(8);
        queue.insertElement(7);
        queue.insertElement(9);
        int p = 1;
        for (Integer x : queue){
            System.out.println(x);
            p *= x;
        }
        System.out.println(p);
    }
}