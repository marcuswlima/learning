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
    int numero , maior=0;


  for (int i=1; i <=10; i++){
    cout << i << " - Digite o numero: ";
    cin >> numero;  

    if ( numero > maior )
        maior = numero ;

  }  
  cout << endl  ;
  
  cout <<"O maior numero é " << maior << endl ;


  cout << endl << endl ;
  return 0;
}

