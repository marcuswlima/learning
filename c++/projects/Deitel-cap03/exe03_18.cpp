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

int integerPower(int base, int expoent);

int main()
{
    cout << integerPower(2,0) << endl;
    cout << integerPower(2,1) << endl;
    cout << integerPower(2,2) << endl;
    cout << integerPower(2,3) << endl;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

int integerPower(int base, int expoent){
    int resposta=1;

    if (expoent==0)
        resposta = 1;
    else 
        for (int i=1; i<=expoent; i++)
            resposta *= base;
    
    return resposta;

}