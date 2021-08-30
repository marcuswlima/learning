

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setiosflags;
using std::fixed;
using std::setprecision;
using std::setw;


#include <cmath>

using std::ios;


int main()
{

    cout << setiosflags( ios::fixed | ios::showpoint )
         << setprecision(2)
         << "sqrt(" << 900.0 << ") = " << sqrt(900.0)
         << "\nsqrt(" << 9.0 << ") = " << sqrt(9.0)
         ;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

