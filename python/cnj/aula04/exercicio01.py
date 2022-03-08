
nome_arquivo="lerolero01.txt"
dict_palavras = dict()
lista_palavras = []

arquivo = open(nome_arquivo, "r")

def registra(palavra):
    if palavra not in dict_palavras:
        dict_palavras[palavra] = 1
    else:
        dict_palavras[palavra] += 1

count_cacarter = 0

for linha in arquivo:
    linha = linha.strip()
    lista_palavras.append(linha)
    palavra = "" 
    for caracter in linha:
        count_cacarter += 1 
        if caracter != " ":
            palavra = palavra+caracter
        else:
            registra(palavra)
            palavra = ''
    registra(palavra)

arquivo.close()

#print(lista_palavras)
print(dict_palavras)

for item in dict_palavras:
    print(item,dict_palavras[item])
    

print("quantidade de caracteres", count_cacarter) 
