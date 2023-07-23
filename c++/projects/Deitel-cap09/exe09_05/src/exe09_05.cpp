
#include "Complex.h"

int main(){
    Complex c0;
    Complex c1(1,1);
    Complex c2(2,2);
    Complex c3(3,3);
    cout << c0.cprint() << endl;
    cout << c1.cprint() << endl;
    cout << c2.cprint() << endl;
    cout << c3.cprint() << endl;
    c1.add(c2);
    cout << c1.cprint() << endl;
    c3.subtrac(c0);
    cout << c3.cprint() << endl;
}