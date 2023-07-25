CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/uteis.o $(OBJ)/pilha.o $(OBJ)/expressoes.o $(OBJ)/main.o 
HDRS = $(INC)/pilha.h $(INC)/uteis.h $(INC)/expressoes.h 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main


run: $(EXE)
	$(EXE) 

all:  $(EXE)
	$(EXE) -d 10 -s

#colocar -pg para debugar

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(OBJ)/uteis.o $(OBJ)/expressoes.o $(SRC)/main.cpp 

$(OBJ)/expressoes.o: $(HDRS) $(SRC)/expressoes.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expressoes.o $(OBJ)/uteis.o $(SRC)/expressoes.cpp 

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 

$(OBJ)/uteis.o: $(HDRS) $(SRC)/uteis.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/uteis.o $(SRC)/uteis.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
