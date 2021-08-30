#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )


#include <iomanip>

using std::setprecision;
using std::setiosflags;

#include <cmath>

int main()
{
    for (int i=2 ; i<=10000000000 ; i++)
        if ( i % 2 == 0 )
            cout << i << '\t' << i*2 << '\n';


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

