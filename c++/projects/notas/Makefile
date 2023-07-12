TARGET=obj/notas.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=obj/Nota.o obj/Intervalo.o obj/notas.o obj/Mathematics.o obj/Janela.o obj/Triade.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) -lncurses
 
obj/Mathematics.o:../lib/Mathematics.cpp 
	$(CC) -c $(CCFLAGS) ../lib/Mathematics.cpp -o obj/Mathematics.o

obj/notas.o: src/notas.cpp src/Janela.h src/Triade.h
	$(CC) -c $(CCFLAGS) src/notas.cpp -o obj/notas.o

obj/Nota.o: src/Nota.cpp ../lib/Mathematics.cpp  
	$(CC) -c $(CCFLAGS) src/Nota.cpp -o obj/Nota.o

obj/Intervalo.o: src/Intervalo.cpp 
	$(CC) -c $(CCFLAGS) src/Intervalo.cpp -o obj/Intervalo.o

obj/Janela.o: src/Janela.cpp 
	$(CC) -c $(CCFLAGS) src/Janela.cpp    -o obj/Janela.o

obj/Triade.o: src/Triade.cpp 
	$(CC) -c $(CCFLAGS) src/Triade.cpp    -o obj/Triade.o


