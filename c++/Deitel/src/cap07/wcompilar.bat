echo off
set dados=D:\Users\marcus.william\Developer\dados
set BIN=%dados%\%1.exe
set OBJ=%dados%\%1.o
set ML=%dados%\marcusLib.o

echo Deletando...
del %BIN%
del %OBJ%
del %ML%

echo Compiling and Liking...

g++ -c ../lib/marcusLib.cpp -o %ML%
g++ -c %1.cpp               -o %OBJ%

g++ -Wextra -Werror %ML% %OBJ% -o %BIN%

echo Executando...
echo -------------------------

%BIN%


