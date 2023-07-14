TARGET=obj/prototipo
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=main.o exemplo.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) -lncurses
 
main.o:src/main.cpp src/exemplo.hh
	$(CC) -c $(CCFLAGS) src/main.cpp -o main.o

exemplo.o:src/exemplo.cpp
	$(CC) -c $(CCFLAGS) src/exemplo.cpp -o exemplo.o

d:
	gdb $(TARGET)
r:
	$(LD) -o $(TARGET) $(OBJS) -lncurses
	$(TARGET)
