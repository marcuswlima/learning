echo off
set dados=D:\Users\marcus.william\Developer\dados

echo Deletando...
del %dados%\exe07_20.exe
del %dados%\Cliente.o
del %dados%\Atendente.o
del %dados%\exe07_20.o

echo Compilando...
g++ -c Cliente.cpp   -o %dados%\Cliente.o
g++ -c Atendente.cpp -o %dados%\Atendente.o
g++ -c exe07_20.cpp  -o %dados%\exe07_20.o

echo Linkando...
g++ %dados%\Cliente.o %dados%\Atendente.o %dados%\exe07_20.o -o %dados%\exe07_20.exe

echo Executando...
%dados%\exe07_20.exe
