//Fig 2.11: fig02_11.cpp
//Análise dos resultados do teste
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ( )
{
    // inicialização
    int passes = 0,
        failures = 0,
        studentCounter = 1,
        result;

    // processa 10 estutandos ciclo controlado por contador
    while (studentCounter <= 10) {
      cout << "Forneça resultado (1=aprov,2=reprov): ";
      cin  >> result;

      if ( result == 1) 
         passes = passes + 1;
      else
         failures = failures + 1;

      studentCounter = studentCounter + 1;
    }

    // fase de termino
    cout << "Aprovados " << passes << endl;
    cout << "Reprovados " << failures << endl;
 
    if ( passes > 8 )
      cout << "Aumente o valor do curso " << endl;
       
    return 0; //indica o fim do programa
}
