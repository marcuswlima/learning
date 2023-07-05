
OBJ=obj
SRC=src
APP=exe08_12.sh

set -e

if [ $1 == "R" ] || [ $1 == "r" ] || [ $1 == "C" ] || [ $1 == "c" ]
then

	echo "DeckOfCards.cpp..."
	g++ -c $SRC/DeckOfCards.cpp -o $OBJ/DeckOfCards.o
	echo "exe08_12.cpp..."
	g++ -c $SRC/exe08_12.cpp    -o $OBJ/exe08_12.o

fi

if [ $1 == "D" ] || [ $1 == "d" ]
then
	
	echo "DeckOfCards.cpp..."
	g++ -g -c $SRC/DeckOfCards.cpp -o $OBJ/DeckOfCards.o
	echo "exe08_12.cpp..."
	g++ -g -c $SRC/exe08_12.cpp    -o $OBJ/exe08_12.o

fi

echo "Linkando...."
g++ -Wextra -Werror    \
	$OBJ/DeckOfCards.o \
	$OBJ/exe08_12.o    \
		-lncurses -ltinfo \
			-o $OBJ/$APP


if [ $1 == "R" ] || [ $1 == "r" ]
then
	echo "Executando...."
	$OBJ/$APP
fi

	
if [ $1 == "D" ] || [ $1 == "d" ]
then
	cd $OBJ
	echo "Debugging...."
	gdb $APP
	cd ..
fi

