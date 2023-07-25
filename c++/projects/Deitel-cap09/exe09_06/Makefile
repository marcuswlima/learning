OBJ=obj/
SRC=src/
LIB=../../../../../lib-cplusplus/src/
TARGET=$(OBJ)Rational.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=$(OBJ)Mathematics.o  $(OBJ)Rational.o $(OBJ)exe09_06.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

$(OBJ)Mathematics.o: $(LIB)Mathematics.cpp $(LIB)Mathematics.h  
##	cp -v $(LIB)Mathematics* $(SRC)
	$(CC) -c $(CCFLAGS) $(SRC)Mathematics.cpp -o $(OBJ)Mathematics.o

$(OBJ)Rational.o: $(SRC)Rational.cpp $(SRC)Rational.h  
	$(CC) -c $(CCFLAGS) $(SRC)Rational.cpp -o $(OBJ)Rational.o

$(OBJ)exe09_06.o: $(SRC)exe09_06.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)exe09_06.cpp -o $(OBJ)exe09_06.o

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)

clear: 
	rm $(OBJ)*
