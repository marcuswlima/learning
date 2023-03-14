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

    int x=11, y=9;

    if (x < 10)
        if (y > 10)
            cout << "*****" << endl;
        else    
            cout << "#####" << endl;
    cout << "$$$$$" << endl;

    if ( x < 10 ) {
        if (y > 10)
            cout << "*****" << endl;
    }
    else {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
    }


  cout << endl << endl ;
  return 0;
}

