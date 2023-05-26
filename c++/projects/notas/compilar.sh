
NOME=notas
OBJ=obj
SRC=src
LIB=../lib
APP=$NOME.sh

set -e

echo "BarraTitulo.cpp..."
g++ -c $LIB/BarraTitulo.cpp -o $OBJ/BarraTitulo.o
echo "Mathematics.cpp..."
g++ -c $LIB/Mathematics.cpp -o $OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $LIB/ObterNumero.cpp -o $OBJ/ObterNumero.o

if [ $1 == "R" ] || [ $1 == "r" ] || [ $1 == "C" ] || [ $1 == "c" ]
then

	echo "Nota.cpp..."
	g++ -c $SRC/Nota.cpp      -o $OBJ/Nota.o
	echo "Intervalo.cpp..."
	g++ -c $SRC/Intervalo.cpp -o $OBJ/Intervalo.o
	echo "Triade.cpp..."
	g++ -c $SRC/Triade.cpp    -o $OBJ/Triade.o
	echo "Tetrade.cpp..."
	g++ -c $SRC/Tetrade.cpp    -o $OBJ/Tetrede.o
	echo "$NOME.cpp..."
	g++ -c $SRC/$NOME.cpp     -o $OBJ/$NOME.o 

fi

if [ $1 == "D" ] || [ $1 == "d" ]
then
	echo "Nota.cpp..."
	g++ -g -c $SRC/Nota.cpp      -o $OBJ/Nota.o
	echo "Intervalo.cpp..."
	g++ -g -c $SRC/Intervalo.cpp -o $OBJ/Intervalo.o
	echo "Triade.cpp..."
	g++ -g -c $SRC/Triade.cpp    -o $OBJ/Triade.o
	echo "$NOME.cpp..."
	g++ -g -c $SRC/$NOME.cpp     -o $OBJ/$NOME.o 
fi

echo "Linkando...."
g++ -Wextra -Werror    \
    $OBJ/BarraTitulo.o \
	$OBJ/Mathematics.o \
	$OBJ/ObterNumero.o \
	$OBJ/Nota.o        \
	$OBJ/Intervalo.o   \
	$OBJ/Triade.o      \
	$OBJ/$NOME.o       \
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

