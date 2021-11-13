#include <iostream>
using std::cout;

#include "../lib/marcusLib.h"

int main(){
    srand( time(0) );

    int arreiSaise;
    char caracteres[]="0123456789";
    cout << caracteres[6] << "\n";

    //b)
    arreiSaise=3;
    double b[arreiSaise]={0,1,2};
    b[3]=4;

    //c)
    arreiSaise=5;
    int g[arreiSaise];
    for (int i=0; i<arreiSaise; i++)
        g[i]=8;
    mostarArray(g,arreiSaise);

    ///d)
    cout << "***** d) ********\n";
    arreiSaise=100;
    double c[arreiSaise], soma=0;
    for (int i=0; i<arreiSaise; i++)
        c[i]=gerarDouble(1,100);
    mostarArray(c,arreiSaise);
    for (int i=0; i<arreiSaise; i++)
        soma += c[i];
    cout << "A soma é " << soma << "\n";

    ///e)
    cout << "***** e) ********\n";
    int arreiSaiseA=11;
    int arreiSaiseB=34;
    double aa[arreiSaiseA];
    double bb[arreiSaiseB];
    for (int i=0; i<arreiSaiseA; i++)
        aa[i]=gerarDouble(1,100);
    cout << "*aa ";
    mostarArray(aa,arreiSaiseA);
    for (int i=0; i<arreiSaiseB; i++)
        bb[i]=gerarDouble(1,100);
    cout << "*bb ";
    mostarArray(bb,arreiSaiseB);
    for (int i=0; i<arreiSaiseA; i++)
        bb[i] = aa[i];
    cout << "*bb ";
    mostarArray(bb,arreiSaiseB);

    ///f)
    cout << "***** f) ********\n";
    const int sizeW=9;
    double w[sizeW];
    for (int i=0; i<sizeW; i++)
        w[i]=gerarDouble(0,1);
    cout << "*w ";
    mostarArray(w,sizeW);

}