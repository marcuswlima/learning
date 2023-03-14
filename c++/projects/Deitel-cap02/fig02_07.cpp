//Fig 2.7: fig02_07.cpp
// Programa de media da turma com repeticao controlada por contatos
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ( )
{
    std::cout << "Bem vindo a C++!\n";

    int total,
        gradeCounter,
        grade,
        average;

    // inicialização
    total = 0;
    gradeCounter = 1;

    //fase processamento
    while (gradeCounter <= 10) {
        cout << "Forneça nota :";
        cin >> grade;
        total = total + grade;
        gradeCounter = gradeCounter + 1;
    }

    //fase de termino
    average = total / 10;
    cout << "A media da turma eh : " << average << endl;

    return 0; //indica o fim do programa
}
