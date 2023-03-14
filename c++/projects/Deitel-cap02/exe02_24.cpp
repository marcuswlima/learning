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

    int count = 1;

    while ( count <= 10) {
        cout << count ;

        cout << ( count % 2 ? "****" : "++++++++") << endl;

        ++count;
    }
  cout << endl << endl ;
  return 0;
}

