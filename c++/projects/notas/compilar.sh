
OBJ=obj
SRC=src
LIB=../lib
NOME=notas

set -e

echo "BarraTitulo.cpp..."
g++ -c $LIB/BarraTitulo.cpp    -o $OBJ/BarraTitulo.o
echo "PrintArray.cpp..."
g++ -c $LIB/PrintArray.cpp     -o $OBJ/PrintArray.o
echo "Mathematics.cpp..."
g++ -c $LIB/Mathematics.cpp    -o $OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $LIB/ObterNumero.cpp    -o $OBJ/ObterNumero.o
echo "Nota.cpp..."
g++ -c $SRC/Nota.cpp           -o $OBJ/Nota.o
echo "Intervalo.cpp..."
g++ -c $SRC/Intervalo.cpp      -o $OBJ/Intervalo.o
echo "Triade.cpp..."
g++ -c $SRC/Triade.cpp         -o $OBJ/Triade.o
echo "Compilando $NOME..."
g++ -c $SRC/$NOME.cpp          -o $OBJ/$NOME.o 


echo "Linkando...."
g++ $OBJ/BarraTitulo.o \
    $OBJ/Mathematics.o \
    $OBJ/ObterNumero.o \
    $OBJ/Nota.o        \
    $OBJ/Intervalo.o   \
    $OBJ/Triade.o      \
    $OBJ/$NOME.o       \
        -o $OBJ/$NOME.sh

echo "Executando...."
$OBJ/$NOME.sh

