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
{  int n1, n2, n3, n4, n5, temp;

  cin  >> n1 >> n2 >> n3 >> n4 >> n5  ;

    cout << endl;

    for (int n=1; n<=5; ++n) {
        switch (n) {
            case 1: temp = n1; break;
            case 2: temp = n2; break;
            case 3: temp = n3; break;
            case 4: temp = n4; break;
            case 5: temp = n5; break;
        }

        cout << temp << " - ";
        for (int i=1; i<= temp; ++i){
            cout << "*";
        }

        cout << endl;
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

