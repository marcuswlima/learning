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


int main()
{
    int x, y;

    x = 5;

    y = floor ( x * 100 + .5 ) /100 ;
    cout << y ;
 

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

