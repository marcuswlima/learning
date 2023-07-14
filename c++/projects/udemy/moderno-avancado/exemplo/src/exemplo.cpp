#include "exemplo.hh" 

typedef std::string STR;

Exemplo::Exemplo(){
	std::cout << "Iniciando o nosso exemplo" << '\n';
}

Exemplo::Exemplo( int x, int *y){
	std::cout << "A soma de " << x << " mais " << *y << " é igual a " << x + (*y) << '\n';
}

Exemplo::~Exemplo(){
	std::cout << "Fechando o projeto" << '\n';
}

void Exemplo::lista_array( STR array[] ){
	std::cout << "Ainda sendo implementado" << '\n'; 
}

STR Exemplo::mostra(STR nova_senha){
	senha = nova_senha;
	return senha;
}
