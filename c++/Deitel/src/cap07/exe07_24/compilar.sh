

dados=/home/marcus/Developer/dados/c++

echo Deletando...
rm $dados/exe07_24.sh
rm $dados/Board.o
rm $dados/exe07_24.o

echo Compilando...
g++ -c Board.cpp    -o $dados/Board.o
g++ -c exe07_24.cpp -o $dados/exe07_24.o

echo Linkando...
g++ $dados/Board.o $dados/exe07_24.o -o $dados/exe07_24.sh

echo Executando...
$dados/exe07_24.sh

