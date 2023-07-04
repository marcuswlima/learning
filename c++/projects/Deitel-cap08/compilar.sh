
NOME=$1
F_LIB=../lib
F_OBJ=obj
F_SRC=src
APP=$F_OBJ/$1.sh

set -e

echo "BarraTitulo.cpp..."
g++ -c $F_LIB/BarraTitulo.cpp -o $F_OBJ/BarraTitulo.o
echo "Mathematics.cpp..."
g++ -c $F_LIB/Mathematics.cpp -o $F_OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $F_LIB/ObterNumero.cpp -o $F_OBJ/ObterNumero.o
echo "PrintArrey.cpp..."
g++ -c $F_LIB/PrintArray.cpp  -o $F_OBJ/PrintArray.o

echo "$1.cpp..."
g++ -c $F_SRC/$1.cpp          -o $F_OBJ/$1.o

echo "Linkando...."
g++ $F_OBJ/BarraTitulo.o \
    $F_OBJ/Mathematics.o \
    $F_OBJ/ObterNumero.o \
    $F_OBJ/PrintArray.o \
    $F_OBJ/$1.o          \
        -o $APP

echo "Executando...."
$APP

