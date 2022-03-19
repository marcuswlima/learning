from operator import itemgetter

def dicio_ordenado_por_valor(in_dicio, in_reverse=False):
    """dicio_ordenado_por_valor

    Returns a new dictionary sorted by value.
    If in_reverse=False then from minor to major, otherwise
    from major to minor (default=False)
    """
    
    out_dicio={}
    for item in sorted(in_dicio.items(),key=itemgetter(1),reverse=in_reverse):
        out_dicio[item[0]]=item[1]

    return out_dicio

def imc(peso,altura):
    """Prove o IMC
    
    imc em função do peso e da altura
    """
    return peso / ( altura**2 )

def obter_float(mensagem):
    digitado = input(mensagem)
    return float(digitado.replace(',','.'))

def escrever_linha(tamanho_texto):
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

def titulo(mensagem):
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

def int2str(inteiro):
    return str(inteiro).ljust(4,' ')

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

