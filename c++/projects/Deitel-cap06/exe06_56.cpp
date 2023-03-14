#include <iostream>

using std::cout;
using std::endl;

int tripleByValue(int);
void tripleByReference(int &);

int main(){
    int count=100;

    cout << "Antes chamada tripleByValue count = "  << count << endl;
    cout << "terorno de tripleByValue = "           << tripleByValue(count) << endl;
    cout << "depois chamada tripleByValue count = " << count << endl;

    cout << "Antes chamada tripleByReference count = " << count << endl;
    tripleByReference(count);
    cout << "depois chamada tripleByReference count = " << count << endl;
}

int tripleByValue(int count){
    return count*3;
}

void tripleByReference(int &count){
    count *= 3;
}