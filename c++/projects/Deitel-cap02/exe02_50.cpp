//Fig 2.22: fig02_21.cpp
//Calculando Juros compostos
#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

int main ( ) {
    int grade,
        aCount = 0,
        bCount = 0,
        cCount = 0,
        dCount = 0,
        fCount = 0,
        notasInformadas = 0;
    double media;

    cout << "Forneça as notas representadas por letras." << endl
         << "Digite o caracter EOF para terminar a entrada de dados" << endl;

    while ( (grade = cin.get() ) != EOF ){
        switch (grade){

            case 'A':
            case 'a':
            ++aCount;
            break;

            case 'B':
            case 'b':
            ++bCount;
            break;

            case 'C':
            case 'c':
            ++cCount;
            break;

            case 'D':
            case 'd':
            ++dCount;
            break;

            case 'F':
            case 'f':
            ++fCount;
            break;

            case '\n':
            case '\t':
            case ' ':
            break;

            default:
            cout << "Forneça uma nova nota [a|b|c|d|f] ou <ctrl+d> para terminar" << endl;
            break;
        } // switch

    } // while

    cout << "\n\nOs Totais para cada nota representada por letra são:" 
            << "\nA : " << aCount
            << "\nB : " << bCount
            << "\nC : " << cCount
            << "\nD : " << dCount
            << "\nF : " << fCount
            << endl;

    notasInformadas = aCount+ bCount+ cCount+ dCount + fCount;
    cout << "Foram informadas "<< notasInformadas << " nota(s)\n";
    media = (aCount*4 + bCount*3 + cCount*2 + dCount) / notasInformadas;
    cout << "media -> "<< media;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}
