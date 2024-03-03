package container;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;

public class TestGenSet {
    @Test
    public void test_emptyCreation() {
        GenSet<Integer> tree = new GenSet<Integer>();
        assertTrue(tree.isEmpty());
        assertEquals(tree.size(), 0);
    }
    
    @Test
    public void test_contains() {
        GenSet<Integer> tree = new GenSet<Integer>();
        tree.insertElement(7);
        tree.insertElement(8);
        tree.insertElement(9);
        assertFalse(tree.isEmpty() );
        assertEquals(tree.size(), 3);
        assertTrue(tree.contains(7));
        assertTrue(tree.contains(8));
        assertTrue(tree.contains(9));
    }
    
    @Test
    public void test_containsString() {
        GenSet<String> tree = new GenSet<String>();
        tree.insertElement("hello");
        tree.insertElement("helli");
        tree.insertElement("hellu");
        assertFalse(tree.isEmpty() );
        assertEquals(tree.size(), 3);
        assertTrue(tree.contains("hello"));
        assertTrue(tree.contains("helli"));
        assertTrue(tree.contains("hellu"));
    }
    
    @Test
    public void test_iterator() {
        GenSet<Integer> tree = new GenSet<Integer>();
        tree.insertElement(5);
        tree.insertElement(7);
        tree.insertElement(3);
        tree.insertElement(6);
        tree.insertElement(2);
        tree.insertElement(8);
        tree.insertElement(4);
        tree.insertElement(9);
        tree.insertElement(1);
        int count = 1;
        for (Integer x : tree){
            assertEquals(x, count);
            count++;
        }        
    }
}