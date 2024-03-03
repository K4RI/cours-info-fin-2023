package container;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.NoSuchElementException;

public class TestIntFIFO {
    @Test
    public void test_emptyCreation() {
        IntFIFO queue = new IntFIFO(10);
        assertTrue(queue.isEmpty() );
        assertEquals(queue.size(), 0);
    }
    
    @Test
    public void test_oneElement() {
        IntFIFO queue = new IntFIFO(10);
        queue.insertElement(7);
        assertFalse(queue.isEmpty() );
        assertEquals(queue.size(), 1);
        assertEquals(queue.element(), (Integer) 7);
    }
    
    @Test
    public void test_popElement() {
        IntFIFO queue = new IntFIFO(10);
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        assertEquals(queue.size(), 3);
        assertEquals(queue.popElement(), (Integer) 7);
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 9);
        assertTrue(queue.isEmpty() );
        assertThrows(NoSuchElementException.class, () -> {
            queue.popElement();});
        assertThrows(NoSuchElementException.class, () -> {
            queue.element();});
    }
    
    @Test
    public void test_fullCapacity() {
        IntFIFO queue = new IntFIFO(3);
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        queue.insertElement(10);
        assertEquals(queue.size(), 4);
        queue.popElement();
        assertEquals(queue.popElement(), (Integer) 8);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 10);
    }
    
    @Test
    public void test_circularBuffer() {
        IntFIFO queue = new IntFIFO(10);
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        queue.popElement();
        queue.popElement();
        queue.insertElement(10);
        assertEquals(queue.size(), 2);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 10);
    }
    
    @Test
    public void test_circularBufferFullCapacity() {
        IntFIFO queue = new IntFIFO(3);
        queue.insertElement(7);
        queue.insertElement(8);
        queue.insertElement(9);
        queue.popElement();
        queue.popElement();
        queue.insertElement(10);
        queue.insertElement(11);
        queue.insertElement(12);
        assertEquals(queue.popElement(), (Integer) 9);
        assertEquals(queue.popElement(), (Integer) 10);
        assertEquals(queue.popElement(), (Integer) 11);
        assertEquals(queue.popElement(), (Integer) 12);
    }
}