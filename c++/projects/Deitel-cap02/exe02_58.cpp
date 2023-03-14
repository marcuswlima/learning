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

    int numero = 7, meio;

    meio = (numero/2)+1;

    cout << meio << endl;


    for (int x=1; x<=numero; x++) {
        for (int y=1; y<=numero; y++ ) {
            cout << x << "," << y << "," << x+y ;
            cout << '\t';
        }
        cout << endl;
    }

    cout << endl;
    for (int x=1; x<=numero; x++) {

        for (int y=1; y<=numero; y++ ) {

            if ( //!(x+y<=meio) || 
            (  x>meio && y<meio)
               )
                cout << x << "," << y;// << "," << x+y ;
            else
                cout << " ";

            cout << '\t';

        }

        cout << endl;

    }


  cout << endl << endl ;
  return 0;
}

