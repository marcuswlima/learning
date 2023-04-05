echo off
set OBJ=obj
set SRC=src
set LIB=..\lib
set NOME=notas

echo BarraTitulo.cpp...
g++ -c %LIB%\BarraTitulo.cpp    -o %OBJ%\BarraTitulo.o
if %errorlevel% neq 0 exit /b %errorlevel%

echo Mathematics.cpp...
g++ -c %LIB%\Mathematics.cpp    -o %OBJ%\Mathematics.o
if %errorlevel% neq 0 exit /b %errorlevel%

echo ObterNumero.cpp...
g++ -c %LIB%\ObterNumero.cpp    -o %OBJ%\ObterNumero.o
if %errorlevel% neq 0 exit /b %errorlevel%


echo Nota.cpp...
g++ -c %SRC%\Nota.cpp -o %OBJ%\Nota.o 
if %errorlevel% neq 0 exit /b %errorlevel%

echo Intervalo.cpp...
g++ -c %SRC%\Intervalo.cpp -o %OBJ%\Intervalo.o 
if %errorlevel% neq 0 exit /b %errorlevel%

echo Triade.cpp...
g++ -c %SRC%\Triade.cpp -o %OBJ%\Triade.o 
if %errorlevel% neq 0 exit /b %errorlevel%

echo %NOME%.cpp...
g++ -c %SRC%\%NOME%.cpp -o %OBJ%\%NOME%.o 
if %errorlevel% neq 0 exit /b %errorlevel%

echo linkando tudo...
g++ -Wextra -Werror      ^
     %OBJ%\BarraTitulo.o ^
     %OBJ%\Mathematics.o ^
     %OBJ%\ObterNumero.o ^
     %OBJ%\Nota.o        ^
     %OBJ%\Intervalo.o   ^
     %OBJ%\Triade.o      ^
     %OBJ%\%NOME%.o      ^
        -o %OBJ%\%NOME%.exe        
if %errorlevel% neq 0 exit /b %errorlevel%

echo Executando...
%OBJ%\%NOME%.exe

