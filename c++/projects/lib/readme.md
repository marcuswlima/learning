[[_TOC_]]

# BarraTitulo.h

## ImprimirTitulo

- Imprimir um título no programa via `cout`

```
void ImprimirTitulo(string titulo="")
```

# PrintArray.h


## PrintVector

- Realiza a impressão em tela de um vetor (`cout`)

```
void PrintVector( const int [], int , string  );
void PrintVector( const double [], int , string  );
```

## PrintMatrix

- Imprime os valores de uma matriz de duas colunas (`cout`)

```
void PrintMatrix(const int [][2],const int, const int );
```


# Methematics.h

## CalcMdc
- Calcular o MDC de dois números
```
int CalcMdc(int x, int y);
```

## GetRemainder
- Apresenta o resto da divisão de 2 números
```
int GetRemainder(int, int);
```
## HasRemainder
- Indica se a divisão de 2 números gera resto
```
bool HasRemainder(int, int);
```
## IsEven
- Indica se o número é par
```
bool IsEven(int);
```
## IsPrime
- Indica se o número é primo
```
bool IsPrime(int entrou);
```
## CalcPower
- Calcula a potência (recursividade)
```
int CalcPower(int base, int expoent);
```

## CalcHypotenuse
- Calcula a hipotenusa para 2 lados de um triâgulo
```
double CalcHypotenuse(double c1, double c2);
```
## CalcFatorial
- Calcula o fatorial de um número
```
long CalcFatorial(long numero);
```
- http://en.wikipedia.org/wiki/Factorial
## CalcCatalan
 - Calcula o numero de um inteiro
```
double CalcCatalan(long numero);
```
- http://en.wikipedia.org/wiki/Catalan_number
## CalcRealRoots

- Calcula as 2 raizes de uma equação 2g
```
string CalcRealRoots(int a, int b, int c);
```
## GerarInteiro
- Gera um inteiro aleatório dentro de uma faixa de inteiros
```
int GerarInteiro(int menor, int maior);
```
1. Parametro  
        - `menor` inicio da faixa  
        - `maior` fim da faixa
1. Retorno  
        - Número inteiro aretório contido  da faixa informada

## GerarDouble
- Gera um double aleatório dentro de uma faixa de inteiros
```
double GerarDouble(int menor, int maior)
```
1. Parametro  
        - `menor` inicio da faixa  
        - `maior` fim da faixa
1. Retorno  
        - Número double aretório contido  da faixa informada

# ObterNumero.h

## ObterNumero
 - Canaliza ao retorno da função o valor informado na tela
```
int ObterNumero(string str);
```
1. Parametro  
        - `Str` Mensagem que será informada ao usuário
1. Retorno  
        - Valor informado pelo usuário
1. Observações  
        - Existe um tratamento de erro, se o valor informado não for numérico o promt com a mensagem aparecerá novamente

## ObterNumeroNaFaixa
 - Canaliza ao retorno da função o valor informado na tela
```
int ObterNumeroNaFaixa(string str, int menor, int maior);
```
1. Parametros  
        - `Str` Mensagem que será informada ao usuário  
        - `menor` inicio da faixa  
        - `maior` fim da faixa
1. Retorno  
        - Valor informado pelo usuário
1. Observações  
        - Existe um tratamento de erro, se o valor informado não for numérico o promt com a mensagem aparecerá novamente

# SystemNumeral.h

## ConvertHexadecinalToDecimal

```
int ConvertHexadecinalToDecimal(string hexadecimal)
```

1. Parametros  
        - `hexadecimal` número hexadecimal em formato `string`
1. Retorno  
        - Numero decimal correspondete


## ConvertBinaryToDecimal
```
long ConvertBinaryToDecimal(string binario)
```
1. Parametros  
        - `binario` número binário em formato `string`
1. Retorno  
        - Numero decimal correspondete


## ConvertDecimalToHexadecimal
```
string ConvertDecimalToHexadecimal(int numero)
```
1. Parametros  
        - `numero` número com base decimal
1. Retorno  
        - Numero hexadecimal correspondete

## ConvertDecimalToBinary
```
string ConvertDecimalToBinary(int numero)
```
1. Parametros  
        - `numero` número com base decimal
1. Retorno  
        - Numero binário correspondete

# NumeroExtenso.h

## ShowNumberEnglishPronuciation

```
string ShowNumberEnglishPronuciation(int numero);
```
1. Parametros  
        - `numero` numero de 1 - 999
1. Retorno  
        - Representação em extenso do número informado (Inglês)
1. Observações  
        - Projetado para a faixa de 1-999

