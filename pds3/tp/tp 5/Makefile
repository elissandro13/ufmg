CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/geraarvbin.o 
# HDRS = $(INC)/vet.h $(INC)/msgassert.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/geraarvbin

run:  $(EXE)
	$(EXE) -d 10 -s
	$(EXE) -d 10 -i
	$(EXE) -d 10 -n

$(BIN)/geraarvbin: $(OBJS)
	$(CC) -pg -o $(BIN)/vetop $(OBJS) $(LIBS)

$(OBJ)/geraarvbin.o: $(HDRS) $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
