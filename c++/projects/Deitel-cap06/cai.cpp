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

void respostaErrada(int resposta){
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
    cout << " o certo é "<< resposta << endl;
}

void testeMultiplicacao(int nivel, int operacaoDesejada){


    int a , b , respostaInformada, resposta, certas=0, erradas=0, operacao;


    for (int i=1;i<=10;i++){

        if (operacaoDesejada=5)
            operacao=gerarInteiro(1,4);
        else
            operacao=operacaoDesejada;

        if (nivel==1){
            a = gerarInteiro(1,9);
            b = gerarInteiro(1,9);
        } else {
            a = gerarInteiro(1,100);
            b = gerarInteiro(1,100);

        }

        switch (operacao)
        {
        case 1:
            cout << i << "- Quanto é " << a <<" + " << b << " ? ";
            resposta = a+b;
            break;
        case 2:
            cout << i << "- Quanto é " << a <<" - " << b << " ? ";
            resposta = a-b;
            break;
        case 3:
            cout << i << "- Quanto é " << a <<" * " << b << " ? ";
            resposta = a*b;
            break;
        case 4:
            cout << i << "- Quanto é " << a <<" / " << b << " ? ";
            resposta = a/b;
            break;
        default:
            break;
        }

        cin >> respostaInformada ; 

        if ( respostaInformada == resposta ) {
            respostaCerta();
            certas++;
        }
        else    {
            respostaErrada(resposta);
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


