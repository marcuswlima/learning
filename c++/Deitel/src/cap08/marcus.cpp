#include <iostream>
using std::cout;

int main(){
    int *countPtr;
    int count;


    cout << "countPtr -> " <<  countPtr << "\n";

    countPtr=0;

    cout << "countPtr -> " <<  countPtr << "\n";

    countPtr=&count;

    cout << "countPtr -> " <<  countPtr << "\n";

    return 0;
}