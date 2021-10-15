#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void WeirdAlgorithm (long entrada);

int main()
{
    long entrada;

    cin >> entrada;

    WeirdAlgorithm(entrada);

    return 0;
}

bool ehPar(int entrada){
    int resto = entrada % 2;

    if (resto == 0)
        return true;
    else
        return false;
}

void WeirdAlgorithm (long entrada){

    cout << entrada ; 

    if (entrada == 1)
        cout << endl;
    else {
        cout << " ";

        if (ehPar(entrada))
            entrada /= 2;
        else {
            entrada *= 3;
            entrada += 1;
        }

        WeirdAlgorithm(entrada);
    }
}
