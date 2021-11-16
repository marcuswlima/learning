class Cliente{
public:
    Cliente(int,int,bool);
    void setTipoPassagem(int);
    void setPreferenciaAssento(int);
    void setAceitaSugestao(bool);
    int getTipoPassagem();
    int getPreferenciaAssento();
    bool getAceitaSugestao();
    void imprimir();
private:
    int rg;
    int tipoPassagem;
    int preferenciaAssento;
    bool aceitaSugestao;
};
