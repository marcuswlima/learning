#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "cap06.h"

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


    int a , b , resposta, certas=0, erradas=0;

    for (int i=1;i<=10;i++){

        a = gerarInteiro(1,9);
        b = gerarInteiro(1,9);

        cout << i << "- Quanto é " << a <<" vezes " << b << " ? ";
        cin >> resposta ; 

        if (resposta == (a*b)){
            respostaCerta();
            certas++;
        }
        else    {
            respostaErrada();
            erradas++;
        }
    }

    cout << endl;
    cout << "certas -> " << certas  << endl;
    cout << "errdas -> " << erradas << endl;

    if (erradas > 7){
        cout << endl;
        cout << "Solicite ajuda extra do profressor";
    }
}


