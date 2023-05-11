#include "Board.h"

//#include "..\..\lib\marcusLib.h"
#include "../../lib/marcusLib.h"

int main(){
    Board board;

/*
    for (int x=0; x<=7; x++)
        for (int y=0; y<=7; y++){
            board.zerar();
            board.setInicio(x,y);
            board.movimentar();
            //board.imprimirOrdem();

        }

    board.zerar();
    board.setInicio(3,4);
    board.movimentar();
    board.imprimirMovimentos();
    board.imprimirAccessibility();
*/
    for (int i=0; i<=2; i++)
        for (int y=0; y<=2; y++){
            board.moveHeuristcAccessibility(i,y);
            board.imprimirMovimentos();

            board.zerar();
            board.setInicio(i,y);
            board.movimentar();
            board.imprimirMovimentos();
 
        }

    return 0;
}