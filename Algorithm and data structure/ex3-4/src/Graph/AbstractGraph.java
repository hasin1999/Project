package Graph;

import java.util.Collection;

public interface AbstractGraph<V,L> {
    public boolean isDirected(); //indicates whether the graph is directed or not -- O(1)
    public boolean isLabelled(); //indicates whether the graph is labeled or not -- O(1)
    public boolean addNode(V a); //adds a node -- O(1)
    public boolean addEdge(V a, V b, L l); //adds an edge between given endpoints with a label -- O(1) (*)
    public boolean containsNode(V a); //checks if a node is in the graph -- O(1)
    public boolean containsEdge(V a, V b); //checks if an edge is in the graph -- O(1) (*)
    public boolean removeNode(V a); //removes a node from the graph -- O(N)
    public boolean removeEdge(V a, V b); //removes an edge from the graph -- O(1) (*)
    public int numNodes(); //number of nodes -- O(1)
    public int numEdges(); //number of edges -- O(N)
    public Collection<V> getNodes(); //retrieves the nodes of the graph -- O(N)
    public Collection<? extends AbstractEdge<V,L>> getEdges(); //retrieves the edges of the graph -- O(N)
    public Collection<V> getNeighbours(V a); // etrieves the neighbors of a given node -- O(1) (*)
    public L getLabel(V a, V b); //retrieves the label of an edge -- O(1) (*)
  };
