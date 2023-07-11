
NOME=$1
F_LIB=../lib
F_OBJ=obj
F_SRC=src
APP=$F_OBJ/$1.sh

set -e

echo "$1.cpp..."
g++ -c $F_SRC/$1.cpp          -o $F_OBJ/$1.o

echo "Linkando...."
g++ $F_OBJ/$1.o -o $APP

echo "Executando...."
$APP

