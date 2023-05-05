
OBJ=obj
SRC=src
LIB=../lib
NOME=notas
BIN=$NOME.sh

set -e

#clear 
echo "BarraTitulo.cpp..."
g++ -c $LIB/BarraTitulo.cpp           -o $OBJ/BarraTitulo.o
echo "Mathematics.cpp..."
g++ -c $LIB/Mathematics.cpp           -o $OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $LIB/ObterNumero.cpp           -o $OBJ/ObterNumero.o

echo "Nota.cpp..."
g++ -c $SRC/Nota.cpp      -o $OBJ/Nota.o
echo "Intervalo.cpp..."
g++ -c $SRC/Intervalo.cpp -o $OBJ/Intervalo.o
echo "Triade.cpp..."
g++ -c $SRC/Triade.cpp    -o $OBJ/Triade.o
echo "$NOME.cpp..."
g++ -c $SRC/$NOME.cpp     -o $OBJ/$NOME.o 

echo "Linkando...."
g++ $OBJ/BarraTitulo.o \
    $OBJ/Mathematics.o \
    $OBJ/ObterNumero.o \
    $OBJ/Nota.o        \
    $OBJ/Intervalo.o   \
    $OBJ/Triade.o      \
    $OBJ/$NOME.o       \
        -o $OBJ/$BIN

echo "Executando...."
$OBJ/$BIN

