#include <iostream>

using std::cout;
using std::endl;

#include "cap06.h"

int main(){

    int countPrime=0, limiteSuperior=10000;

    for (int i=1;i<=limiteSuperior;i++){
        if (prime(i)){
            countPrime++;
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "entre 1 e "<< limiteSuperior <<" existe(m) "<< countPrime << endl;

    return 0;

}