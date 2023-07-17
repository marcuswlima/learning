#include <iostream>

class Mae {
  public:
    virtual void mensagem(){
      std::cout << "eu sou a mãe" << '\n';
    }
};

class Filha : public Mae {
  public:
    void mensagem(){
      std::cout << "eu sou a filha" << '\n';
    }
};

class Neta : public Filha {
  public:
    void mensagem(){
      std::cout << "eu sou a neta" << '\n';
    }
};

class Bisneta: public Neta {
};


void responde( Mae * m ){
  m->mensagem();
}

int main( int argc , char **argv ){

  Mae m;
  Filha f;
  Neta n;
  Bisneta bn;

  m.mensagem();
  f.mensagem();
  n.mensagem();
  
  std::cout << "\n---------------------\n";

  responde( &m );
  responde( &f );
  responde( &n );

  return 0;
}

