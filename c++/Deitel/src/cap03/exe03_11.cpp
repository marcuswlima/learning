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

int main()
{
    double x;

    x=fabs(7.5);   cout << "fabs(7.5) -> " << x << endl;
    x=ceil(7.5);  cout << "ceil(7.5) -> " << x << endl;
    x=floor(7.5);  cout << "floor(7.5) -> " << x << endl;
    x=fabs(0.0);   cout << "fabs(0.0) -> " << x << endl;
    x=ceil(0.0);   cout << "ceil(0.0) -> " << x << endl;
    x=fabs(-6.4);  cout << "fabs(-6.4) -> " << x << endl;
    x=ceil(-6.4);  cout << "ceil(-6.4) -> " << x << endl;
    x=floor(-6.4);  cout << "floor(-6.4) -> " << x << endl;

    cout << ceil(-fabs(-8 + floor ( -5.5))) << endl;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

