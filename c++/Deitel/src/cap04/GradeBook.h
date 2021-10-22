// Figura 4.12: GradeBook.h
// Definição da classe GradeBook que determina a média de uma classe.
// As funções-membro são definidas no GradeBook.cpp
#include <string> // o programa utiliza classe de string padrão C++
using std::string;
// definição da classe GradeBook
class GradeBook
{
public:
    GradeBook( string ); // o construtor inicializa o nome do curso
    void setCourseName( string ); // função para configurar o nome do curso
    string getCourseName(); // função para recuperar o nome do curso
    void displayMessage(); // exibe uma mensagem de boas-vindas
    void determineClassAverage(); // calcula a média das notas inseridas pelo usuário
private:
    string courseName; // nome do curso para esse GradeBook
}; // fim da classe GradeBook