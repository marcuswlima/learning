echo off

set BIN=D:\Users\marcus.william\Developer\dados\%1
set OBJ=D:\Users\marcus.william\Developer\dados\%1.o
set OBJ6=D:\Users\marcus.william\Developer\dados\cap06.o

echo Deletando...
del D:\Users\marcus.william\Developer\dados\%1.exe

echo Compilando...
g++ -Wextra -Werror cap06.cpp cai.cpp %1.cpp -o D:\Users\marcus.william\Developer\dados\%1

echo Executando...
echo -------------------------

D:\Users\marcus.william\Developer\dados\%1
