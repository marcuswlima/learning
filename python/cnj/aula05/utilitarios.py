#-----------------------------------------
# Função imc
#-----------------------------------------
def imc(peso,altura):
    return peso / ( altura**2 )

#-----------------------------------------
# Função Obter_float
#-----------------------------------------
def obter_float(mensagem):
    digitado = input(mensagem)
    return float(digitado.replace(',','.'))

#-----------------------------------------
# Função titulo
#-----------------------------------------
def escrever_linha(tamanho_texto):
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

def titulo(mensagem):
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

#-----------------------------------------
# Função imprime_matriz
#-----------------------------------------
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
