// Figura 7.17: GradeBook.cpp
// Definições de função-membro para a classe GradeBook que
// utiliza um array para armazenar notas de teste.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;
using std::setw;

#include "GradeBook.h" // definição da classe GradeBook

// o construtor inicializa courseName e o array grades
GradeBook::GradeBook( string name, const int gradesArray[] [ tests ])
{
    setCourseName( name ); // inicializa courseName

    // copia notas de gradeArray para grades
    for ( int student = 0; student < students; student++ )

        for ( int test = 0; test < tests; test++ )
            grades[ student ][ test ] = gradesArray[ student ][ test ];

} // fim do construtor GradeBook

// função para configurar o nome do curso
void GradeBook::setCourseName( string name )
{
    courseName = name; // armazena o nome do curso
} // fim da função setCourseName

// função para recuperar o nome do curso
string GradeBook::getCourseName()
{
    return courseName;
} // fim da função getCourseName

// exibe uma mensagem de boas-vindas para o usuário de GradeBook
void GradeBook::displayMessage()
{
    // essa instrução chama getCourseName para obter o
    // nome do curso que esse GradeBook representa
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
} // fim da função displayMessage


// realiza várias operações nos dados
void GradeBook::processGrades()
{
    // gera saída de array de notas
    outputGrades();

    // chama função getAverage para calcular a nota média
    cout << "\nLowest grade in the grade book is " << getMinimum()
         << "\nHighest grade in the grade book is " << getMaximum() << endl;
    
    outputBarChart();
} // fim da função processGrades

// localiza nota mínima
int GradeBook::getMinimum()
{
    int lowGrade = 100; // supõe que a nota mais baixa é 100

    // faz um loop pelas linhas do array de notas
    for ( int student = 0; student < students; student++ )
    {
        // faz um loop pelas colunas da linha atual
        for ( int test = 0; test < tests; test++ )
        {
            // se a nota for menor que lowGrade, atribui a nota a lowGrade
            if ( grades[ student ][ test ] < lowGrade )
                lowGrade = grades[ student ][ test ]; // nova nota mais baixa
        } // fim do for interno
    } // fim do for externo

    return lowGrade; // retorna nota mais baixa
} // fim da função getMinimum

// localiza nota máxima
int GradeBook::getMaximum()
{
    int highGrade = 0; // supõe que a nota mais alta é 0

    // faz um loop pelas linhas do array de notas
    for ( int student = 0; student < students; student++ )
    {
        // faz um loop pelas colunas da linha atual
        for ( int test = 0; test < tests; test++ )
        {
            // se a nota atual for maior que lowGrade, atribui essa nota a highGrade
            if ( grades[ student ][ test ] > highGrade )
                highGrade = grades[ student ][ test ]; // nova nota mais alta
        } // fim do for interno
    } // fim do for externo

    return highGrade; // retorna nota mais alta
} // fim da função getMaximum

// determina média para o teste
double GradeBook::getAverage(const int setOfGrades[], const int grades)
{
    int total = 0; // inicializa o total

    // soma notas no array
    for ( int grade = 0; grade < students; grade++ )
        total += setOfGrades[ grade ];

    // retorna média de notas
    return static_cast< double >( total ) / students;
} // fim da função getAverage

// gera a saída do gráfico de barras exibindo distribuição de notas
void GradeBook::outputBarChart()
{
    cout << "\nGrade distribution:" << endl;

    // armazena freqüência de notas em cada intervalo de 10 notas
    const int frequencySize = 11;
    int frequency[ frequencySize ] = { 0 };

    // para cada nota, incrementa a freqüência apropriada
    for ( int student = 0; student < students; student++ )
        for ( int test = 0; test < tests; test++ )
            ++frequency[ grades[ student ][ test ] / 10 ];

    // para cada freqüência de nota, imprime barra no gráfico
    for ( int count = 0; count < frequencySize; count++ )
    {
        // gera a saída do rótulo das barras ("0-9:", ..., "90-99:", "100:" )
        if ( count == 0 )
            cout << " 0-9: ";
        else if ( count == 10 )
            cout << " 100: ";
        else
            cout << count * 10 << "-" << ( count * 10 ) + 9 << ": ";

        // imprime a barra de asteriscos
        for ( int stars = 0; stars < frequency[ count ]; stars++ )
            cout << '*';

        cout << endl; // inicia uma nova linha de saída
    } // fim do for externo
} // fim da função outputBarChart

// gera a saída do conteúdo do array de notas
void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";

    cout << "            "; // alinha títulos de coluna

    // cria um título de coluna para cada um dos testes
    for ( int test = 0; test < tests; test++ )
        cout << "Test " << test + 1 << " ";
    
    cout << "Average" << endl; // título da coluna de média do aluno
    
    // cria linhas/colunas de texto que representam notas de array
    for ( int student = 0; student < students; student++ )
    {
        cout << "Student " << setw( 2 ) << student + 1;

        // gera saída de notas do aluno
        for ( int test = 0; test < tests; test++ )
            cout << setw( 8 ) << grades[ student ][ test ];

        // chama a função-membro getAverage para calcular a média do aluno;
        // passa linha de notas e o valor dos testes como argumentos
        double average = getAverage( grades[ student ], tests );
        cout << setw( 9 ) << setprecision( 2 ) << fixed << average << endl;
    } // fim do for externo
} // fim da função outputGrades