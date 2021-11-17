class Tabuleiro{
public:
    Tabuleiro();
    void imprimir();
    void queimar(int,int);
    int maiorSubscrito();
    void plotar(int[][2],int,int);
private:
    static const int lado=20;
    char tabuleiro[lado][lado]={' '};    
    int movimentos[40][2];
};