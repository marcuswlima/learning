#include <iostream>

void recebe_array( int numeros[] ){
  std::cout << sizeof(numeros)  << '\n';
  std::cout << sizeof(numeros[0]) << '\n';
  std::cout << "A quantidade de itens do array numeros[] DENTRO DA FUNÇÃO é: " << sizeof(numeros) / sizeof(numeros[0]) << '\n';
}


void recebe_variavel( int variavel ){
  variavel = 12;
}

int main(){
  int numeros[] = {11, 22, 33, 44, 55};
  
  recebe_array( numeros );
  std::cout << sizeof(numeros)  << '\n';
  std::cout << sizeof(numeros[0]) << '\n';
  std::cout << "A quantidade de itens do array numeros[] é: " << sizeof(numeros) / sizeof(numeros[0]) << '\n';

  //int variavel { 66 };
  //std::cout << "O valor da variavel ANTES da função é: " << variavel << '\n';
  //recebe_variavel( variavel );
  //std::cout << "O valor da variavel DEPOIS da função é: " << variavel << '\n';
  //int multi[3][3] = { { 5, 8, 9 } , { 2, 7, 4 } , { 6, 0, 1 } };
  //std::cout << "O valor de posição 3 ANTES da função é: " << numeros[3] << '\n';
  //recebe_array( numeros );
  //std::cout << "O valor de posição 3 ANTES da função é: " << numeros[3] << '\n';
  return 0;
}
