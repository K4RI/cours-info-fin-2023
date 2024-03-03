package container;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class GenPriorityQueue<E extends Comparable<E>> implements Queue<E> {
    private int capacity;
    private int size;
    private E[] tableau;
    private Comparator<? super E> c;

    public GenPriorityQueue(int capacity, Comparator<? super E> comparator){
        this.capacity = capacity;
        this.c = comparator;
        this.size = 0;
        this.tableau = (E[]) new Comparable[capacity];
    }

    public static final <E> void swap (E[] a, int i, int j) {
        E t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    
    public boolean insertElement(E e){
        if (size == capacity){
            E[] newTableau = (E[]) new Comparable[capacity+1];
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

    public E element(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        return tableau[0];
    }

    public E popElement(){
        if (this.isEmpty()){
            throw new NoSuchElementException();
        }
        E popped = tableau[0];
        swap(tableau, 0, size-1);
        tableau[size-1] = null;
        size--;
        int index = 0;
        boolean flag = true;
        while (flag) {
            if (2*index+1 > size-1){ // ni fils gauche ni fils droit
                flag = false;
            } else if (2*index+1 == size-1){ // fils gauche mais pas de fils droit
                if (c.compare(tableau[2*index+1], tableau[index]) > 0){
                    swap(tableau, index, 2*index+1);
                    index = 2*index+1;
                } else {
                    flag = false;}
            } else { // fils gauche et fils droit
                if (c.compare(tableau[2*index+1], tableau[2*index+2]) >= 0 && c.compare(tableau[2*index+1], tableau[index]) >= 0){
                    swap(tableau, index, 2*index+1);
                    index = 2*index+1;
                } else if (c.compare(tableau[2*index+2], tableau[2*index+1]) >= 0 && c.compare(tableau[2*index+2], tableau[index]) >= 0){
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
    public Iterator<E> iterator() {
        E[] newTableau = (E[]) new Comparable[size];
        System.arraycopy(tableau, 0, newTableau, 0, size);
        return Arrays.stream(newTableau).iterator();
    }
}