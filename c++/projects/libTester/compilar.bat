echo off
set OBJ=obj
set SRC=src
set LIB=..\lib
set NOME=libTester

echo BarraTitulo.cpp...
g++ -c %LIB%\BarraTitulo.cpp -o %OBJ%\BarraTitulo.o
echo PrintArray.cpp...
g++ -c %LIB%\PrintArray.cpp  -o %OBJ%\PrintArray.o
echo marcusLib.cpp...
g++ -c %LIB%\marcusLib.cpp   -o %OBJ%\marcusLib.o
echo Mathematics.cpp...
g++ -c %LIB%\Mathematics.cpp -o %OBJ%\Mathematics.o
echo ObterNumero.cpp...
g++ -c %LIB%\ObterNumero.cpp -o %OBJ%\ObterNumero.o

IF %ERRORLEVEL% EQU 0 ( 
    g++ -c %SRC%\%NOME%.cpp -o %OBJ%\%NOME%.o 
    echo marcus.cpp...

    IF %ERRORLEVEL% EQU 0  (
        echo linkando tudo...
        g++ -Wextra -Werror %OBJ%\%NOME%.o %OBJ%\ObterNumero.o %OBJ%\BarraTitulo.o %OBJ%\PrintArray.o %OBJ%\marcusLib.o %OBJ%\Mathematics.o -o %OBJ%\%NOME%.exe

        IF %ERRORLEVEL% EQU 0  (
            echo Executando...
            %OBJ%\%NOME%.exe
        )
     )
)
