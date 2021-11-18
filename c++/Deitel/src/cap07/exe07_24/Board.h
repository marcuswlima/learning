class Board{
public:
    Board();
    void setCurrentRow(int);
    int getCurrentRow();
    void setCurrentColumn(int);
    int getCurrentColumn();
    void movimentar();
    void setInicio(int,int);
private:
    static const int colunas=8;
    int board[colunas][colunas][2];
    int currentRow;
    int currentColumn;
    int horizontal[colunas];
    int vertical[colunas];
};