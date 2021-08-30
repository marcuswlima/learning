#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )


#include <iomanip>

using std::setprecision;
using std::setiosflags;

int main()
{
    int numero , top1=0, top2=0;


  for (int i=1; i <=3; i++){
    cout << i << " - Digite o numero: ";
    cin >> numero;  

    if ( numero > top1 )
        top1 = numero ;

    if ( numero > top2 || numero < top1)
        top2 = numero;

  }  
  cout << endl  ;
  
  cout <<"O top1 é " << top1 << endl ;
  cout <<"O top2 é " << top2 << endl ;


  cout << endl << endl ;
  return 0;
}

