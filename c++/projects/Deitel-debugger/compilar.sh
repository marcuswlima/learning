
F_LIB=../lib
F_OBJ=obj
F_SRC=src
APP=$F_OBJ/$1.sh

set -e

echo "$1.cpp..."
g++ -c $F_SRC/$1.cpp          -o $F_OBJ/$1.o
g++ -c $F_SRC/Account.cpp     -o $F_OBJ/Account.o

if [ $2 == "R" ] || [ $2 == "r" ] 
then
	echo "Linkando...."
	g++ $F_OBJ/$1.o  $F_OBJ/Account.o -o $APP
	echo "Executando...."
	$APP
fi

if [ $2 == "D" ] || [ $2 == "d" ]
then
	echo "Linkando para debugging...."
	g++ -g -o $APP $F_OBJ/$1.o $F_OBJ/Account.o 
	cd obj
	echo "Debugging...."
	gdb $1.sh
	cd ..
fi


