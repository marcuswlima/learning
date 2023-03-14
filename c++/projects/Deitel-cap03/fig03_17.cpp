// Figura 3.17: fig03_17.cpp
// Demonstração de classe GradeBook depois de separar
#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h" // inclui a definição de classe GradeBook

// a função main inicia a execução do programa
int main()
{
    // cria dois objetos GradeBook;
    // nome inicial de curso de gradeBook1 é muito longo
    GradeBook gradeBook1( "CS101 Introduction to Programming in C++", "Marcus William" );
    GradeBook gradeBook2( "CS102 C++ Data Structures", "Santos Lima" );

    // exibe courseName de cada GradeBook
    cout << "gradeBook1’s initial course name is: "
       << gradeBook1.getCourseName()
       << "\ngradeBook2’s initial course name is: "
       << gradeBook2.getCourseName() << endl;

    // modifica courseName do myGradeBook (com uma string de comprimento válido)
    gradeBook1.setCourseName( "CS101 C++ Programming" );

    // exibe courseName de cada GradeBook
    cout << "\ngradeBook1’s course name is: "
       << gradeBook1.getCourseName()
       << "\ngradeBook2’s course name is: "
       << gradeBook2.getCourseName() << endl;

   gradeBook1.displayMessage();
   gradeBook2.displayMessage();
   //cout << gradeBook2.displayMessage() << endl;
   return 0; // indica terminação bem-sucedida


    cout << "0";
} // fim de main