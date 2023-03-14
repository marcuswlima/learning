#include <string> 
using std::string;


class Date{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Date(int, int, int);
        void setDia(int);
        int getDia();
        void setMes(int);
        int getMes();
        void setAno(int);
        int getAno();
        string displayData();

};