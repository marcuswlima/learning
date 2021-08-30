//Fig 2.7: fig02_07.cpp
// Programa de media da turma com repeticao controlada por contatos
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setprecision;
using std::setiosflags;

int main ( )
{
    int total,
        gradeCounter,
        grade;
    double average;

    // inicialização
    total        = 0;
    gradeCounter = 0;

    //fase processamento
    cout << "Forneça a nota ou -1 para finalizar: ";
    cin  >> grade;

    while (grade != -1) {
        total = total + grade;
        gradeCounter = gradeCounter + 1;
        cout << "Forneça a nota ou -1 para finalizar: ";
        cin  >> grade;
    }

    //fase de termino
    if ( gradeCounter != 0 ) {
      average = static_cast< double >( total ) / gradeCounter;
      cout << "A média da turma é " << setprecision(2)
           << setiosflags( ios::fixed | ios::showpoint )
           << average << endl;
    }
    else 
      cout << "Nenhuma nota foi digitada " << endl;
        
    cout << "Total -> " << total << endl;
    cout << "gradeCounter -> " << gradeCounter << endl;
    cout << "Media -> " << static_cast<double>(total)/gradeCounter << endl;
    return 0; //indica o fim do programa
}
