#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>


int main()
{
    cout << endl;

    for (int n=1; n<=4; ++n){
        for (int x=1; x<=10; ++x){
            for (int y=1; y <= 10; ++y) {

/*
                if ( n == 1 && x>=y)
                    cout << "*";

                if ( n == 2 && (x+y) <= 6 )
                    cout << "*";

                if ( n == 3 && x<=y)
                    cout << "*";

                if ( n == 4 && (x+y) >= 6 )
                    cout << "*";
*/

                if ( ( n == 1 && x>=y) || ( n == 2 && (x+y) <= 11 ) || ( n == 3 && x<=y) || ( n == 4 && (x+y) >= 11 ) ) 
                    cout << "*";
                else
                    cout << " ";
                ;

                //cout << x << " " << y << " " << x+y ;

                //cout << " ";
            }

            cout << endl;

        }

        cout << endl;
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}


