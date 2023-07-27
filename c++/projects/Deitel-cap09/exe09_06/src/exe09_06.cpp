#include "Rational.h"

int main(){
	Rational resp(1,1);
    Rational r1(2,4);
    Rational r2(10,3);
    r1.print();
    r2.print();

    cout << "add\n";
	resp = r1.add(r1,r2);
	resp.print(); 
    resp.printd();
    
    cout << "subtrac\n";
	resp = r1.subtrac(r1,r2);
	resp.print(); 
    resp.printd();
    
    cout << "multiply\n";
	resp = r1.multiply(r1,r2);
	resp.print(); 
    resp.printd();
    
    cout << "divide\n";
	resp = r1.divide(r1,r2);
	resp.print(); 
    resp.printd();
    
    return 0;
}
