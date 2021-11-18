#include "Board.h"

int main(){
    Board board;

    for (int x=0; x<=7; x++)
        for (int y=0; y<=7; y++){
            board.zerar();
            board.setInicio(x,y);
            board.movimentar();
            //board.imprimirOrdem();

        }
    
    return 0;
}