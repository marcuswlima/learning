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

    cout << "N\t10*N\t100*N\t1000*N"<< endl << endl;

    for (int i=1; i<=5; i++)
        cout << i     << "\t" 
             << i*10  << "\t" 
             << i*100 << "\t" 
             << i*1000
             << endl;
  cout << endl << endl ;
  return 0;
}

