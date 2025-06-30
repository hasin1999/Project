# DESTINATIONS
BIN_SRC := src
BIN_DIR := bin

# creates bin folder if it doesn't already exist
$(shell if not exist $(BIN_DIR) mkdir $(BIN_DIR))

# COMPILE THE FILES
all: 
	gcc -o $(BIN_DIR)\test_ex1.exe $(BIN_SRC)\test.c $(BIN_SRC)\sorting.c
	gcc -o $(BIN_DIR)\main_ex1.exe $(BIN_SRC)\main.c  $(BIN_SRC)\sorting.c

# RUN TARGETS
run_test:
	$(BIN_DIR)\test_ex1.exe

# CLEAN UP
cleanup:
	del /Q $(BIN_DIR)\test_ex1.exe $(BIN_DIR)\main_ex1.exe
