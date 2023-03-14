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


int main()
{

    for (int x=1; x<=16; x++) {

        for (int y=1; y<=16; y++ ) {

            if ( ( x + y ) % 2  == 0 )
                cout << "*";
            else
                cout << " " ;
        }

        cout << endl;

    }


  cout << endl << endl ;
  return 0;
}

