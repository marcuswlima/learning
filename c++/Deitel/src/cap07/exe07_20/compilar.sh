

dados=/home/marcus/Developer/dados/c++

echo Deletando...
rm $dados/exe07_20.sh
rm $dados/Cliente.o
rm $dados/Atendente.o
rm $dados/exe07_20.o

echo Compilando...
g++ -c Cliente.cpp   -o $dados/Cliente.o
g++ -c Atendente.cpp -o $dados/Atendente.o
g++ -c exe07_20.cpp  -o $dados/exe07_20.o

echo Linkando...
g++ $dados/Cliente.o $dados/Atendente.o $dados/exe07_20.o -o $dados/exe07_20.sh

echo Executando...
$dados/exe07_20.sh

