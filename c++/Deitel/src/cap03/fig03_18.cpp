#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

using std::setprecision;
using std::setiosflags;
using std::setw;


void function1();

int main()
{


    int x=2 ;
    cout << x << endl;
    {
        int x=3 ;
        cout << x << endl;

        {
            int x=4 ;
            cout << x << endl;

        }


    }

    cout << x << endl;
//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

void function1(){
    cout << "function1 não recebe argumentos"       ;
    //return 0;
};