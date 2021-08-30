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
    int row = 10,column;

    while (row >= 1) {
        column  = 1;

        while ( column <= 10 ) {
            cout << ( row % 2 ? "<" : ">");
            ++column;
        }

        --row;

        cout << endl;
    }

  return 0;
}

