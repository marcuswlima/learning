OBJ=obj/
SRC=src/
TARGET=$(OBJ)Time.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Time.o $(OBJ)exe09_07.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Time.o: $(SRC)Time.cpp $(SRC)Time.h  
	$(CC) -c $(CCFLAGS) $(SRC)Time.cpp -o $(OBJ)Time.o

$(OBJ)exe09_07.o: $(SRC)exe09_07.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)exe09_07.cpp -o $(OBJ)exe09_07.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)
