// Figura 3.11: GradeBook.h
// Definição da classe GradeBook. Esse arquivo apresenta a interface pública de
// GradeBook sem revelar as implementações de funções-membro de GradeBook
// que são definidas em GradeBook.cpp.#include <iostream>
#include <string> // a classe GradeBook utiliza a classe de string padrão C++
using std::string;

// definição da classe GradeBook
class GradeBook
{
public:
    GradeBook( string, string ); // chama a função set para inicializar courseName
    void setCourseName( string ); // armazena o nome do curso no objeto
    string getCourseName(); // retorna courseName do objeto
    void setInstrutor( string );
    string getInstrutor(); 
    void displayMessage(); //função que exibe uma mensagem de boas-vinda
private:
    string courseName; // nome do curso para esse GradeBook
    string instrutor; // nome do curso para esse GradeBook
}; //