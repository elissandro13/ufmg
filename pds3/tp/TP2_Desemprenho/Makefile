CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/fat.o $(OBJ)/fib.o $(OBJ)/recurFat.o $(OBJ)/recurFib.o 
CFLAGS = -Wall -c -I$(INC)

EXES = $(BIN)/fat $(BIN)/recurFat $(BIN)/fib $(BIN)/recurFib


run: $(EXES)
	
	$(BIN)/fat 5
	$(BIN)/recurFat 5
	$(BIN)/fib 5
	$(BIN)/recurFib 5

all: $(EXES)
	
	time $(BIN)/fat 40
	time $(BIN)/recurFat 40
	time $(BIN)/fib 40
	time $(BIN)/recurFib 40

$(BIN)/fat: $(OBJ)/fat.o
	$(CC) -o $(BIN)/fat $(OBJ)/fat.o

$(BIN)/fib: $(OBJ)/fib.o 
	$(CC) -o $(BIN)/fib $(OBJ)/fib.o 

$(BIN)/recurFat: $(OBJ)/recurFat.o
	$(CC) -o $(BIN)/recurFat $(OBJ)/recurFat.o

$(BIN)/recurFib: $(OBJ)/recurFib.o 
	$(CC) -o $(BIN)/recurFib $(OBJ)/recurFib.o 

$(OBJ)/fat.o:  $(SRC)/fat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.c 

$(OBJ)/fib.o:  $(SRC)/fib.c
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.c 

$(OBJ)/recurFat.o:  $(SRC)/recurFat.c
	$(CC) $(CFLAGS) -o $(OBJ)/recurFat.o $(SRC)/recurFat.c

$(OBJ)/recurFib.o:  $(SRC)/recurFib.c
	$(CC) $(CFLAGS) -o $(OBJ)/recurFib.o $(SRC)/recurFib.c
	
clean:
	rm -f $(EXEs) $(OBJS) $(EXES)
