class Tabuleiro{
public:
    Tabuleiro();
    void imprimir();
    void queimar();
    int maiorSubscrito();
    void plotar(int[][2],int,int,int);
    void avancar(int);
    void virarDireita();
    void virarEsquerda();
    //get-set
    void setOrientacao(int);
    int getOrientacao();
    void setX(int);
    int getX();
    void setY(int);
    int getY();
    void setEscrevendo(bool);
    bool getEscrevendo();
private:
    static const int lado=20;
    char tabuleiro[lado][lado];    
    int orientacao,x,y;
    bool escrevendo;
};