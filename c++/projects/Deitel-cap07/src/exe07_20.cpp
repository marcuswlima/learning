#include <iostream>
using std::cout;

#include "../lib/marcusLib.h"

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

Cliente::Cliente(int tipoPassagem=2,int preferenciaAssento=0, bool aceitaSugestao=true){
    setTipoPassagem(tipoPassagem);
    setPreferenciaAssento(preferenciaAssento);
    setAceitaSugestao(aceitaSugestao);
}

void Cliente::setTipoPassagem(int in_tipoPassagem){
    tipoPassagem = in_tipoPassagem;
}

void Cliente::setPreferenciaAssento(int in_preferenciaAssento){
    preferenciaAssento = in_preferenciaAssento;
}

void Cliente::setAceitaSugestao(bool in_aceitaSugestao){
    aceitaSugestao = in_aceitaSugestao;
}

int Cliente::getTipoPassagem(){
    return tipoPassagem;
}

int Cliente::getPreferenciaAssento(){
    return preferenciaAssento;
}

bool Cliente::getAceitaSugestao(){
    return aceitaSugestao;
}

void Cliente::imprimir(){
    cout << "TipoPassagem: "       << getTipoPassagem()       << "\n";
    cout << "PreferenciaAssento: " << getPreferenciaAssento() << "\n";
    cout << "AceitaSugestao: "     << getAceitaSugestao()     << "\n";
}

class Atendimento{
public:
    static const int sizeAssentos=11;

    Atendimento();
    void emitirBilhete(Cliente);
    void atender(Cliente);
    int obterUmaVaga(int);
    void setAssentoVendido(int);
    int getAssentoVendido();
    void mostrarAssentos();
private:    
    int assentos[sizeAssentos];
    int assentoVendido;
    bool estaOcupado(int);
};

Atendimento::Atendimento(){
    for (int i=0; i<Atendimento::sizeAssentos; i++)
        Atendimento::assentos[i]=0;
}

void Atendimento::setAssentoVendido(int assento){
    assentoVendido = assento;
}

int Atendimento::getAssentoVendido(){
    return assentoVendido;
}

bool Atendimento::estaOcupado(int assentoDesejado){
    return Atendimento::assentos[assentoDesejado]==0;
};

int Atendimento::obterUmaVaga(int tipoPassagem){
    int menor, maior ;

    cout << "obter uma vaga" << tipoPassagem<< "\n";
    if (tipoPassagem==1){ // primeira classe
        menor = 1;
        maior = 4;
    }
    else {   // economica
        menor = 5;
        maior = 10;
    }

    cout << menor << maior << "\n";
    for (int i=menor; i<=maior; i++)
        if (!Atendimento::estaOcupado(i)){
            Atendimento::assentos[i]=1;
            return i;
        }

    return -1;

}

void Atendimento::emitirBilhete(Cliente cliente){
    cout << "********* Bilhete";

    if (cliente.getTipoPassagem() == 1)
        cout << "Primeira classe, ";
    else
        cout << "Economica, ";

    cout << "assento: " << Atendimento::getAssentoVendido();
}

void Atendimento::atender(Cliente cliente){
    int assentoLivre;
    if ( cliente.getPreferenciaAssento() == 0 ){  // se não há preferencia 
        assentoLivre = Atendimento::obterUmaVaga(cliente.getTipoPassagem());
        if (assentoLivre > 0){
            Atendimento::setAssentoVendido(assentoLivre);
            emitirBilhete(cliente);
        }
    }
}

void Atendimento::mostrarAssentos(){
    cout << "First Classe\n";
    for (int i=1; i<=4; i++)
        cout << "[" << i << "] " << Atendimento::assentos[i] << " ";
    cout << "\n";
    cout << "Economy\n";
    for (int i=5; i<=10; i++)
        cout << "[" << i << "] " << Atendimento::assentos[i] << " ";

    cout << "\n";
    cout << "\n";
}


int main(){

    //srand( time(0) );

    Atendimento atendimento;

    atendimento.mostrarAssentos();

    for (int i=1; i<=1; i++){

        int TipoPassagem;
        int preferenciaAssento;
        bool aceitaSugestao=true;

        TipoPassagem=gerarInteiro(1,2);
        preferenciaAssento=gerarInteiro(0,1);
        if (preferenciaAssento==1){
            if (TipoPassagem==1)
                preferenciaAssento = gerarInteiro(1,4);
            if (TipoPassagem==2)
                preferenciaAssento = gerarInteiro(5,10);
            
            aceitaSugestao=gerarInteiro(0,1);
        }
        Cliente cliente(TipoPassagem,preferenciaAssento,aceitaSugestao);
        cliente.imprimir();
        
        atendimento.atender(cliente);
        atendimento.mostrarAssentos();

    }



}

