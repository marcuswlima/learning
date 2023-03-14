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
    int lado;
    cout << "Informe o lado do quadrado : "  ;
    cin >> lado;

    for (int x=1; x <= lado; x++ )  {
        //cout << x;

        for (int y=1; y <= lado; y++ )
            if ( x==1  ||  x==lado || y == 1 || y == lado )
                cout << "*" ;
            else
                cout << " " ;

        cout << endl;
    }


    cout << endl << endl ;
    return 0;
}

