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
    int produto;
    for (int i=1; i<=20; ++i) {
        cout << i << " - " ;
        produto = 1;
        for (int y=i; y >= 1; --y) {
            produto *= y;
            cout << y << '\t';
        }

        cout << " - "<<i<<"! = " << produto;

        cout << endl;
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

