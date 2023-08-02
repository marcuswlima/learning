OBJ=obj/
SRC=src/
LIB=../../lib-cplusplus/src/
TARGET=$(OBJ)SnakeGame.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
OBJS=$(OBJ)SnakeGame.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(NCURSES)
 
$(OBJ)SnakeGame.o: $(SRC)SnakeGame.cpp $(SRC)SnakeGame.h  
	$(CC) -c $(CCFLAGS) $(SRC)SnakeGame.cpp -o $(OBJ)SnakeGame.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug:all
	gdb $(TARGET)

run:all
	$(TARGET) 

clean:
	rm $(OBJ)*.o


