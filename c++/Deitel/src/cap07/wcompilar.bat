echo off
set dados=D:\Users\marcus.william\Developer\_dados\c++
set BIN=%dados%\%1.exe
set OBJ=%dados%\%1.o
set ML=%dados%\marcusLib.o

echo ** Deleting...
del %BIN%
del %OBJ%
del %ML%

echo ** Compiling...

g++ -c ../lib/marcusLib.cpp -o %ML%
g++ -c %1.cpp               -o %OBJ%

echo ** Linking...

g++ -Wextra -Werror %ML% %OBJ% -o %BIN%

echo ** Executing...
echo -------------------------

%BIN%


