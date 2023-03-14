
OBJ=obj
SRC=src

echo " "
echo "***************************************"
echo "** Compilando Biblioteca Necessárias"
echo "***************************************"
echo " "

g++ -c ../lib/BarraTitulo.cpp -o $OBJ/BarraTitulo.o
g++ -c ../lib/PrintArray.cpp  -o $OBJ/PrintArray.o

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

        g++ $OBJ/marcus.o $OBJ/BarraTitulo.o $OBJ/PrintArray.o -o $OBJ/marcus.sh

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

