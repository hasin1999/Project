package PriorityQueue;

import org.junit.Test;
import java.util.Comparator;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertEquals;

// Unit tests for the PriorityQueue class
public class PriorityQueueTest {
    private PriorityQueue<Integer> queue;

    // Test the empty() method
    @Test
    public void testEmpty() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestEmpty()");
        assertTrue(queue.empty());
    }

    // Test the push() method
    @Test
    public void testPush() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestPush()");
        queue.push(10);
        assertFalse(queue.empty());
        assertTrue(queue.contains(10));
    }

    // Test pushing multiple elements
    @Test
    public void testPushMultiple() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestPushMultiple()");
        queue.push(7);
        queue.push(3);
        queue.push(12);
        queue.push(1);
        assertFalse(queue.contains(5));
        assertTrue(queue.contains(3));
    }

    // Test the contains() method
    @Test
    public void testContains() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestContains()");
        queue.push(15);
        queue.push(20);
        queue.push(5);
        assertTrue(queue.contains(15));
        assertTrue(queue.contains(5));
    }

    // Test the pop() method
    @Test
    public void testPop() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestPop()");
        queue.push(8);
        queue.pop();
        assertTrue(queue.empty());
    }

    // Test popping multiple elements
    @Test
    public void testPopMultiple() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestPopMultiple()");
        queue.push(9);
        queue.push(4);
        queue.push(6);
        queue.push(2);
        queue.pop();
        assertTrue(queue.contains(9));
        assertTrue(queue.contains(6));
        assertTrue(queue.contains(4));
        assertFalse(queue.contains(2));
    }

    // Test the remove() method
    @Test
    public void testRemove() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestRemove()");
        queue.push(11);
        queue.push(3);
        queue.remove(11);
        assertTrue(queue.contains(3));
        assertFalse(queue.contains(11));
    }

    // Test removing multiple elements
    @Test
    public void testRemoveMultiple() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestRemoveMultiple()");
        queue.push(14);
        queue.push(7);
        queue.remove(14);
        queue.remove(7);
        assertTrue(queue.empty());
    }

    // Test pushing, removing, and retrieving the top element
    @Test
    public void testPushRemoveTop() {
        queue = new PriorityQueue<>(new ComparInt());
        System.out.print("\ntestPushRemoveTop()");
        queue.push(13);
        queue.push(4);
        queue.push(10);
        queue.push(2);
        queue.push(8);
        queue.remove(4);
        assertEquals(queue.top().intValue(), 2);
        queue.remove(10);
        assertEquals(queue.top().intValue(), 2);
        queue.remove(13);
        assertEquals(queue.top().intValue(), 2);
    }

    // Comparator class for Integer comparison
    static class ComparInt implements Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b) {
            return a.compareTo(b);
        }
    }
}
