package container;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.Comparator;
import java.util.NoSuchElementException;

public class TestIntPriorityQueue {
    @Test
    public void test_emptyCreation() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        assertTrue(queue.isEmpty() );
        assertEquals(queue.size(), 0);
    }
    
    @Test
    public void test_oneElement() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(7);
        assertFalse(queue.isEmpty() );
        assertEquals(queue.size(), 1);
        assertEquals(queue.element(), (Integer) 7);
    }
    
    @Test
    public void test_popElement() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        assertEquals(queue.size(), 3);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 7);
        assertTrue(queue.isEmpty() );
        assertThrows(NoSuchElementException.class, () -> {
            queue.popElement();});
        assertThrows(NoSuchElementException.class, () -> {
            queue.element();});
    }
    
    @Test
    public void test_fullCapacity() {
        IntPriorityQueue queue = new IntPriorityQueue(3, Comparator.naturalOrder());
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        queue.insertElement(10);
        assertEquals(queue.size(), 4);
        assertEquals(queue.popElement(), (Integer) 10);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 7);
    }
    
    @Test
    public void test_popElement2() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(13);
        queue.insertElement(17);
        queue.insertElement(12);
        queue.insertElement(18);
        queue.insertElement(15);
        queue.insertElement(11);
        queue.insertElement(16);
        queue.insertElement(14);
        queue.insertElement(19);
        assertEquals(queue.size(), 9);
        assertEquals(queue.popElement(), (Integer) 19);
        assertEquals(queue.popElement(), (Integer) 18);
        assertEquals(queue.popElement(), (Integer) 17);
        assertEquals(queue.popElement(), (Integer) 16);
        assertEquals(queue.popElement(), (Integer) 15);
        assertEquals(queue.popElement(), (Integer) 14);
        assertEquals(queue.popElement(), (Integer) 13);
        assertEquals(queue.popElement(), (Integer) 12);
        assertEquals(queue.popElement(), (Integer) 11);
    }
    
    @Test
    public void test_sameValues() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(9);
        queue.insertElement(8);
        queue.insertElement(8);
        queue.insertElement(7);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 7);
        assertTrue(queue.isEmpty() );
        assertThrows(NoSuchElementException.class, () -> {
            queue.popElement();});
        assertThrows(NoSuchElementException.class, () -> {
            queue.element();});
    }
    
    @Test
    public void test_iterator() {
        IntPriorityQueue queue = new IntPriorityQueue(10, Comparator.naturalOrder());
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        int p = 1;
        for (Integer x : queue){
            p *= x;
        }
        assertEquals(p, 504);
    }
    
    @Test
    public void test_comparator() {
        class InvComparator<T extends Comparable<T>> implements Comparator<T> {
            public int compare(T o1, T o2) {
                return -o1.compareTo(o2);
            }
        }

        IntPriorityQueue queue = new IntPriorityQueue(10, new InvComparator<Integer>());
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        assertEquals(queue.size(), 3);
        assertEquals(queue.popElement(), (Integer) 7);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 9);

    }
}