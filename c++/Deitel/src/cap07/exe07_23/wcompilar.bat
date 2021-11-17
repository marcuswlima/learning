echo off
set dados=D:\Users\marcus.william\Developer\dados

echo ***************************
echo ** Deletando...
echo ***************************
del %dados%\exe07_23.exe
del %dados%\Tabuleiro.o

echo ***************************
echo ** Compilando...
echo ***************************
g++ -c Tabuleiro.cpp -o %dados%\Tabuleiro.o
g++ -c exe07_23.cpp  -o %dados%\exe07_23.o

echo ***************************
echo ** Linkando...
echo ***************************
g++ %dados%\Tabuleiro.o  %dados%\exe07_23.o -o %dados%\exe07_23.exe

echo ***************************
echo ** Executando...
echo ***************************
%dados%\exe07_23.exe
