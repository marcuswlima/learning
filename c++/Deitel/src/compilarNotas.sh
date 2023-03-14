OBJ=notas/obj
SRC=notas/src

echo " "
echo "***************************************"
echo "** Compilando Biblioteca Externa"
echo "***************************************"
echo " "

lib/cplusplus/compilarLib $OBJ

if [ $? -eq 0 ]; then

    echo " "
    echo "******************************"
    echo "** Compilando Solução"
    echo "******************************"
    echo " "

    g++ -c $SRC/Tecla.cpp     -o $OBJ/Tecla.o 
    erroTecla=$?

    g++ -c $SRC/Intervalo.cpp -o $OBJ/Intervalo.o 
    erroIntervalo=$?

    g++ -c $SRC/notas2.cpp    -o $OBJ/notas.o 
    erronota=$?

    g++ -c $SRC/Triade.cpp    -o $OBJ/Triade.o 
    erroTriade=$?

    if [ $erroTecla -eq 0 ] && [ $erroIntervalo -eq 0 ] && [ $erronota -eq 0 ]&& [ $erroTriade -eq 0 ]; then

        echo " "
        echo "******************************"
        echo "** Linkando....               "
        echo "******************************"
        echo " "

        g++ $OBJ/notas.o       \
            $OBJ/Tecla.o       \
            $OBJ/BarraTitulo.o \
            $OBJ/Intervalo.o   \
            $OBJ/Triade.o      \
                -o $OBJ/notas.sh


        if [ $? -eq 0 ]; then

            echo " "
            echo "******************************"
            echo "** Executando....               "
            echo "******************************"
            echo " "
            $OBJ/notas.sh

        fi

    fi

fi

