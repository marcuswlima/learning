OBJ=obj/
SRC=src/
TARGET=$(OBJ)soma.sh
OBJS=$(OBJ)soma.o
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTK) 
 
$(OBJ)soma.o: $(SRC)soma.cpp   
	$(CC) -c $(CCFLAGS) $(SRC)soma.cpp -o $(OBJ)soma.o $(GTK)

debug:
	gdb $(TARGET)
