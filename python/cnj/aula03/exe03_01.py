#---------------------------------------------------------------
# Comando  
#----------------------------------------------------------------
'''
Crie uma função que recebe uma lista de inteiros como 
parâmetro. A função deve percorrer a lista a fim de encontrar 
o maior valor dessa lista. A função deve retornar o maior valor.
'''

import utilitarios
import random

#-----------------------------------------
# Inicio 
#-----------------------------------------
utilitarios.titulo("exercicios 03.01")

quantidade_de_itens_na_lista=10
quantidade_de_listas=40

for lista in range(quantidade_de_listas):
    numeros=[]
    for item in range(quantidade_de_itens_na_lista):
        numeros.append(random.randrange(1,100))

    print(lista+1, numeros, "o maior valor é", utilitarios.maior_valor_de_lista(numeros))

