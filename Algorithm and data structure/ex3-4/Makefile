#folder definition
BIN_SRC_PRIORITY := src/PriorityQueue
BIN_DIR_PRIORITY := bin
BIN_SRC_GRAPH := src/Graph
BIN_DIR_GRAPH := bin
DATA_DIR := data

#compilation of source files into executables
all: 
	javac -cp "lib/*" -d $(BIN_DIR_PRIORITY) $(BIN_SRC_PRIORITY)/*.java
	javac -cp "lib/*" -d $(BIN_DIR_GRAPH) $(BIN_SRC_GRAPH)/*.java $(BIN_SRC_PRIORITY)/*.java

graph:
	java -cp "$(BIN_DIR_GRAPH):lib/*" Graph.GraphTestRunner

queue:
	java -cp "$(BIN_DIR_PRIORITY):lib/*" PriorityQueue.PriorityQueueTestRunner

prim:
	java -cp "$(BIN_DIR_PRIORITY):lib/*" Graph.Prim "$(DATA_DIR)/italian_dist_graph.csv"
	
RunPrim:
	java -cp bin Graph.Prim data/italian_dist_graph.csv

#cleaning up object files and executables
cleanup:
	rm -f $(BIN_DIR_PRIORITY)/*.class
