
OBJ=obj
SRC=src
LIB=../lib

echo " "
echo "***************************************"
echo "** Compilando Biblioteca Necessárias"
echo "***************************************"
echo " "

g++ -c $LIB/BarraTitulo.cpp  -o $OBJ/BarraTitulo.o
g++ -c $LIB/PrintArray.cpp   -o $OBJ/PrintArray.o
g++ -c $LIB/Mathematics.cpp  -o $OBJ/Mathematics.o

if [ $? -eq 0 ]; then

    echo " "
    echo "******************************"
    echo "** Compilando Solução"
    echo "******************************"
    echo " "

    g++ -c $SRC/marcus.cpp     -o $OBJ/marcus.o 

    if [ $? -eq 0 ]; then

        echo " "
        echo "******************************"
        echo "** Linkando....               "
        echo "******************************"
        echo " "

        g++ $OBJ/marcus.o      \
            $OBJ/BarraTitulo.o \
            $OBJ/PrintArray.o  \
            $OBJ/Mathematics.o \
                -o $OBJ/marcus.sh

        if [ $? -eq 0 ]; then

            echo " "
            echo "******************************"
            echo "** Executando....               "
            echo "******************************"
            echo " "
            $OBJ/marcus.sh

        fi

    fi

fi

