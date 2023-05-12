// Figura 7.25: fig07_25.cpp
// Cria objeto GradeBook utilizando um array bidimensional de notas.
#include "GradeBook.h" // Definição da classe GradeBook

#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

#include "../lib/marcusLib.h"

void mostraArr2DInt(const int [][GradeBook::tests], int  );

// a função main inicia a execução do programa
int main()
{
    // array bidimensional de notas de aluno
    int gradesArray[ GradeBook::students ][ GradeBook::tests ] =
        { { 87, 96, 70 },
{ 68, 87, 3 },
{ 94, 100, 90 },
{ 100, 81, 82 },
{ 83, 65, 85 },
{ 78, 37, 65 },
{ 85, 75, 83 },
{ 91, 41, 100 },
{ 76, 72, 34 },
{ 87, 68, 73 } };

    GradeBook myGradeBook("CS101 Introduction to C++ Programming", gradesArray );

    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    mostraArr2DInt(gradesArray, GradeBook::students);

    for (int i=0;i<GradeBook::students; i++){
        cout << i << " - ";
        mostarArrayInt(gradesArray[i],GradeBook::tests);
    }

    int tanahoArrray=3;
    int array1d[3]={1,2,100};
    mostarArrayInt(array1d,tanahoArrray);

    return 0; // indica terminação bem-sucedida
} // fim de main

void mostraArr2DInt(const int gradesArray[][GradeBook::tests],int linhas){
    cout << "\n";
    // copia notas de gradeArray para grades
    for ( int student = 0; student < GradeBook::students; student++ ) {
        for ( int test = 0; test < GradeBook::tests; test++ )
            cout << "[" << student << "," << test << "]=" << setw( 3 ) << gradesArray[ student ][ test ] << " ";

        cout << "\n";
    }

}