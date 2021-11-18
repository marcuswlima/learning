echo off
set dados=D:\Users\marcus.william\Developer\dados

echo ***************************
echo ** Deletando...
echo ***************************
del %dados%\exe07_24.exe
del %dados%\Board.o

echo ***************************
echo ** Compilando...
echo ***************************
g++ -c Board.cpp               -o %dados%\Board.o
g++ -c exe07_24.cpp            -o %dados%\exe07_23.o
g++ -c ..\..\lib\marcusLib.cpp -o %dados%\marcusLib.o

echo ***************************
echo ** Linkando...
echo ***************************
g++ %dados%\marcusLib.o %dados%\Board.o  %dados%\exe07_23.o -o %dados%\exe07_24.exe

echo ***************************
echo ** Executando...
echo ***************************
%dados%\exe07_24.exe
