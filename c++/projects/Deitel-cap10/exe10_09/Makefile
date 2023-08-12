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
OBJS=$(OBJ)Time.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
$(OBJ)Time.o: $(SRC)Time.cpp $(SRC)Time.h  
	$(CC) -c $(CCFLAGS) $(SRC)Time.cpp -o $(OBJ)Time.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug: all
	gdb $(TARGET)

run: all
	$(TARGET) 

clean:
	rm $(OBJ)*.o


