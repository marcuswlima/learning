OBJ=obj/
SRC=src/
LIB=../../../../../lib-cplusplus/src/
TARGET=$(OBJ)Rectangle.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Rectangle.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Rectangle.o: $(SRC)Rectangle.cpp $(SRC)Rectangle.h 
	$(CC) -c $(CCFLAGS) $(SRC)Rectangle.cpp -o $(OBJ)Rectangle.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)

clean:
	rm obj/*
