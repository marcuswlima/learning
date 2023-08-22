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
OBJS=$(OBJ)integerset.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
$(OBJ)integerset.o: $(SRC)integerset.cpp $(SRC)integerset.h  
	$(CC) -c $(CCFLAGS) $(SRC)integerset.cpp -o $(OBJ)integerset.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug: all
	gdb $(TARGET)

run: all
	$(TARGET) 

clean:
	rm $(OBJ)*.o


