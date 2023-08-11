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
OBJS=$(OBJ)savingaccount.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
$(OBJ)savingaccount.o: $(SRC)savingaccount.cpp $(SRC)savingaccount.h  
	$(CC) -c $(CCFLAGS) $(SRC)savingaccount.cpp -o $(OBJ)savingaccount.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug: all
	gdb $(TARGET)

run: all
	$(TARGET) 

clean:
	rm $(OBJ)*.o


