#-----------------------------------------
# Função Obter_float
#-----------------------------------------
def obter_float(mensagem):
    digitado = input(mensagem)
    return float(digitado.replace(',','.'))

#-----------------------------------------
# Procedure título
#-----------------------------------------
def __escrever_linha(tamanho_texto):
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

def titulo(mensagem):
    __escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    __escrever_linha(len(mensagem))

#-----------------------------------------
# Função imc - indice de massa corporal
#-----------------------------------------
def imc(peso,altura):
    return peso / (altura**2)

#-----------------------------------------
# Função maior_valor_de_lista(lista): 
#-----------------------------------------
def maior_valor_de_lista(lista):
    maior = 0
    for item in lista:
        if item > maior :
            maior = item
    return maior

#-----------------------------------------
# Função media_da_lista(lista): 
#-----------------------------------------
def media_da_lista(lista):
    soma=0
    quantidade=0
    for item in lista:
        soma += item
        quantidade += 1

    return soma/quantidade

#-----------------------------------------
# Função desvio_padrao([]): 
#-----------------------------------------
def desvio_padrao_da_lista(lista):
    desvio_padrao = 0
    media         = media_da_lista(lista)

    for item in lista:
        desvio_padrao = desvio_padrao + (( item - media ) ** 2)
    return desvio_padrao 
#-----------------------------------------

