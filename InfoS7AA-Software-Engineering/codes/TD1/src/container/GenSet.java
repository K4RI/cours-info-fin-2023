package container;

import java.util.Arrays;
import java.util.Iterator;

public class GenSet<E extends Comparable<E>> implements SetContainer<E> {
    private int size;
    private E racine;
    private GenSet<E> filsGauche;
    private GenSet<E> filsDroit;

    public GenSet(){
        this.racine = null;
        this.size = 0;
        this.filsGauche = null;
        this.filsDroit = null;
    }
    
    @Override
    public boolean insertElement(E e) {
        if (racine == null){
            racine = e;
        } else if (e.compareTo(racine) < 0){
            if (filsGauche != null){
                filsGauche.insertElement(e);
            } else {
                filsGauche = new GenSet<E>();
                filsGauche.insertElement(e);
            }
        } else {
            if (filsDroit != null){
                filsDroit.insertElement(e);
            } else {
                filsDroit = new GenSet<E>();
                filsDroit.insertElement(e);
            }
        }
        size++;
        return true;
    }

    @Override
    public boolean contains(E e) {
        if (racine == null){ // arbre vide
            return false;
        
        } else if (e == racine){
            return true;
        
        } else if (e.compareTo(racine) < 0){ // plus petit donc à gauche
            if (filsGauche == null){
                return false;
            } else return filsGauche.contains(e);
        
        } else if (e.compareTo(racine) > 0){ // plus grand donc à droite
            if (filsDroit == null){
                return false;
            } else return filsDroit.contains(e);
        
        } else if (filsGauche == null){ // de même priorité, on cherche des deux côtés
            if (filsDroit == null){
                return false;
            } else return filsDroit.contains(e);
        } else if (filsDroit == null){
            return filsGauche.contains(e);
        } return filsGauche.contains(e) || filsDroit.contains(e);
    }

    @Override
    public boolean isEmpty() {
        return (size == 0);
    }

    @Override
    public int size() {
        return size;
    }
    

    private E[] itarr() {
        E[] arr = (E[]) new Comparable[size];
        if (filsGauche != null){
            System.arraycopy(filsGauche.itarr(), 0, arr, 0, filsGauche.size());
            arr[filsGauche.size()] = racine;
        } else if (!this.isEmpty()) { arr[0] = racine; }
        
        if (filsDroit != null){
            System.arraycopy(filsDroit.itarr(), 0, arr, size - filsDroit.size(), filsDroit.size());
        }

        return arr;
    }

    @Override
    public Iterator<E> iterator() {
        return Arrays.stream(this.itarr()).iterator();
    }

    public static void main(String[] arg) {
        GenSet<Integer> tree = new GenSet<Integer>();
        tree.insertElement(5);
        tree.insertElement(3);
        tree.insertElement(2);
        tree.insertElement(4);
        tree.insertElement(1);
        // int count = 1;
        for (Integer x : tree){
            System.out.println(x);
        }
    }
}