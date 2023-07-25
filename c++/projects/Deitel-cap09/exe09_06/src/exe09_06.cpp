#include "Rational.h"

int main(){
    Rational r1(1,2);
    Rational r2(1,3);
	Rational resp(1,1);
    cout << r1.print() << '\n';
    cout << r2.print() << '\n';
    resp = r1.add(r1,r2);
    cout << resp.print() << '\n';
    
	resp = r1.subtrac(r1,r2);
    cout << resp.print() << '\n';
    
	resp = r1.multiply(r1,r2);
    cout << resp.print() << '\n';
    return 0;
}
