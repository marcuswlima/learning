echo off
set OBJ=obj
set SRC=src
set LIB=..\lib
set NOME=notas

echo BarraTitulo.cpp...
g++ -c %LIB%\BarraTitulo.cpp    -o %OBJ%\BarraTitulo.o
echo Mathematics.cpp...
g++ -c %LIB%\Mathematics.cpp    -o %OBJ%\Mathematics.o
echo ObterNumero.cpp...
g++ -c %LIB%\ObterNumero.cpp    -o %OBJ%\ObterNumero.o

IF %ERRORLEVEL% EQU 0 ( 
    echo %NOME%.cpp...
    g++ -c %SRC%\%NOME%.cpp -o %OBJ%\%NOME%.o 

    echo Tecla.cpp...
    g++ -c %SRC%\Tecla.cpp -o %OBJ%\Tecla.o 

    echo Intervalo.cpp...
    g++ -c %SRC%\Intervalo.cpp -o %OBJ%\Intervalo.o 
    IF %ERRORLEVEL% EQU 0  (

        echo linkando tudo...
        g++ -Wextra -Werror %OBJ%\Tecla.o %OBJ%\%NOME%.o %OBJ%\ObterNumero.o %OBJ%\BarraTitulo.o %OBJ%\Mathematics.o %OBJ%\Intervalo.o -o %OBJ%\%NOME%.exe        

        IF %ERRORLEVEL% EQU 0  (
            echo Executando...
            %OBJ%\%NOME%.exe
        )
     )
)
