// Figura 7.23: GradeBook.h
// Definição da classe GradeBook que utiliza um
// array bidimensional para armazenar notas de teste.
// As funções-membro são definidas em GradeBook.cpp
#include <string> // o programa utiliza a classe string da C++ Standard Library
using std::string;

// Definição da classe GradeBook
class GradeBook
{
public:
    // constante -- número de alunos que fizeram o teste
    const static int students = 10; // note os dados públicos
    const static int tests = 3; // número de testes de cada aluno

    // construtor inicializa o nome do curso e o array de notas
    GradeBook( string, const int [] [ tests ]);

    void setCourseName( string ); // função para configurar o nome do curso
    string getCourseName(); // função para recuperar o nome do curso
    void displayMessage(); // exibe uma mensagem de boas-vindas
    void processGrades(); // realiza várias operações nos dados
    int getMinimum(); // localiza a nota mínima para o teste
    int getMaximum(); // localiza a nota máxima para o teste
    double getAverage(const int [], const int); // determina a nota média para o teste
    void outputBarChart(); // gera saída do gráfico de barras de distribuição de notas
    void outputGrades(); // gera a saída do conteúdo do array de notas
private:
    string courseName; // nome do curso para esse livro de notas
    int grades[ students ][ tests ]; // array de notas dos alunos
}; // fim da classe GradeBook