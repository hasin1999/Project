package Graph;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// The Graph class implements an undirected or directed, labelled or unlabelled graph.
public class Graph<V, L> implements AbstractGraph<V, L>  {

    private int edgeCount; // The number of edges in the graph
    private int nodeCount; // The number of nodes in the graph
    private final boolean directed; // Indicates if the graph is directed
    private final boolean labelled; // Indicates if the graph is labelled
    private final Map<V, HashSet<Edge<V, L>>> neighbourList; // Stores edges for each node
    private final Map<V, Set<V>> adjacencyList; // Stores adjacency list for each node

    // Constructor to initialize the graph with specified properties
    public Graph(boolean directed, boolean labelled) {
        this.edgeCount = 0;
        this.nodeCount = 0;
        this.directed = directed;
        this.labelled = labelled;
        this.neighbourList = new HashMap<>();
        this.adjacencyList = new HashMap<>();
    }

    // Indicates whether the graph is directed or not
    @Override
    public boolean isDirected() {
        return directed;
    }

    // Indicates whether the graph is labelled or not
    @Override
    public boolean isLabelled() {
        return labelled;
    }

    // Checks if the graph is empty (no nodes and no edges)
    public boolean isEmpty() {
        return numNodes() == 0 && numEdges() == 0;
    }

    // Adds a node to the graph
    @Override
    public boolean addNode(V node) {
        if (node == null || neighbourList.containsKey(node)) {
            return false;
        }
        neighbourList.put(node, new HashSet<>());
        adjacencyList.put(node, new HashSet<>());
        nodeCount++;
        return true;
    }

    // Adds an edge between the given endpoints with a label
    @Override
    public boolean addEdge(V start, V end, L label) {
        if (start == null || end == null) {
            return false;
        }
        if (!containsNode(start) || !containsNode(end)) {
            return false;
        }
        if (containsEdge(start, end)) {
            return false;
        }
        if (!labelled && label != null) {
            return false;
        }
        if (labelled && label == null) {
            return false;
        }
        neighbourList.get(start).add(new Edge<>(start, end, label));
        adjacencyList.get(start).add(end);
        if (!directed) {
            neighbourList.get(end).add(new Edge<>(end, start, label));
            adjacencyList.get(end).add(start);
        }
        edgeCount++;
        return true;
    }

    // Checks if a node is in the graph
    public boolean containsNode(V node) {
        return neighbourList.containsKey(node);
    }

    // Checks if an edge is in the graph
    public boolean containsEdge(V start, V end) {
        if (!neighbourList.containsKey(start) || !neighbourList.containsKey(end)) {
            return false;
        }
        return adjacencyList.get(start).contains(end);
    }

    // Removes a node from the graph
    public boolean removeNode(V node) {
        if (!containsNode(node) || node == null) {
            return false;
        }
        Set<V> adjacentNodes = adjacencyList.get(node);
        for (V adjacentNode : adjacentNodes) {
            Set<Edge<V, L>> edges = neighbourList.get(adjacentNode);
            edges.removeIf(edge -> edge.getEnd().equals(node));
            edgeCount--;
            if (!directed) {
                adjacencyList.get(adjacentNode).remove(node);
            }
        }
        neighbourList.remove(node);
        adjacencyList.remove(node);
        nodeCount--;
        return true;
    }

    // Removes an edge from the graph
    public boolean removeEdge(V start, V end) {
        if (!containsEdge(start, end)) {
            return false;
        }
        if (!adjacencyList.containsKey(start) || !adjacencyList.containsKey(end)) {
            return false;
        }
        HashSet<Edge<V, L>> edges = neighbourList.get(start);
        if (edges.removeIf(edge -> edge.getEnd().equals(end))) {
            adjacencyList.get(start).remove(end);
            if (!directed) {
                HashSet<Edge<V, L>> reverseEdges = neighbourList.get(end);
                reverseEdges.removeIf(edge -> edge.getEnd().equals(start));
                adjacencyList.get(end).remove(start);
            }
            edgeCount--;
            return true;
        }
        return false;
    }

    // Returns the number of nodes in the graph
    public int numNodes() {
        return nodeCount;
    }

    // Returns the number of edges in the graph
    public int numEdges() {
        return edgeCount;
    }

    // Retrieves the nodes of the graph
    public Collection<V> getNodes() {
        if (nodeCount == 0) {
            System.out.println("There are no nodes in the graph");
        }
        return neighbourList.keySet();
    }

    // Retrieves the edges of the graph
    public Collection<? extends AbstractEdge<V, L>> getEdges() {
        if (edgeCount == 0) {
            return Collections.emptySet();
        }
        Collection<Edge<V, L>> edges = new HashSet<>();
        for (Set<Edge<V, L>> edgeSet : neighbourList.values()) {
            edges.addAll(edgeSet);
        }
        return edges;
    }

    // Retrieves the neighbors of a given node
    public Collection<V> getNeighbours(V node) {
        if (!adjacencyList.containsKey(node)) {
            System.out.println("The node is not present in the graph");
        }
        return adjacencyList.get(node);
    }

    // Retrieves the label of an edge
    public L getLabel(V start, V end) {
        if (!labelled) {
            System.err.println("The graph is not labelled");
            return null;
        }
        if (!this.containsEdge(start, end)) {
            System.err.println("The edge is not present in the graph");
            return null;
        }
        HashSet<Edge<V, L>> edges = neighbourList.get(start);
        for (Edge<V, L> edge : edges) {
            if (edge.getEnd().equals(end)) {
                return edge.getLabel();
            }
        }
        return null;
    }
}
