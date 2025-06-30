package Graph;

import org.junit.Test;

import java.util.Collection;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertEquals;

public class GraphTest {

    // Checks if getting nodes works
    @Test
    public void testGetNode() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestGetNode()");
        assertTrue(graph.addNode(1));
        assertTrue(graph.addNode(2));
        assertTrue(graph.addNode(3));
        Collection<Integer> test = graph.getNodes();
        assertTrue(test.contains(1));
        assertTrue(test.contains(2));
        assertTrue(test.contains(3));
    }

    // Checks if the graph is labelled
    @Test
    public void testLabelled() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestLabelled()");
        assertTrue(graph.isLabelled());
    }

    // Checks if the graph is directed
    @Test
    public void testDirected() {
        Graph<Integer, String> graph = new Graph<>(true, false);
        System.out.print("\ntestDirected()");
        assertTrue(graph.isDirected());
    }

    // Checks if adding a single node works
    @Test
    public void testNodeAdded() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestNodeAdded()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.containsNode(4));
        assertEquals(1, graph.numNodes());
        assertFalse(graph.isEmpty());
    }

    // Checks if adding multiple nodes works
    @Test
    public void testNodesAdded() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestNodesAdded()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(2));
        assertTrue(graph.containsNode(4));
        assertTrue(graph.containsNode(2));
        assertEquals(2, graph.numNodes());
        assertFalse(graph.isEmpty());
    }

    // Checks if removing nodes works
    @Test
    public void testRemoveNode() {
        Graph<Integer, String> graph = new Graph<>(true, false);
        System.out.print("\ntestRemoveNode()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addNode(6));
        assertFalse(graph.removeNode(null));
        assertFalse(graph.removeNode(7));
        assertTrue(graph.addEdge(4, 5, null));
        assertTrue(graph.addEdge(4, 6, null));
        assertTrue(graph.removeNode(4));
        assertFalse(graph.containsNode(4));
        assertFalse(graph.containsEdge(4, 5));
        assertFalse(graph.containsEdge(5, 4));
        assertFalse(graph.containsEdge(4, 6));
        assertTrue(graph.containsNode(5));
        assertFalse(graph.containsNode(4));
        assertEquals(2, graph.numNodes());
        assertEquals(0, graph.numEdges());
    }

    // Checks if removing non-directed nodes works
    @Test    
    public void testRemoveNodeNotDirected() {
        Graph<Integer, String> graph = new Graph<>(false, false);
        System.out.print("\ntestRemoveNodeNotDirected()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addNode(6));
        assertTrue(graph.addNode(7));
        assertTrue(graph.addEdge(4, 5, null));
        assertTrue(graph.addEdge(4, 6, null));
        assertTrue(graph.addEdge(4, 7, null));
        assertTrue(graph.removeNode(4));
        assertFalse(graph.containsNode(4));
        assertFalse(graph.containsEdge(4, 5));
        assertFalse(graph.containsEdge(5, 4));
        assertEquals(3, graph.numNodes());
        assertEquals(0, graph.numEdges());
        assertTrue(graph.containsNode(5));
        assertFalse(graph.containsNode(4));
    }

    // Checks if removing directed edges works
    @Test
    public void testRemoveEdgeDirected() {
        Graph<Integer, String> graph = new Graph<>(true, false);
        System.out.print("\ntestRemoveEdgeDirected()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addEdge(4, 5, null));
        assertTrue(graph.removeEdge(4, 5));
        assertFalse(graph.containsEdge(4, 5));
        assertFalse(graph.containsEdge(5, 4));
        assertTrue(graph.containsNode(5));
        assertTrue(graph.containsNode(4));
    }

    // Checks if removing non-directed edges works
    @Test
    public void testRemoveEdgeNotDirected() {
        Graph<Integer, String> graph = new Graph<>(false, false);
        System.out.print("\ntestRemoveEdgeNotDirected()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addEdge(4, 5, null));
        assertTrue(graph.removeEdge(4, 5)); 
        assertFalse(graph.containsEdge(4, 5));
        assertFalse(graph.containsEdge(5, 4));
        assertTrue(graph.containsNode(5));
        assertTrue(graph.containsNode(4));
    }

    // Checks if labels work 
    @Test
    public void testGetLabel() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestGetLabel()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addEdge(4, 5, "test"));
        assertEquals(graph.getLabel(4, 5), "test");
    }

    // Checks if getting neighbour list works
    @Test
    public void testGetNeighbourList() {
        Graph<Integer, String> graph = new Graph<>(false, true);
        System.out.print("\ntestGetNeighbourList()");
        assertTrue(graph.addNode(4));
        assertTrue(graph.addNode(5));
        assertTrue(graph.addNode(6));
        assertTrue(graph.addNode(7));
        assertTrue(graph.addEdge(4, 5, "test"));
        assertTrue(graph.addEdge(4, 6, "test"));
        assertTrue(graph.addEdge(5, 6, "test"));
        assertTrue(graph.addEdge(6, 7, "test"));
        assertTrue(graph.addEdge(7, 4, "test"));
        Collection<Integer> test = graph.getNeighbours(4);
        assertTrue(test.contains(5));
        assertTrue(test.contains(6));
    }
}
