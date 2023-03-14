#include <string> 
using std::string;

#include "Invoice.h" 

Invoice::Invoice (string id
                 ,string descricao
                 ,int quantidade
                 ,int precoPorItem){
    setId(id);
    setDescricao(descricao);
    setQuantidade(quantidade);
    setPrecoPorItem(precoPorItem);

}
void Invoice::setId (string in_id){
    id = in_id;

}
string Invoice::getId(){
    return id;

}
void Invoice::setDescricao (string in_descricao){
    descricao = in_descricao;
}
string Invoice::getDescricao(){
    return descricao;
}
void Invoice::setQuantidade (int in_quantidade){
    quantidade = in_quantidade;

}
int Invoice::getQuantidade(){
    return quantidade;
}
void Invoice::setPrecoPorItem (int in_precoPorItem){
    precoPorItem = in_precoPorItem;

}
int Invoice::getPrecoPorItem(){
    return precoPorItem;
}
int Invoice::getInvoiceAmmount(){
    if (quantidade   < 0) return 0;
    if (precoPorItem < 0) return 0;
 
    return quantidade * precoPorItem;
}
