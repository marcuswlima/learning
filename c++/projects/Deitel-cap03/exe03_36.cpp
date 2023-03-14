#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

void testeMultiplicacao();

int main()
{
    srand( time(0) );

    testeMultiplicacao();

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

void respostaCerta(){
    int nResposta = gerarInteiro(1,4);

    switch (nResposta) {
        case 1:
            cout << "Muito Bem !!";
            break;
        case 2:
            cout << "Excelente !";
            break;
        case 3:
            cout << "Bom trabalho !";
            break;
        case 4:
            cout << "Carto! Continue assim";
            break;
        default:
            break;
    }
    cout << endl;
}

void respostaErrada(){
    int nResposta = gerarInteiro(1,4);

    switch (nResposta) {
        case 1:
            cout << "Não. Tente novamente";
            break;
        case 2:
            cout << "Errado. Tente outra vez";
            break;
        case 3:
            cout << "Não desista!";
            break;
        case 4:
            cout << "Vai estudar !!!";
            break;
        default:
            break;
    }
    cout << endl;
}

void testeMultiplicacao(){
    int a = gerarInteiro(1,9), b = gerarInteiro(1,9), resultado;

    cout << "Quanto é " << a <<" vezes " << b << " ? ";
    cin >> resultado ; 

    if (resultado == (a*b))
        respostaCerta();
    else    {
        respostaErrada();
        testeMultiplicacao();
    }

}


