*CC=g++
DEFS = ./defs
LIB = ./lib
SRC = ./src
BIN = ./bin

all: $(LIB)/serialib.o

	@echo "Compilation programme principal"
	$(CC) $(FLAGS) $(SRC)/main.cpp $(LIB)/serialib.o

$(LIB)/serialib.o : $(SRC)/serialib.cpp $(DEFS)/serialib.h 
	@echo "Compilation classe serialib"
	$(CC) -c $(SRC)/serialib.cpp -std=c++11 -std=gnu++11 -lpthread  -o $@ $(FLAGS) 


