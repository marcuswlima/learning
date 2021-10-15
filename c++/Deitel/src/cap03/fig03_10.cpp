// Figura 3.10: fig03_10.cpp
// Incluindo a classe GradeBook a partir do arquivo Gradebook.h para uso em main.
#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h" // inclui a definição de classe GradeBook

// a função main inicia a execução do programa
int main()
{
    // cria dois objetos GradeBook
    GradeBook gradeBook1( "CS101 Introduction to C++ Programming" );
    GradeBook gradeBook2( "CS102 Data Structures in C++" );
    GradeBook gradeBook3( "CS103 Terceiro Exemplo" );

    // exibe valor inicial de courseName para cada GradeBook
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << "\ngradeBook3 created for course: " << gradeBook3.getCourseName()
        << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main