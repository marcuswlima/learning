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

int gerarInteiro(int menor, int maior);
int quociente(int a, int b);
int resto(int a, int b);
void separar(int inteiro);

int main()
{
    int a, b, inteiro;

    srand( time(0) );


    cout << "a\tb\tquociente\tresto" << endl;

    for (int i=1;i<=10;i++){
        a = gerarInteiro(1,10);
        b = gerarInteiro(1,10);



        cout << setw(2) << a << "\t" << setw(2) << b << "\t" << quociente(a,b) << "\t\t" << resto(a,b) << endl;
    }

    inteiro = gerarInteiro(1,32767);
    inteiro = 15001;

    cout << inteiro << endl;

    separar(inteiro);




//--------------------------------------------
    cout << endl << endl ;
    return 0;
}


int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);
}

int quociente(int a, int b){
    return a / b;
}

int resto(int a, int b){
    return a % b;
}

void separar(int inteiro ){
    int decimal;

    if (inteiro > 10000)
        decimal = 10000;
    else
        if (inteiro > 1000)
            decimal = 1000;
        else
            if (inteiro > 100)
                decimal = 100;
            else 
                if (inteiro > 10)
                    decimal = 10;
                else 
                    decimal = 1;

    if (decimal==1)
        cout << inteiro << endl;
    else {
        cout << quociente (inteiro,decimal) << " ";
        inteiro = resto (inteiro,decimal);
        separar(inteiro);
    }
}

