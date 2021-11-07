#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


int main(){
    int n[3]={3};
    
    for (int i=0;i<=3;i++){
        cout << n[i] << endl;

    }

    char string1[] = "arrayDeCaracteres";
    string string2 = "stringDeCaracteres";

    for (int i=0;i<=6;i++){
        cout << string1[i] << endl;

    }

    cout << string1 << "\n";
    cout << string2 << "\n";
}