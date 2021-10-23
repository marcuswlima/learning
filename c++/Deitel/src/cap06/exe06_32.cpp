#include <iostream>
using std::cout;
using std::endl;
#include "cap06.h"

int main(){

    int a, b; 


    for (int i=1;i<=100; i++){
        a = gerarInteiro (1,100);
        b = gerarInteiro (1,100);
        cout << "MDC("<< a << "," << b << ")=" << mdc(a,b) << " | ";
    }

    return 0;

}

