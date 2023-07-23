OBJ=obj/
SRC=src/
TARGET=$(OBJ)Time.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Time.o $(OBJ)fig09_10.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Time.o: $(SRC)Time.cpp $(SRC)Time.h  
	$(CC) -c $(CCFLAGS) $(SRC)Time.cpp -o $(OBJ)Time.o

$(OBJ)fig09_10.o: $(SRC)fig09_10.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)fig09_10.cpp -o $(OBJ)fig09_10.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)