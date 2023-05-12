
class Board{
public:
         Board();
    void movimentar();
    void moveHeuristcAccessibility(int,int);
    void setInicio(int,int);
    void zerar();
    void imprimirMovimentos();
    void imprimirAccessibility();
private:
  static const int colunas=8;
     int board[colunas][colunas];
     int accessibility[colunas][colunas];
     int currentRow;
     int currentColumn;
     int horizontal[colunas];
     int vertical[colunas];
//---------------------------------------
     int setAccessibility(int, int);
     int marcado(int,int);
    void marcar(int);
    void imprimirBoard(int[][colunas]);
    void setCurrentRow(int);
     int getCurrentRow();
    void setCurrentColumn(int);
     int getCurrentColumn();
    void downAccessibility();
};