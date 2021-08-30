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

#include <cmath>

int main()
{
    int produto = 1;

    for (int i = 1; i <= 15; i += 2) {
        cout << i << "\t" << (produto *= i) << "\n";
    }

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

