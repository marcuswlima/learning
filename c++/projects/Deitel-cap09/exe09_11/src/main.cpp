#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
	Rectangle r(3,2);

	cout << r.perimeter() << '\n';
	cout << r.area() << '\n';

	return 0;
}
