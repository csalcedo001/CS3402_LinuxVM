BIN = bin
OBJ = build
INC = include
LIB = lib
SRC = src

CC = gcc
CFLAGS = -I $(INC) -o $@

BINS = $(addprefix $(BIN)/, $(basename $(notdir $(wildcard $(SRC)/*))))
OBJS = $(patsubst $(LIB)/%.c, $(OBJ)/%.o, $(wildcard $(LIB)/*))

.PRECIOUS: $(OBJ)/*

all: $(BINS)

$(BIN)/%: $(SRC)/%.c $(OBJS)
	$(CC) $(CFLAGS) $^

$(OBJ)/%.o: $(LIB)/%.c $(INC)/%.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm $(BIN)/*
	rm $(OBJ)/*
