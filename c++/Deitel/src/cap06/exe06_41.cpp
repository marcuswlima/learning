#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <iomanip>
using std::setw;
using std::setiosflags;
using std::setprecision;



double fibonacci(int enesimo);

int main(){
    int x=fibonacci(5);

/*
    for (int i=10;i<=30;i++){
        cout << setw(5) << i << " ";
    }
    cout << endl;

    for (int i=10;i<=30;i++){
        cout << setw(5) << fibonacci(i) << " ";
    }
*/

    cout << setiosflags(ios::fixed | ios::showpoint)<<setprecision(0);

    for (int i=1;i<=80;i++){
        cout << setw(2) << i << " -> " << setw(11) << fibonacci(i) << endl;
    }

    cout << endl;
}

double fibonacci(int enesimo){

    double soma=1, menos1, menos2;

    if (enesimo == 1)
        return 0;
    else
        if (enesimo == 2)
            return 1;
        else{
            menos2=0;
            menos1=1;
            for (int i=3;i<=enesimo;i++){
                soma = menos1+menos2;

//                cout << "i      -> "<<i<< endl;
//                cout << "menos2 -> "<<menos2<< endl;
//                cout << "menos1 -> "<<menos1<< endl;
//                cout << "soma   -> "<<soma<< endl;

                menos2 = menos1;
                menos1 = soma;

            }
    }

//    cout<< endl;

    return soma;
}