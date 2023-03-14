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

double hypotenuse (double c1, double c2);

int main()
{
    int t;
    double c1, c2;

    cout << setprecision(2) << setiosflags( ios::fixed | ios::showpoint );

    cout << "Triangulo\tLado1\tLado2\tHypotenuse" << endl ;

    t  = 1  ;
    c1 = 3.0;
    c2 = 4.0;
    cout <<t<<"\t\t"<<c1<<"\t"<<c2<<"\t"<<hypotenuse(c1,c2)<<endl ;

    t  =  2  ;
    c1 =  5.0;
    c2 = 12.0;
    cout <<t<<"\t\t"<<c1<<"\t"<<c2<<"\t"<<hypotenuse(c1,c2)<<endl ;

    t  =  3  ;
    c1 =  8.0;
    c2 = 15.0;
    cout <<t<<"\t\t"<<c1<<"\t"<<c2<<"\t"<<hypotenuse(c1,c2)<<endl ;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

double integerPower(double base, int expoent){

    double resposta=1;

    if (expoent==0)
        resposta = 1;
    else 
        for (int i=1; i<=expoent; i++)
            resposta *= base;
    
    return resposta;

}

double hypotenuse (double in_c1, double in_c2){

    return sqrt ( integerPower(in_c1,2) + integerPower(in_c2,2) );

}
