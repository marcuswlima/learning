#include <iostream>

int main(){
	std::string var1="Meu conteudo";
	std::string *PrtVar2 = &var1;

	std::cout << var1 << std::endl;
	std::cout << PrtVar2 << std::endl;
	std::cout << *PrtVar2 << std::endl;


	return 0;
}
