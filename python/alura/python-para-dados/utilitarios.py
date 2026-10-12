from random import randrange, choice
from operator import itemgetter

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


NOMES = (
    "Marcus",
    "João",
    "Maria",
    "Ana",
    "Carlos",
    "Pedro",
    "José",
    "Paulo",
    "Luciana",
    "Fernanda",
    "Izabel"
)

SOBRENOMES = (
    "Silva",
    "Santos",
    "Oliveira",
    "Souza",
    "Costa",
    "Lima",
    "Pereira",
    "Ferreira",
    "Rodrigues",
    "Almeida",
    "Ramos"
)

# ==================================================
# gerar_nome()
# ==================================================
def gerar_nome() -> str:
    """
    Gera um nome completo aleatório.
    """
    return f"{choice(NOMES)} {choice(SOBRENOMES)}"

# ==================================================
# gerar_tupla_com_inteiros()
# ==================================================
def gerar_tupla_com_inteiros(in_start:int, in_stop:int, in_quantidade:int)->tuple:
    """
    Gera uma tupla com numeros inteiros

    Args:
        in_start:
            Inicio da faixa de valores válidos 

        in_stop:
            Fim da faixa de valores válidos 

        in_quantidade:
            quantidade de mumeros gerados
    Returns:
        tuple
    """
    lista=[]
    for i in range(in_quantidade):
        lista.append(randrange(in_start,in_stop))

    return tuple(lista)

# ==================================================
# gerar_tupla_com_decimais()
# ==================================================
def gerar_tupla_com_decimais(in_start:int, in_stop:int, in_quantidade:int)->tuple:
    """
    Gera uma tupla com numeros com decimais

    Args:
        in_start:
            Inicio da faixa de valores válidos 

        in_stop:
            Fim da faixa de valores válidos 

        in_quantidade:
            quantidade de mumeros gerados
    Returns:
        tuple
    """
    lista=list(gerar_tupla_com_inteiros(in_start, in_stop, in_quantidade))
    for i in range(len(lista)):
        decimal=randrange(100)
        lista[i] += round((decimal/100),2)

    return tuple(lista)

# ==================================================
# imprimir_tabuada()
# ==================================================
def imprimir_tabuada(numero:int)->None:
    """
    Imprime a tabuada do numero gerado na tela

    Args:
        numero:
            Número para gerar a tabuada

    Returns:
        Nones
    """
    print(f"Tabuada de {numero}:")

    for i in range(11):
        if i==0:
            continue
        print(f'{numero} x {i} = {numero*i}')


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
# ordernar_dicit_por_valor()
# ==================================================
def ordernar_dicit_por_valor(in_dicio: dict, in_reverse=False):
    """ordernar_dicit_por_valor

    Returns a new dictionary sorted by value.
    If in_reverse=False then from minor to major, otherwise
    from major to minor (default=False)
    """
     
    out_dicio={}
    for item in sorted(in_dicio.items(),key=itemgetter(1),reverse=in_reverse):
        out_dicio[item[0]]=item[1]

    return out_dicio

# ==================================================
# calcular_imc()
# ==================================================
def calcular_imc(peso:int, altura:int) -> float:
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
# imprimir_titulo
# ==================================================
def imprimir_titulo(mensagem:str) -> None:
    """
    Imprimir um título na tela

    Args:
        mensagem: Mensagem que será exibida na título

    Returns:
        None
    """
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

# ==================================================
# int2str
# ==================================================
def transformar_int_to_str(inteiro:int) -> str:
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

