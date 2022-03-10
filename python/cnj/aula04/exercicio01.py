import utilitarios

def registra_palavra(palavra):
    if palavra not in dict_palavras:
        dict_palavras[palavra] = 1
    else:
        dict_palavras[palavra] += 1

def registra_letra(letra):
    if letra not in dict_letras:
        dict_letras[letra] = 1
    else:
        dict_letras[letra] += 1

def inverter_dict(dicionario):
    '''
    Gerar uma lista de tuplas apartir de um dictionary
    onde são trocados key e value
    '''
    resposta=[]
    for d in dicionario:
        tupla=(dicionario[d],d)
        resposta.append(tupla)
    return resposta

def inverter_lista_tupla(lista):
    '''
    Em uma lista de tuplas com 2 elementos inverter a sequencias
    dos elementos de cada tupla
    '''
    resposta=[]
    for t in lista:
        tupla=(t[1],t[0])
        resposta.append(tupla)
    return resposta
        

def ordernar_por_value(dicionario,in_reverse=False):
    resposta=inverter_dict(dicionario)
    resposta=sorted(resposta,reverse=in_reverse)
    resposta=inverter_lista_tupla(resposta)
    return resposta

def mostra_dicionario(dicionario,nome):
    utilitarios.titulo(nome)
    print(dicionario)

    utilitarios.titulo(nome+" ordenada por key crescente")
    print(sorted(dicionario.items()))

    utilitarios.titulo(nome+" ordenada por key decrescente")
    print(sorted(dicionario.items(),reverse=True))

    utilitarios.titulo(nome+" ordenada por value crescente")
    print(ordernar_por_value(dicionario))

    utilitarios.titulo(nome+" ordenada por value decrescente")
    print(ordernar_por_value(dicionario,True))


#--------------------------------------
nome_arquivo="lerolero01.txt"
dict_palavras = dict()
dict_letras = dict()

arquivo = open(nome_arquivo, "r")

for linha in arquivo:
    linha = linha.strip()
    palavra = "" 
    for caracter in linha:
        registra_letra(caracter)
        if caracter != " ":
            palavra = palavra+caracter
        else:
            registra_palavra(palavra)
            palavra = ''
    registra_palavra(palavra)

arquivo.close()

mostra_dicionario(dict_palavras,"palavras")
mostra_dicionario(dict_letras,"letras")

