TARGET=obj/soma.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=obj/soma.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(pkg-config gtkmm-3.0 --cflags --libsi) -export-dymamic
 
obj/soma.o: src/soma.cpp   
	$(CC) -c $(CCFLAGS) src/soma.cpp -o obj/soma.o $(pkg-config gtkmm-3.0 --cflags --libsi) -export-dynamic

d:
	$(LD) -o $(TARGET) $(OBJS) $(pkg-config gtkmm-3.0 --cflags --libsi) -export-dymamic
	gdb $(TARGET)
run:
	$(LD) -o $(TARGET) $(OBJS) $(pkg-config gtkmm-3.0 --cflags --libsi) -export-dymamic
	$(TARGET)
clean:
	rm obj/*.o


