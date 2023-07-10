
OBJ=obj
SRC=src
APP=exe08_19.sh

set -e

if [ $1 == "R" ] || [ $1 == "r" ] || [ $1 == "C" ] || [ $1 == "c" ]
then

	echo "Word.cpp..."
	g++ -c $SRC/Word.cpp -o $OBJ/Word.o
	echo "Program.cpp..."
	g++ -c $SRC/Program.cpp -o $OBJ/Program.o
	echo "Simpletron.cpp..."
	g++ -c $SRC/Simpletron.cpp -o $OBJ/Simpletron.o
	echo "exe08_19.cpp..."
	g++ -c $SRC/exe08_19.cpp    -o $OBJ/exe08_19.o

fi

if [ $1 == "D" ] || [ $1 == "d" ]
then
	
	echo "Word.cpp..."
	g++ -g -c $SRC/Word.cpp -o $OBJ/Word.o
	echo "Program.cpp..."
	g++ -g -c $SRC/Program.cpp -o $OBJ/Program.o
	echo "Simpletron.cpp..."
	g++ -g -c $SRC/Simpletron.cpp -o $OBJ/Simpletron.o
	echo "exe08_19.cpp..."
	g++ -g -c $SRC/exe08_19.cpp    -o $OBJ/exe08_19.o
fi

echo "Linkando...."
g++ -Wextra -Werror    \
	$OBJ/Word.o        \
	$OBJ/Program.o     \
	$OBJ/Simpletron.o  \
	$OBJ/exe08_19.o    \
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

