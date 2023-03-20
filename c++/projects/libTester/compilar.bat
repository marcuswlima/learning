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
echo SystemNumeral.cpp...
g++ -c %LIB%\SystemNumeral.cpp  -o %LIB%\SystemNumeral.o

IF %ERRORLEVEL% EQU 0 ( 
    echo %SRC%\%NOME%.cpp...
    g++ -c %SRC%\%NOME%.cpp -o %OBJ%\%NOME%.o 

    IF %ERRORLEVEL% EQU 0  (
        g++ -Wextra -Werror %OBJ%\%NOME%.o %OBJ%\ObterNumero.o %OBJ%\BarraTitulo.o %OBJ%\PrintArray.o %OBJ%\marcusLib.o %OBJ%\Mathematics.o %LIB%\SystemNumeral.o -o %OBJ%\%NOME%.exe
        echo linkando tudo...

        IF %ERRORLEVEL% EQU 0  (
            echo Executando...
            %OBJ%\%NOME%.exe
        )
     )
)
