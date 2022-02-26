import utilitarios

utilitarios.titulo("Manutenção da lista lista_compras")

lista_compras = ['alho','cebola','carro','geladeira']
comando = "0"
novo_item = "0"
velho_item = "0"

while(comando!="exit"):

    comando = input("Informe o comando [exit, add, remove, update, list]: ")

    if comando=='list':
        print(lista_compras)
    elif comando=='add':
        novo_item = input("informe um novo item: ")
        lista_compras.append(novo_item)
    elif comando=='remove':
        print(lista_compras)
        velho_item = input("informe o item a ser removido: ")
        if lista_compras.count(velho_item)==0:
            print("item não existe")
        else:
            lista_compras.remove(velho_item)
    elif comando=='update':
        print(lista_compras)
        velho_item = input("informe o item a ser alterado: ")
        if lista_compras.count(velho_item)==0:
            print("item não existe")
        else:
            posicao = lista_compras.index(velho_item)
            novo_item = input("informe um novo item: ")
            lista_compras[posicao]=novo_item
            '''
            novo_item = input("informe um novo item: ")
            print(posicao)
            lista_compas[
            '''
    else:
        print("Não é um comando válido!!!")


