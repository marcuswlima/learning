TARGET=obj/notas.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=obj/Mathematics.o                  \
     obj/Nota.o   obj/Intervalo.o       \
	 obj/Triade.o obj/Tetrade.o         \
	 obj/Janela.o obj/ncurses-notas.o   \
     obj/main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) -lncurses
 
obj/Mathematics.o: src/Mathematics.cpp src/Mathematics.h  
	cp -v ../lib/Mathematics* src/
	$(CC) -c $(CCFLAGS) src/Mathematics.cpp -o obj/Mathematics.o

obj/Nota.o: src/Nota.cpp src/Nota.h 
	$(CC) -c $(CCFLAGS) src/Nota.cpp -o obj/Nota.o

obj/Intervalo.o: src/Intervalo.cpp src/Intervalo.h 
	$(CC) -c $(CCFLAGS) src/Intervalo.cpp -o obj/Intervalo.o

obj/Triade.o: src/Triade.cpp src/Triade.h 
	$(CC) -c $(CCFLAGS) src/Triade.cpp -o obj/Triade.o

obj/Tetrade.o: src/Tetrade.cpp src/Tetrade.h 
	$(CC) -c $(CCFLAGS) src/Tetrade.cpp -o obj/Tetrade.o

obj/Janela.o: src/Janela.cpp src/Janela.h 
	$(CC) -c $(CCFLAGS) src/Janela.cpp -o obj/Janela.o

obj/ncurses-notas.o: src/ncurses-notas.cpp src/ncurses-notas.h src/Janela.h src/Tetrade.h
	$(CC) -c $(CCFLAGS) src/ncurses-notas.cpp -o obj/ncurses-notas.o

obj/main.o: src/main.cpp src/ncurses-notas.h
	$(CC) -c $(CCFLAGS) src/main.cpp -o obj/main.o

d:
	$(LD) -o $(TARGET) $(OBJS) -lncurses
	gdb $(TARGET)
run:
	$(LD) -o $(TARGET) $(OBJS) -lncurses
	$(TARGET)
clean:
	rm obj/*.o


