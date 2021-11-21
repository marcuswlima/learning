#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

// Protótipos
void imprimirTabuleiro(int [][8], string titulo="tabela[8][8]");
 int quantosAlcanca(int, int);
void marcar(int [][8], int , int , int );
bool EhAlcancavel(int ,int , int , int );
void posicionarDama(int, int , int);
void posicionarDamas(int , int, bool mostraTabuleiro=false ) ;
bool estahEliminado(int, int);
void posicionarDamasComHeuristica(int , int , bool );

// Variáveis globais
const int lado=8;
int tabuleiro[lado][lado];
int alcancados[lado][lado];
int eliminados[lado][lado];

int main(){


    // marcarQtdEliminados
    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++)
            alcancados[x][y]=quantosAlcanca(x,y);

    imprimirTabuleiro(alcancados,"alcancados");


    for(int x=0 ; x<lado ; x++)
        for(int y=0 ; y<lado ; y++);
            //posicionarDamas(x,y);


//    posicionarDamas(5,0,true);
//    posicionarDamas(5,2,true);
    posicionarDamas(4,4,true);
    posicionarDamasComHeuristica(4,4,true);



    return 0;
   
}

void imprimirTabuleiro(int arrei[][8], string titulo){
    cout << "\n";
    cout << titulo << "\n";
    cout <<"------------------------------------------\n"; 
    cout <<" |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |\n";
    cout <<"------------------------------------------\n"; 


    for (int x=0; x<lado; x++){
        cout << x << "| ";
        for (int y=0; y<lado; y++)
            cout << setw(2) << arrei[x][y]<< " | ";
        cout << "\n";
    }

    cout <<"------------------------------------------\n"; 

}

void marcar(int arrei[][8], int x, int y, int valor){
    arrei[x][y]=valor;
}

bool EstaoMesmaColuna(int x1,int y1, int x2, int y2){
    return y1==y2;
}

bool EstaoMesmaLinha(int x1,int y1, int x2, int y2){
    return x1==x2;
}

bool EstaoMesmaDiagonal(int x1,int y1, int x2, int y2){
    return (x1+y1==x2+y2) || (x1-y1==x2-y2);
}

int quantosAlcanca(int x, int y){
    int contador=0;
    for(int row=0 ; row<lado ; row++)
        for(int col=0 ; col<lado ; col++)
            if (EhAlcancavel(x,y,row,col) ) 
                contador++;
    
    return contador;
}

bool EhAlcancavel(int x1,int y1, int x2, int y2){
    return EstaoMesmaColuna(x1,y1,x2,y2) || EstaoMesmaLinha(x1,y1,x2,y2) || EstaoMesmaDiagonal(x1,y1,x2,y2);
}

void eliminarAlcancados(int x, int y, int valor){

    for(int row=0 ; row<lado ; row++)
        for(int col=0 ; col<lado ; col++)
            if (EhAlcancavel(x,y,row,col)) 
                marcar(eliminados,row,col,valor);

}


void posicionarDama(int x, int y, int valor){
    marcar(tabuleiro,x,y,valor);

    eliminarAlcancados(x, y, valor);
}

bool estahEliminado(int x, int y){
    return eliminados[x][y]!=0;
}

void zerarTabuleiros(){
    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++){
            tabuleiro[x][y]=0;
            alcancados[x][y]=0;
            eliminados[x][y]=0;
        }
}

string descricaoVolta(int volta){

    string resposta;
    switch (volta)
    {
        case 1:resposta = "um";break;
        case 2:resposta = "dois";break;
        case 3:resposta = "trẽs";break;
        case 4:resposta = "quatro";break;
        case 5:resposta = "cinco";break;
        case 6:resposta = "seis";break;
        case 7:resposta = "sete";break;
    default:
        break;
    }

    return resposta;
}




void posicionarDamas(int currentX, int currentY, bool mostraTabuleiro){

    bool fazer;
    int voltas=0;

    zerarTabuleiros();

    cout << "[" << currentX << "," << currentY << "] ";

    for(int volta=1;volta<=10; volta++){

        voltas++;

        posicionarDama(currentX,currentY,volta);

        for(int x=0 ; x<lado ; x++){
            for(int y=0 ; y<lado ; y++){

                fazer = tabuleiro[x][y]==0 && 
                        !EhAlcancavel(currentX,currentY,x,y) &&
                        !estahEliminado(x,y)
                        ;

                if (fazer){ // sair do laço de coluna
                    currentX = x;
                    currentY = y;
                    break;
                };
                
            }

            if (fazer){ // sair do laço de linha
                break;
            };

        }

        if (!fazer){ // sair do laço colunas
            break;
        };


    }

    cout << "voltas: " << voltas << "\n";

    if (mostraTabuleiro){
        imprimirTabuleiro(tabuleiro,"s/ heuristica");
        cout << "\n";
    }
}

void posicionarDamasComHeuristica(int currentX, int currentY, bool mostraTabuleiro){
    bool fazer;
    int voltas=0;

    int smallest  = 99999,
        smallestX = currentX,
        smallestY = currentY;

    zerarTabuleiros();

    cout << "[" << smallestX << "," << smallestY << "] \n";

    for(int posicionamento=1;posicionamento<=2; posicionamento++){

        voltas++;

        posicionarDama(smallestX,smallestY,posicionamento);

        for(int x=0 ; x<lado ; x++){
            for(int y=0 ; y<lado ; y++){


                fazer = tabuleiro[x][y]==0 && 
                        !EhAlcancavel(smallestX,smallestY,x,y) &&
                        !estahEliminado(x,y) &&
                        alcancados[x][y] < smallest
                        ;

                cout << posicionamento << " " << smallestX << " " << smallestY << " " << x << " " << y << "-" << fazer << "\n";


                if (fazer){ // sair do laço de coluna
                    smallest = alcancados[x][y];
                    smallestX = x;
                    smallestY = y;
                };

            }

        }

    }



    cout << "voltas: " << voltas << "\n";

    if (mostraTabuleiro){
        imprimirTabuleiro(tabuleiro,"c/ heuristica");
        cout << "\n";
    }
}