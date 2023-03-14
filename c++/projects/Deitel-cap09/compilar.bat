echo off
set OBJ=obj
set SRC=src
set LIB=..\lib

g++ -c %LIB%\BarraTitulo.cpp -o %OBJ%\BarraTitulo.o
echo BarraTitulo.cpp...
g++ -c %LIB%\PrintArray.cpp  -o %OBJ%\PrintArray.o
echo PrintArray.cpp...
g++ -c %LIB%\marcusLib.cpp   -o %OBJ%\marcusLib.o
echo marcusLib.cpp...
g++ -c %LIB%\Mathematics.cpp  -o %OBJ%\Mathematics.o
echo Mathematics.cpp...

IF %ERRORLEVEL% EQU 0 ( 
    g++ -c %SRC%\marcus.cpp  -o %OBJ%\marcus.o 
    echo marcus.cpp...

    IF %ERRORLEVEL% EQU 0  (
        echo linkando tudo...
        g++ -Wextra -Werror %OBJ%\marcus.o %OBJ%\BarraTitulo.o %OBJ%\PrintArray.o %OBJ%\marcusLib.o %OBJ%\Mathematics.o -o %OBJ%\marcus.exe

        IF %ERRORLEVEL% EQU 0  (
            echo Executando...
            %OBJ%\marcus.exe
        )
     )
)
