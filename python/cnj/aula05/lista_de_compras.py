import utilitarios as utl
import csv

def obter_item(mensagem):
    valor_obtido=input("\t"+mensagem)
    return valor_obtido

def carregar_arquivo():
    lista_compras2 = []
    arq = open("produtos.mwb","r")
    csv_reader = csv.reader(arq,delimiter = ';')
    for linha in csv_reader:
        tupla=(linha[0],linha[1])
        lista_compras2.append(tupla)
    arq.close()
    return lista_compras2

def pesquisar_item(in_lista,in_item):
    achou=False
    for tupla in in_lista:
        if in_item in tupla:
            return True
    print("\tO item \"{}\" não está na lista".format(in_item))
    return achou

def qual_quantidade(in_lista,in_item):
    for tupla in in_lista:
        if in_item in tupla:
            return tupla[1]

def qual_posicao(in_lista, in_item):
    contador=0
    for tupla in in_lista:
        if in_item in tupla:
            return contador
        contador += 1

def persistir_arquivo(lista):
    arq = open("produtos.mwb","w")
    for tupla in lista:
        linha=tupla[0]+';'+tupla[1]+'\n'
        arq.write(linha)
    arq.close()

#----------------------------------------------------------
utl.titulo("Manutenção da lista lista_compras")

lista_compras = carregar_arquivo()
comando = ""

print(lista_compras)
while(comando!="exit"):

    comando = input("Informe o comando [exit, add, remove, update, list]: ")

    if comando=='list':
        print(lista_compras)
    elif comando=='add':
        item = obter_item("informe um novo item: ")
        quantidade = obter_item("informe a nova quantidade: ")
        lista_compras.append((item,quantidade))
    elif comando=='remove':
        print(lista_compras)
        item = obter_item("informe o item a ser removido: ")
        if pesquisar_item(lista_compras,item):
            quantidade=qual_quantidade(lista_compras,item)
            lista_compras.remove((item,quantidade))
    elif comando=='update':
        print(lista_compras)
        item = obter_item("informe o item a ser alterado: ")
        if pesquisar_item(lista_compras,item):
            posicao = qual_posicao(lista_compras,item)
            quantidade = obter_item("informe a nova quantidade: ")
            lista_compras[posicao]=(item,quantidade)
    elif comando=='exit':
        pass
    else:
        print("\tNão é um comando válido!!!")

persistir_arquivo(lista_compras)


