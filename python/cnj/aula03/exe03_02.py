#---------------------------------------------------------------
# Comando  
#----------------------------------------------------------------
'''
Crie um programa que solicita indefinidos valores até o usuário digitar -1. Armazene
os valores digitados em uma lista (o -1 não deve ser armazenado). O programa deve
exibir a média dos valores, o desvio padrão, e os valores da lista que são maiores do
que média + desvio, e os que são menores do que média - desvio. Dica: crie funções
para calcular a média e o desvio padrão, por exemplo.

'''
import utilitarios
import random

#-----------------------------------------
# Procedure informacoes_lista(lista): 
#-----------------------------------------
def informacoes_lista(lista):   
    maiores_que_media = []
    menores_que_media = []
    na_media          = []
    
    media = utilitarios.media_da_lista(lista)

    print(lista)
    print("media:", media)

    for item in lista:
        if item>media:
            maiores_que_media.append(item)
        elif item<media:    
            menores_que_media.append(item)
        elif item==media:
            na_media.append(item)
    
    print("maiores que a média", maiores_que_media)
    print("menores que a média", menores_que_media)
    print("na média", na_media)
    print(" ")

    desvio_padrao = utilitarios.desvio_padrao_da_lista(lista)
    print("desvio padrão:", desvio_padrao)
    print(" ")

#-----------------------------------------
# Inicio
#-----------------------------------------
utilitarios.titulo("exercicios 03.02")

quantidade_de_listas=4
quantidade_de_iten_na_lista=10

for i in range(quantidade_de_listas):
    numeros=[]
    for i in range(quantidade_de_iten_na_lista):
        numeros.append(random.randrange(5,10))

    informacoes_lista(numeros)

