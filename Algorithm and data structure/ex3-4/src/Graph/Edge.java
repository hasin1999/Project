package Graph;

public class Edge<V, L> implements AbstractEdge<V, L> {
    private final V startVertex; // The starting vertex of the edge
    private final V endVertex; // The ending vertex of the edge
    private final L edgeLabel; // The label or weight of the edge

    // Constructor to initialize an edge with start vertex, end vertex, and a label
    public Edge(V start, V end, L label) {
        this.startVertex = start;
        this.endVertex = end;
        this.edgeLabel = label;
    }

    // Returns the starting vertex of the edge
    @Override
    public V getStart() {
        if (startVertex == null) {
            System.out.println("The start vertex of the edge is null");
        }
        return startVertex;
    }

    // Returns the ending vertex of the edge
    @Override
    public V getEnd() {
        if (endVertex == null) {
            System.out.println("The end vertex of the edge is null");
        }
        return endVertex;
    }

    // Returns the label of the edge
    @Override
    public L getLabel() {
        if (edgeLabel == null) {
            System.out.println("The label of the edge is null");
        }
        return edgeLabel;
    }
}
