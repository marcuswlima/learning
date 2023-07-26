#include "Rational.h"

int main(){
    Rational r1(2,2);
    Rational r2(10,3);
    cout << r1.print() << '\n';
    cout << r2.print() << '\n';

	Rational resp(1,1);
    resp = r1.add(r1,r2);
    cout << "add " << resp.print() << '\n';
    cout << "add " << resp.printd() << '\n';
    
	resp = r1.subtrac(r1,r2);
    cout << "subtrac " << resp.print() << '\n';
    
	resp = r1.multiply(r1,r2);
    cout << "multiply " << resp.print() << '\n';

	resp = r1.divide(r1,r2);
    cout << "divide " << resp.print() << '\n';
    return 0;
}
