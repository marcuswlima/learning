OBJ=obj/
SRC=src/
TARGET=$(OBJ)connect.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
MYSQL=-L /usr/include/mysql -lmysqlclient -I /usr/include/mysql
OBJS=$(OBJ)connect.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(MYSQL)
 
$(OBJ)connect.o: $(SRC)connect.cpp  
	$(CC) -c $(CCFLAGS) $(SRC)connect.cpp -o $(OBJ)connect.o $(MYSQL)

debug: all
	gdb $(TARGET)
run: all
	$(TARGET) 
clean:
	rm $(OBJ)*.o


