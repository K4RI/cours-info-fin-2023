package container;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class IntFIFO implements Queue<Integer> {
    private int capacity;
    private int size;
    private int begin;
    private Integer[] tableau;

    public IntFIFO(int capacity){
        this.capacity = capacity;
        this.size = 0;
        this.begin = 0;
        this.tableau = new Integer[capacity];
    }
    
    public boolean insertElement(Integer e){
        if (size == capacity){
            Integer[] oldTableau = Arrays.copyOf(tableau, capacity);
            tableau = new Integer[capacity+1];
            System.arraycopy(oldTableau, 0, tableau, 0, begin);
            System.arraycopy(oldTableau, begin, tableau, begin+1, capacity-begin);
            capacity++;
            begin++;
        }
        tableau[(begin+size)%capacity] = e;
        size++;
        return true;
    }

    public Integer element(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        return tableau[begin];
    }

    public Integer popElement(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        Integer popped = tableau[begin];
        tableau[begin] = null;
        size--;
        begin = (begin+1)%capacity;
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
        return null;
    }
}