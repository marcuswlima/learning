#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

#include "Date.h"

int main()
{
    Date date1(3,4,5);
    cout << date1.displayData() << endl;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}