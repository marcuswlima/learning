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

int x=1;

int main()
{

    cout << x << endl;

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

