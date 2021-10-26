#include <iostream>
using std::cout;
using std::endl;
#include "cap06.h"

int main(){
    
    int a, b; 


    for (int i=1;i<=30; i++){
        a = gerarInteiro (1,20);
        b = gerarInteiro (1,20);
        cout << "MDC("<< a << "," << b << ")=" << mdc_r(a,b) << endl;
    }


}