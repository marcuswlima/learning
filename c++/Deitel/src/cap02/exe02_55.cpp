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
{
    int encontradas = 0;
    
    for (int l1=1; l1<=50; ++l1) 
        for (int l2=1; l2<=50; ++l2)
            for (int l3=1; l3<=50; ++l3)

                if ( pow(l1,2)==pow(l2,2)+pow(l3,2) || pow(l2,2)==pow(l1,2)+pow(l3,2) || pow(l3,2)==pow(l1,2)+pow(l2,2) ){
                    cout << ++encontradas << "\t" << l1 << "\t" << l2 << "\t" << l3 ;
                    cout << endl;
                }

    

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

