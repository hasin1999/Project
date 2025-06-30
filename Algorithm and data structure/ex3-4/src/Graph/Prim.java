package Graph;

import java.util.*;
import java.io.*;

import PriorityQueue.PriorityQueue;

public class Prim {

    private static final Graph<String, Float> graph = new Graph<>(false, true);
    private static int nNode = 0;

    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
		// calculates the minimum spanning forest with Prim's algorithm
        // returns the collection of edges forming the forest
		
        Comparator<Edge<V, L>> edgeComparator = Comparator.comparingDouble(o -> o.getLabel().doubleValue());
        Set<V> visited = new HashSet<>();
        Collection<Edge<V, L>> forest = new ArrayList<>();
        PriorityQueue<Edge<V, L>> queue = new PriorityQueue<>(edgeComparator);

        for (V node : graph.getNodes()) {
            if (!visited.contains(node)) {
                visited.add(node);
                for (V next : graph.getNeighbours(node)) {
                    queue.push(new Edge<>(node, next, graph.getLabel(node, next)));
                }
                while (!queue.empty()) {
                    Edge<V, L> edge = queue.top();
                    queue.pop();
                    V currentNode = edge.getEnd();
                    if (visited.contains(currentNode)) {
                        continue;
                    }
                    forest.add(edge);
                    visited.add(currentNode);
                    for (V nextNode : graph.getNeighbours(currentNode)) {
                        if (!visited.contains(nextNode)) {
                            queue.push(new Edge<>(currentNode, nextNode, graph.getLabel(currentNode, nextNode)));
                        }
                    }
                }
            }
        }
        nNode = visited.size();
        return forest;
    }

    // Prints the minimum spanning forest and additional information.
    private static void printMsf() {
        double totalWeight = 0;
        Collection<? extends AbstractEdge<String, Float>> forest = minimumSpanningForest(graph);

        Set<String> printedEdges = new HashSet<>();

        for (AbstractEdge<String, Float> edge : forest) {
            totalWeight += edge.getLabel().doubleValue();
            String edgeKey = edge.getStart() + "-" + edge.getEnd();
            String reverseEdgeKey = edge.getEnd() + "-" + edge.getStart();
            if (!printedEdges.contains(edgeKey) && !printedEdges.contains(reverseEdgeKey)) {
                printedEdges.add(edgeKey);
                printedEdges.add(reverseEdgeKey);
                System.out.printf("%s, %s, %.2f%n", edge.getStart(), edge.getEnd(), edge.getLabel().doubleValue());
            }
        }
        System.out.println("--------------------------------------------------------");
        System.out.println("Number of nodes in the forest: " + nNode);
        System.out.println("Number of edges in the forest: " + forest.size());
        totalWeight = totalWeight / 1000;
        System.out.printf("Total weight of the forest: %.3f km%n", totalWeight);
		System.out.println("--------------------------------------------------------");
    }

    // Reads the CSV file and creates the graph.
    private static void readCsv(String path) {
        String line;
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            while ((line = br.readLine()) != null) {
                String[] split = line.split(",");
                String node1 = split[0].trim();
                String node2 = split[1].trim();
                Float weight = Float.valueOf(split[2].trim());

                // Add edges in both directions to treat as undirected
                graph.addNode(node1);
                graph.addNode(node2);
                graph.addEdge(node1, node2, weight);
                graph.addEdge(node2, node1, weight); // Adding the reverse edge
            }
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
	// read the CSV graph data from the path in args[1]
    // calculate the minimum spanning forest with minimumSpanningForest
    // write to standard output only the description of the calculated forest as CSV in a similar format to the input
    // additional information, such as the number of nodes and edges in the calculated forest or the total weight of the forest, can be written to standard error
        if (args.length == 0) {
            System.out.println("Usage: java Prim <file>");
            System.exit(1);
        }
        readCsv(args[0]);
        printMsf();
    }
}
