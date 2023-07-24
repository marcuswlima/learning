#include "Rational.h"

int main(){
    Rational r1(3,2);
    Rational r2(1,3);
    r1 = r1.add(r1,r2);
    cout << r1.print() << '\n';
    return 0;
}