echo off

set F_LIB=..\lib
set F_OBJ=obj
set F_SRC=src
set APP=%F_OBJ%\%1.exe

echo "%1.cpp..."
g++ -c %F_SRC%/%1.cpp          -o %F_OBJ%/%1.o
if %errorlevel% neq 0 exit /b %errorlevel%

echo linkando tudo...
g++ -Wextra -Werror        ^
     %F_OBJ%/%1.o          ^
        -o %APP%

if %errorlevel% neq 0 exit /b %errorlevel%

echo Executando...
.\%APP%

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::echo "BarraTitulo.cpp..."
::g++ -c %F_LIB%/BarraTitulo.cpp -o %F_OBJ%/BarraTitulo.o
::if %errorlevel% neq 0 exit /b %errorlevel%

::echo "Mathematics.cpp..."
::g++ -c %F_LIB%/Mathematics.cpp -o %F_OBJ%/Mathematics.o
::if %errorlevel% neq 0 exit /b %errorlevel%

::echo "ObterNumero.cpp..."
::g++ -c %F_LIB%/ObterNumero.cpp -o %F_OBJ%/ObterNumero.o
::if %errorlevel% neq 0 exit /b %errorlevel%

::echo "PrintArrey.cpp..."
::g++ -c %F_LIB%/PrintArray.cpp  -o %F_OBJ%/PrintArray.o
::if %errorlevel% neq 0 exit /b %errorlevel%

::g++ -Wextra -Werror        ^
::     %F_OBJ%/%1.o          ^
::     %F_OBJ%/BarraTitulo.o ^
::     %F_OBJ%/Mathematics.o ^
::     %F_OBJ%/ObterNumero.o ^
::     %F_OBJ%/PrintArray.o  ^
::        -o %APP%
