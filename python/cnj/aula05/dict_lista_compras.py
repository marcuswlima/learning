import utilitarios as utl
import csv
def carregar_arquivo():
    dicio= {}
    arq = open("produtos.mwb","r")
    csv_reader = csv.reader(arq,delimiter = ';')
    for linha in csv_reader:
        dicio[linha[0]]=linha[1]
    arq.close()
    return dicio

def obter_item(mensagem):
    valor_obtido=input("\t"+mensagem)
    return valor_obtido

def pesquisar_item(in_dicio,in_item):
    achou=in_item in in_dicio
    if not achou:
        print("\tO item \"{}\" não está na lista".format(in_item))
    return achou

def persistir_arquivo(in_dicio):
    arq = open("produtos.mwb","w")
    for chave, valor in in_dicio.items():
        linha=chave +';'+ valor +'\n'
        arq.write(linha)
    arq.close()

#----------------------------------------------------------
utl.titulo("Manutenção da lista lista_compras - Dict")

dicio_compras = carregar_arquivo()
comando = ""

print(dicio_compras)

while(comando!="exit"):

    comando = input("Informe o comando [exit, add, remove, update, list]: ")
    if comando=='list':
        print(dicio_compras)
    elif comando=='add':
        item = obter_item("informe um novo item: ")
        quantidade = obter_item("informe a nova quantidade: ")
        dicio_compras[item]=quantidade
    elif comando=='remove':
        item = obter_item("informe o item a ser removido: ")
        if pesquisar_item(dicio_compras,item):
            del dicio_compras[item]
    elif comando=='update':
        print(dicio_compras)
        item = obter_item("informe o item a ser alterado: ")
        if pesquisar_item(dicio_compras,item):
            quantidade = obter_item("informe a nova quantidade: ")
            dicio_compras[item]=quantidade
    elif comando=='exit':
        pass
    else:
        print("\tNão é um comando válido!!!")

persistir_arquivo(dicio_compras)