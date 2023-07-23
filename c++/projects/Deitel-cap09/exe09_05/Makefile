OBJ=obj/
SRC=src/
TARGET=$(OBJ)Complex.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Complex.o $(OBJ)exe09_05.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Complex.o: $(SRC)Complex.cpp $(SRC)Complex.h  
	$(CC) -c $(CCFLAGS) $(SRC)Complex.cpp -o $(OBJ)Complex.o

$(OBJ)exe09_05.o: $(SRC)exe09_05.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)exe09_05.cpp -o $(OBJ)exe09_05.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)