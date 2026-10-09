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
# indicar_menor_numero()
# ==================================================
def indicar_menor_numero(n1 , n2, n3) -> int:
    if n1 < n2 and n1 < n3:
        return n1
    elif n2 < n1 and n2 < n3:
        return n2
    elif n3 < n1 and n3 < n2:
        return n3

# ==================================================
# indicar_maior_numero()
# ==================================================
def indicar_maior_numero(n1 , n2, n3) -> int:
    if n1 > n2 and n1 > n3:
        return n1
    elif n2 > n1 and n2 > n3:
        return n2
    elif n3 > n1 and n3 > n2:
        return n3

# ==================================================
# obter_float()
# ==================================================
def obter_float(mensagem) -> float:
    digitado = input(mensagem+': ')
    return float(digitado.replace(',','.'))

# ==================================================
# obter_int()
# ==================================================
def obter_int(mensagem) -> int:
    """
    Solicita um caractere ao usuário até que seja informada um numero.
    """
    while True:
        caractere = input(mensagem+': ')

        if caractere.isnumeric():
            return int(caractere)

        print("Erro: informe apenas numeros.")

# ==================================================
# obter_uma_letra()
# ==================================================
def obter_uma_letra() -> str:
    """
    Solicita um caractere ao usuário até que seja informada uma letra.
    """

    while True:
        caractere = input("Informe uma letra: ")

        if len(caractere) == 1 and caractere.isalpha():
            return caractere

        print("Erro: informe apenas uma letra.")


# ==================================================
# dicio_ordernado_por_valor()
# ==================================================
def dicio_ordernado_por_valor(in_dicio, in_reverse=False):
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
def imc(peso,altura) -> float:
    """Prove o IMC
    
    imc em função do peso e da altura
    """
    return peso / ( altura**2 )

# ==================================================
# escrever_linha
# ==================================================
def escrever_linha(tamanho_texto) -> None:
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

# ==================================================
# titulo
# ==================================================
def titulo(mensagem) -> None:
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

# ==================================================
# int2str
# ==================================================
def int2str(inteiro) -> str:
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

