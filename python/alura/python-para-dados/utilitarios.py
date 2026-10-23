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

# ==================================================
# Bibliotecas/Importações
# ==================================================
from random import randint, choice
from operator import itemgetter

# ==================================================
# gerar_nome()
# ==================================================
def gerar_nome() -> str:
    """
    Gera um nome aleatório.
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

    return choice(NOMES)

# ==================================================
# gerar_sobrenome()
# ==================================================
def gerar_sobrenome() -> str:

    """
    Gera um SOBRENOMES aleatório.
    """
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

    return choice(SOBRENOMES)


# ==================================================
# gerar_nome_completo()
# ==================================================
def gerar_nome_completo() -> str:
    return f"{gerar_nome()} {gerar_sobrenome()}"

# ==================================================
# gerar_um_inteiro()
# ==================================================
def gerar_um_inteiro(in_start:int, in_end:int)->int:
    return randint(in_start,in_end)

# ==================================================
# gerar_um_decimal()
# ==================================================
def gerar_um_decimal(in_start:float, in_end:float)->float:
    decimal = gerar_um_inteiro(in_start = int(in_start*100)
                              ,in_end   = int(in_end*100)
                              )
    return decimal/100

# ==================================================
# gerar_tupla_com_inteiros()
# ==================================================
def gerar_tupla_com_inteiros(in_start:int, in_end:int, in_quantidade:int)->tuple:
    """
    Gerar uma tupla contendo numeros inteiros

    Args:
        in_start->int:
            Inicio da faixa de valores válidos 

        in_end->int:
            Fim da faixa de valores válidos 

        in_quantidade->int:
            quantidade de mumeros gerados
    Returns:
        tuple
    """
    inteiros=[]
    for i in range(in_quantidade):
        inteiros.append(gerar_um_inteiro(in_start = in_start
                                        ,in_end   = in_end
                                        )
                       )

    return tuple(inteiros)

# ==================================================
# gerar_tupla_com_decimais()
# ==================================================
def gerar_tupla_com_decimais(in_start:float, in_end:float, in_quantidade:int)->tuple:
    """
    Gerar uma tupla contendo numeros decimais

    Args:
        in_start->float:
            Inicio da faixa de valores válidos 

        in_end->float:
            Fim da faixa de valores válidos 

        in_quantidade->int:
            quantidade de mumeros gerados
    Returns:
        tuple
    """
    inteiros=gerar_tupla_com_inteiros(in_start      = int(in_start*100), 
                                      in_end        = int(in_end*100), 
                                      in_quantidade = in_quantidade
                                      )

    decimais=tuple(map(lambda x: x/100 , inteiros))

    return decimais

# ==================================================
# is_inteiro_primo()
# ==================================================
def is_inteiro_primo(numero: int) -> bool:

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
# is_intiero_par()
# ==================================================
def is_intiero_par(numero: int) -> bool:
    return numero % 2 == 0


# ==================================================
# is_inteiro()
# ==================================================
def is_inteiro(numero: float) -> bool:
    return numero % 1 == 0

# ==================================================
# obter_racional()
# ==================================================
def obter_racional(in_mensagem: str) -> float:

    while True:
        numero_racional = input(in_mensagem+': ')

        try:
            numero_racional = float(numero_racional.replace(',','.'))
            return numero_racional

        except ValueError:
            print("Erro: o texto informado não representa um numero racional.")

# ==================================================
# obter_racional_positivo()
# ==================================================
def obter_racional_positivo(in_mensagem: str) -> float:
    while True:
        numero_racional = obter_racional(in_mensagem)

        if numero_racional >= 1:
            return numero_racional

        print("Erro: o texto informado não representa um numero racional potivio (n>0).")

# ==================================================
# obter_racional_nao_netativo()
# ==================================================
def obter_racional_nao_netativo(in_mensagem: str) -> float:
    while True:
        numero_racional = obter_racional(in_mensagem)

        if numero_racional >= 0:
            return numero_racional

        print("Erro: o texto informado não representa um numero racional não negativo (n>=0).")

# ==================================================
# obter_inteiro()
# ==================================================
def obter_inteiro(in_mensagem: str) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero.
    """
    while True:
        caractere = input(in_mensagem+': ')

        try:
            numero = int(caractere)
            return numero

        except ValueError:
            print("Erro: o texto informado não representa um número inteiro.")

# ==================================================
# obter_inteiro_positivo()
# ==================================================
def obter_inteiro_positivo(mensagem: str) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero
    """
    while True:
        inteiro = obter_inteiro(mensagem)

        if inteiro > 0:
            return inteiro

        print("Erro: o texto digitado não representa um inteiro positivo (n>0).")

# ==================================================
# obter_inteiro_nao_negativo()
# ==================================================
def obter_inteiro_nao_negativo(mensagem: str) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero e positivo.
    """
    while True:
        numero = obter_inteiro(mensagem)

        if numero >= 0:
            return numero

        print("Erro: o texto digitado não representa um inteiro não negativo (n>=0).")


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
def calcular_imc(in_peso:float, in_altura:float) -> float:
    """Prove o IMC
    
    imc em função do peso e da altura
    """
    return in_peso / ( in_altura**2 )

# ==================================================
# imprimir_titulo
# ==================================================
def imprimir_titulo(in_mensagem:str) -> None:
    """
    Imprimir um título na tela

    Args:
        mensagem: Mensagem que será exibida na título

    Returns:
        None
    """

    def escrever_linha(in_tamanho_texto:int) -> None:
        print("***",end="")
        for i in range(in_tamanho_texto):
            print("*",end="")
        print("***")

    escrever_linha(in_tamanho_texto=len(in_mensagem))
    print("**",in_mensagem, "**")
    escrever_linha(in_tamanho_texto=len(in_mensagem))

# ==================================================
# imprime_matriz
# ==================================================
def imprime_matriz(matriz):

    def transformar_int_to_str(inteiro:int) -> str:
        return str(inteiro).ljust(4,' ')

    qtd_colunas = 0
    qtd_linhas = len(matriz)
    for linha in matriz:
        tamanho_linha=len(linha)
        if tamanho_linha > qtd_colunas :
            qtd_colunas = tamanho_linha

    print("|    ",end="")
    for c in range(qtd_colunas):
        print('|',transformar_int_to_str(c),sep='',end="")
    print()
    for i in range(6+(qtd_colunas*5)):
        print('-',sep='',end='')
    print()


    for l in range(len(matriz)):
        print('|',transformar_int_to_str(l),sep='',end='')
        for c in range(len(matriz[l])):
            print('|',transformar_int_to_str(matriz[l][c]),sep='',end='')
        print()

