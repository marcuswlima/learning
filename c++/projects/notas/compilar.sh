
OBJ=obj
SRC=src
LIB=../lib
NOME=notas

echo "BarraTitulo.cpp..."
g++ -c $LIB/BarraTitulo.cpp    -o $OBJ/BarraTitulo.o
echo "PrintArray.cpp..."
g++ -c $LIB/PrintArray.cpp     -o $OBJ/PrintArray.o
echo "Mathematics.cpp..."
g++ -c $LIB/Mathematics.cpp    -o $OBJ/Mathematics.o
echo "ObterNumero.cpp..."
g++ -c $LIB/ObterNumero.cpp    -o $OBJ/ObterNumero.o

if [ $? -eq 0 ]; then

    echo "Compilando $NOME..."
    g++ -c $SRC/$NOME.cpp -o $OBJ/$NOME.o 
	echo "Intervalo.cpp..."
	g++ -c $SRC/Intervalo.cpp -o $OBJ/Intervalo.o
	echo "Triade.cpp..."
	g++ -c $SRC/Triade.cpp -o $OBJ/Triade.o
	echo "Nota.cpp..."
	g++ -c $SRC/Nota.cpp -o $OBJ/Nota.o

    if [ $? -eq 0 ]; then

        echo "Linkando...."
        g++ $OBJ/BarraTitulo.o \
            $OBJ/PrintArray.o  \
            $OBJ/Mathematics.o \
            $OBJ/ObterNumero.o \
            $OBJ/$NOME.o       \
            $OBJ/Nota.o        \
            $OBJ/Intervalo.o   \
            $OBJ/Triade.o      \
                -o $OBJ/$NOME.sh

        if [ $? -eq 0 ]; then
            echo "Executando...."
            $OBJ/$NOME.sh

        fi

    fi

fi

