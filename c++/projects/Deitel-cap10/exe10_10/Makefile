OBJ=build/
SRC=./
LIB=../../lib-cplusplus/src/
TARGET=$(OBJ)notas.exe
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
OBJS=$(OBJ)Card.o $(OBJ)Hand.o $(OBJ)DeckOfCards.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
$(OBJ)Card.o: $(SRC)Card.cpp $(SRC)Card.h  
	$(CC) -c $(CCFLAGS) $(SRC)Card.cpp -o $(OBJ)Card.o

$(OBJ)DeckOfCards.o: $(SRC)DeckOfCards.cpp $(SRC)DeckOfCards.h  
	$(CC) -c $(CCFLAGS) $(SRC)DeckOfCards.cpp -o $(OBJ)DeckOfCards.o

$(OBJ)Hand.o: $(SRC)Hand.cpp $(SRC)Hand.h  
	$(CC) -c $(CCFLAGS) $(SRC)Hand.cpp -o $(OBJ)Hand.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug: all
	gdb $(TARGET)

run: all
	$(TARGET) 

clean:
	rm $(OBJ)*.o


