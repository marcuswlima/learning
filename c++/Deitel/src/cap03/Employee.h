#include <string> 
using std::string;

/*
class Employee {
  - nome : string
  - sobreNome : string
  - salarioMensal: int
  <<constructor>> +Employee (nome : String, sobrenome : String, salarioMensal : int)
  + setNome(string nome):void
  + getNome():string
  + setSobreNome(string nome):void
  + getSobreNome():string
  + setSalarioMensal(int salario):void
  + getSalarioMensal():int
  
}

*/

class Employee{
    private:
        string nome;
        string sobreNome;
        int    salarioMensal;
    public:
        Employee(string, string, int);
        void setNome(string);
        string getNome();
        void setSobreNome(string);
        string getSobreNome();
        void setsalarioMensal(int);
        int getSalarioMensal();
        void showEmployee();
};