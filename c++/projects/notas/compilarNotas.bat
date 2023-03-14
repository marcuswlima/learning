echo off
set BASE=D:\Users\marcus.william\Developer\github\learning\c++\Deitel\src\notas
set OBJ=%BASE%\obj

echo **************************************
echo ** Compilando Biblioteca Necessárias
echo **************************************

g++ -c ..\lib\BarraTitulo.cpp -o %OBJ%\BarraTitulo.o
g++ -c ..\lib\PrintArray.cpp  -o %OBJ%\PrintArray.o


IF %ERRORLEVEL% EQU 0 ( 
    echo **************************************
    echo ** Compilando Solução
    echo **************************************

    g++ -c src\Tecla.cpp  -o %OBJ%\Tecla.o 
    SET err_tecla=%ERRORLEVEL%
    g++ -c src\notas2.cpp -o %OBJ%\nota.o 
    SET err_nota = %ERRORLEVEL%

    IF %ERRORLEVEL% EQU 0  (
        echo **************************************
        echo ** Linkando...
        echo **************************************
        g++ -Wextra -Werror  %OBJ%\BarraTitulo.o %OBJ%\Tecla.o  %OBJ%\nota.o -o %OBJ%\notas.exe

        IF %ERRORLEVEL% EQU 0  (
            echo **************************************
            echo ** Executando
            echo **************************************
            %OBJ%\notas.exe
        )
     )
)
