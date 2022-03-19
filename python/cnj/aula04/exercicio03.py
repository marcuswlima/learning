import utilitarios as utl

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

def mostra_dicionario(dicionario,nome):
    utl.titulo(nome)
    print(dicionario)

    utl.titulo(nome+" ordenada por key crescente")
    print(sorted(dicionario.items()))

    utl.titulo(nome+" ordenada por key decrescente")
    print(sorted(dicionario.items(),reverse=True))

    utl.titulo(nome+" ordenada por value crescente")
    print(utl.dicio_ordenado_por_valor(dicionario))

    utl.titulo(nome+" ordenada por value decrescente")
    print(utl.dicio_ordenado_por_valor(dicionario,True))


#--------------------------------------
nome_arquivo="lerolero02.txt"
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

