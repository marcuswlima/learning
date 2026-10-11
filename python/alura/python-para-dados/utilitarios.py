
"""
# Documentação do módulo utilitarios.py

## Objetivo

O módulo fornece funções utilitárias para:

- Verificação de números inteiros, pares e primos
- Entrada de dados validada.
- Cálculo de IMC.
- Manipulação e ordenação de dicionários.
- Impressão formatada de títulos e matrizes.

---

# Funções

## is_primo()

### Descrição
Verifica se um número é primo.

### Sintaxe
```python
is_primo(numero: float) -> bool
```
"""

from operator import itemgetter


# ==================================================
# eh_primo()
# ==================================================
def is_primo(numero: float) -> bool:

    eh_primo=True

    if numero <= 1:
        eh_primo=False
    else:
        for i in range(2,numero):
            if numero % i == 0:
                eh_primo=False
                break

    return eh_primo


# ==================================================
# is_inteiro()
# ==================================================
def is_inteiro(numero: float) -> bool:
    return numero % 1 == 0

# ==================================================
# is_par()
# ==================================================
def is_par(numero: float) -> bool:
    return numero % 2 == 0

# ==================================================
# obter_float()
# ==================================================
def obter_float(mensagem: str) -> float:
    digitado = input(mensagem+': ')
    return float(digitado.replace(',','.'))

# ==================================================
# obter_float_positivo()
# ==================================================
def obter_float_positivo(mensagem: str) -> float:
    while True:
        digitado = obter_float(mensagem)
        if digitado >= 1:
            return digitado

        print("Erro: informe apenas valores positivos.")

# ==================================================
# obter_int()
# ==================================================
def obter_int(mensagem: str) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero.
    """
    while True:
        caractere = input(mensagem+': ')

        if caractere.isnumeric():
            return int(caractere)

        print("Erro: informe apenas numeros.")

# ==================================================
# obter_int_positivo()
# ==================================================
def obter_int_positivo(mensagem: str) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero e positivo.
    """
    while True:
        numero = obter_int(mensagem)

        if numero > 0:
            return numero

        print("Erro: informe apenas numeros positivos.")


# ==================================================
# obter_uma_letra()
# ==================================================
def obter_uma_letra(mensagem: str) -> str:
    """
    Solicita um caractere ao usuário até que seja informada uma letra.
    """

    while True:
        caractere = input(mensagem+': ')

        if len(caractere) == 1 and caractere.isalpha():
            return caractere

        print("Erro: informe apenas uma letra.")


# ==================================================
# dicio_ordernado_por_valor()
# ==================================================
def dicio_ordernado_por_valor(in_dicio: dict, in_reverse=False):
    """dicio_ordernado_por_valor

    Returns a new dictionary sorted by value.
    If in_reverse=False then from minor to major, otherwise
    from major to minor (default=False)
    """
     
    out_dicio={}
    for item in sorted(in_dicio.items(),key=itemgetter(1),reverse=in_reverse):
        out_dicio[item[0]]=item[1]

    return out_dicio

# ==================================================
# imc()
# ==================================================
def imc(peso:int, altura:int) -> float:
    """Prove o IMC
    
    imc em função do peso e da altura
    """
    return peso / ( altura**2 )

# ==================================================
# escrever_linha
# ==================================================
def escrever_linha(tamanho_texto:int) -> None:
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

# ==================================================
# titulo
# ==================================================
def titulo(mensagem:str) -> None:
    """
    Escrever um título
    """
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

# ==================================================
# int2str
# ==================================================
def int2str(inteiro:int) -> str:
    return str(inteiro).ljust(4,' ')

# ==================================================
# imprime_matriz
# ==================================================
def imprime_matriz(matriz):
    qtd_colunas = 0
    qtd_linhas = len(matriz)
    for linha in matriz:
        tamanho_linha=len(linha)
        if tamanho_linha > qtd_colunas :
            qtd_colunas = tamanho_linha

    print("|    ",end="")
    for c in range(qtd_colunas):
        print('|',int2str(c),sep='',end="")
    print()
    for i in range(6+(qtd_colunas*5)):
        print('-',sep='',end='')
    print()


    for l in range(len(matriz)):
        print('|',int2str(l),sep='',end='')
        for c in range(len(matriz[l])):
            print('|',int2str(matriz[l][c]),sep='',end='')
        print()

