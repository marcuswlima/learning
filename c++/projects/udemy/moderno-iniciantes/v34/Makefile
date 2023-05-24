TARGET=helloworld
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CURSES=-lncurses
TINFO=-ltinfo
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS=helloworld.cpp
all: helloworld.cpp
	$(LD) -o $(TARGET) $(OBJS) $(DEBUG) $(OPT) $(WARN) $(CURSES) $(TINFO)

