#include <iostream>
using namespace std;

int main(){
	int SIZE=5;
	unsigned int values[ SIZE ]={2,3,4,5,6,7};
	unsigned int *vPtr;

	cout << "array subscript notation - values[i]" << endl;
	for (int i=0; i<=SIZE; i++){
		cout << values[ i ]<< " ";
	}//for
	cout << '\n' ;

	vPtr = values;
	vPtr = &values[0];
	
	cout << "pointer offset notation - *(vPtr+i)" << endl;
	for (int i=0; i<=SIZE; i++){
		cout << *(vPtr+i)<< " ";
	}//for
	cout << '\n' ;

	cout << "pointer offset notation, array as pointer *(values+i)" << endl;
	for (int i=0; i<=SIZE; i++){
		cout << *(values+i)<< " ";
	}//for
	cout << '\n' ;

	cout << "subscripting the pointer - vPtr[i]" << endl;
	for (int i=0; i<=SIZE; i++){
		cout << vPtr[i]<< " ";
	}//for
	cout << '\n' ;

	cout << "5th subscript notation / values[4] -> " << values[4] << endl;
	cout << "5th pointer/offset notation with array as pointer / *(values+4) -> " << *(values+4) << endl;
	cout << "5th pointer subscript notation / vPtr[4] -> " << vPtr[4] << endl;
	cout << "5th pointer/offset notation / *(vPtr+4) -> " << *(vPtr+4) << endl;

	cout << endl;

	cout << "vPtr + 3 -> " << vPtr+3 << endl;
	cout << "*(vPtr + 3) -> " << *(vPtr+3) << endl;

	vPtr = &values[4];

	cout << "vPtr -= 4 -> " << *(vPtr -=4) << endl;

	vPtr = &values[0];
	for (int i=0; i<SIZE; i++)
		cout << vPtr+i << '\n';


	cout << endl;
}//main
