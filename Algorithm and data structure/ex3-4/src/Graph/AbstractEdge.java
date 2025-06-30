package Graph;

public interface AbstractEdge<V, L> {
    public V getStart();        // the starting node of the edge
    public V getEnd();          // the ending node of the edge
    public L getLabel();        // the label of the edge
}
