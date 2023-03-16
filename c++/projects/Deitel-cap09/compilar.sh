
OBJ=obj
SRC=src
LIB=../lib

echo "BarraTitulo.cpp..."
g++ -c $LIB/BarraTitulo.cpp  -o $OBJ/BarraTitulo.o
echo "PrintArray.cpp..."
g++ -c $LIB/PrintArray.cpp   -o $OBJ/PrintArray.o
echo "Mathematics.cpp..."
g++ -c $LIB/Mathematics.cpp  -o $OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $LIB/ObterNumero.cpp  -o $OBJ/ObterNumero.o

if [ $? -eq 0 ]; then

    echo "Compilando Solução..."
    g++ -c $SRC/marcus.cpp     -o $OBJ/marcus.o 

    if [ $? -eq 0 ]; then

        echo "Linkando....               "
        g++ $OBJ/marcus.o      \
            $OBJ/BarraTitulo.o \
            $OBJ/PrintArray.o  \
            $OBJ/Mathematics.o \
            $OBJ/ObterNumero.o \
                -o $OBJ/marcus.sh

        if [ $? -eq 0 ]; then
            echo "Executando....               "
            $OBJ/marcus.sh

        fi

    fi

fi

