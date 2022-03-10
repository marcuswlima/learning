import utilitarios

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

#------------------------------------
utilitarios.titulo("imprime_matriz")

Matriz = [ [0, 1, 2], [3, 4, 5], [6, 7, 8, 9,5,4,2], [10,11] ,[80,100]]
imprime_matriz(Matriz)



