
#---------------------------------------------------------------
# Comando  
#----------------------------------------------------------------
'''
Melhore o exemplo da lista de compras da aula. O programa deve solicitar novos
itens do usuário até ele digitar “sair”. Se o usuário digitar “remover”, o programa
deve perguntar qual o item ele quer remover da lista, e removê-lo. Se o usuário
digitar “substituir”, o programa deve perguntar o nome do item a ser substituído, e
substituí-lo por outro digitado pelo usuário. Após o usuário digitar “sair”, você deve
exibir a lista de compras na tela, sendo que a lista deve estar ordenada.
'''


import utilitarios

#-----------------------------------------
# Função existe() 
#-----------------------------------------
def existe(item):
    if lista_compras.count(item)==0:
        print("\tO item \"{}\" não está na lista".format(item))
        return False
    else:
        return True

#-----------------------------------------
# Função obter_item 
#-----------------------------------------
def obter_item(mensagem):
    valor_obtido=input("\t"+mensagem)
    return valor_obtido

#-----------------------------------------
# Inicio 
#-----------------------------------------
utilitarios.titulo("exercicios 03.03")

utilitarios.titulo("Manutenção da lista lista_compras")

lista_compras = ['alho','cebola','carro','geladeira']
comando = "0"

while(comando!="exit"):

    comando = input("Informe o comando [exit, add, remove, update, list]: ")

    if comando=='list':
        print(lista_compras)
    elif comando=='add':
        novo_item = obter_item("informe um novo item: ")
        lista_compras.append(novo_item)
    elif comando=='remove':
        print(lista_compras)
        velho_item = obter_item("informe o item a ser removido: ")
        if existe(velho_item):
            lista_compras.remove(velho_item)
    elif comando=='update':
        print(lista_compras)
        velho_item = obter_item("informe o item a ser alterado: ")
        if existe(velho_item):
            posicao = lista_compras.index(velho_item)
            novo_item = obter_item("informe um novo item: ")
            lista_compras[posicao]=novo_item
    elif comando=='exit':
        pass
    else:
        print("\tNão é um comando válido!!!")


