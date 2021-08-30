#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>      // std::setw


int main () 
{   
    int c;

    c = 5;
    cout <<  c    << endl;
    cout <<  c++  << endl;
    cout <<  c    << endl<< endl;

    c = 5;
    cout <<  c    << endl;
    cout <<  ++c  << endl;
    cout <<  c    << endl;

    std::cout << std::setw(5);
    std::cout << 77 << std::endl;


    return 0;

}