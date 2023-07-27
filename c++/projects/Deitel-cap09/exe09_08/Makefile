OBJ=obj/
SRC=src/
LIB=../../../../../lib-cplusplus/src/
TARGET=$(OBJ)Date.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Mathematics.o  $(OBJ)Date.o $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Mathematics.o: $(LIB)Mathematics.cpp $(LIB)Mathematics.h  
	$(CC) -c $(CCFLAGS) $(LIB)Mathematics.cpp -o $(OBJ)Mathematics.o

$(OBJ)Date.o: $(SRC)Date.cpp $(SRC)Date.h  
	cp -v $(LIB)Mathematics* $(SRC)
	$(CC) -c $(CCFLAGS) $(SRC)Date.cpp -o $(OBJ)Date.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)

clean:
	rm obj/*
