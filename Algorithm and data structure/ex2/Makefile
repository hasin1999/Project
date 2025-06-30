BIN_SRC := src
BIN_DIR := bin

#creates bin folder
$(shell if not exist $(BIN_DIR) mkdir $(BIN_DIR))

#compilation of source files into executables
all:
	gcc -o $(BIN_DIR)/test_ex2 $(BIN_SRC)/test.c $(BIN_SRC)/edit_distance.c
	gcc -o $(BIN_DIR)/main_ex2 $(BIN_SRC)/main.c $(BIN_SRC)/edit_distance.c

#cleaning up object files and executables
cleanup:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/_ex2 $(BIN_DIR)/test_ex2 $(BIN_DIR)/main_ex2

run_main:
	./bin/main_ex2 ./data/dictionary.txt ./data/correctme.txt