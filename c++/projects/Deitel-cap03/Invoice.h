#include <string> 
using std::string;

class Invoice{
    private:
        string id ;
        string descricao ;
        int quantidade ;
        int precoPorItem ;
    public:
        Invoice (string,string,int,int);
        void setId (string);
        string getId();
        void setDescricao (string);
        string getDescricao();
        void setQuantidade (int);
        int getQuantidade();
        void setPrecoPorItem (int);
        int getPrecoPorItem();
        int getInvoiceAmmount();
};
