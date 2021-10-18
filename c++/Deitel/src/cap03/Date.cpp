#include <string> 
using std::string;

#include "Date.h"

Date::Date(int mes, int dia, int ano){
    setDia(dia);
    setMes(mes);
    setAno(ano);
}
void Date::setDia(int in_dia){
    dia = in_dia;
}
int Date::getDia(){
    return dia;
}
void Date::setMes(int in_mes){
    mes = in_mes;
}
int Date::getMes(){
    return mes;
}
void Date::setAno(int in_ano){
    ano = in_ano;
}
int Date::getAno(){
    return ano;
}
string Date::displayData(){

//    return static_cast< string >(  std::to_string(getMes())  ) + "/";
    return std::to_string(getMes()) + "/"
         + std::to_string(getDia()) + "/"
         + std::to_string(getAno()) 
           ;
}


