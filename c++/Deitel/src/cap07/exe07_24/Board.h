class Celula{
public:
    void setBit(int);
     int getBit();
    void setOrdem(int);
     int getOrdem();
private:
     int bit;
     int ordem;
};

class Board{
public:
         Board();
    void setCurrentRow(int);
     int getCurrentRow();
    void setCurrentColumn(int);
     int getCurrentColumn();
    void movimentar();
    void setInicio(int,int);
    void marcar(int,int,int);
     int marcado(int,int);
    void imprimirOcupacao();
    void imprimirOrdem();
    void zerar();
private:
  static const int colunas=8;
     int board[colunas][colunas];
  Celula board2[colunas][colunas];
     int currentRow;
     int currentColumn;
     int horizontal[colunas];
     int vertical[colunas];
};