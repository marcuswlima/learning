"""Leitua arquivo TJSP.cvs - ExercicioExtra 05-02

Lê o arquivo e contabiliza os a quantaide de processos
na fase de conhecimento agrupado por códigoIBGE

"""
import utilitarios as utl
import csv

#------------------------------------------
arq = open("TJSP.csv","r") #abrir aquivo para leitura
csv_reader = csv.reader(arq,delimiter=';')

next(csv_reader)#pular a primeira linha

resposta={}

for linha in csv_reader:
    fase_processual = linha[10]
    codigo_ibge = linha[24]

    if fase_processual=="1":
        if codigo_ibge not in resposta:
            resposta[codigo_ibge] = 1
        else:
            resposta[codigo_ibge] += 1

print(resposta)

print("Código IGBE \t ProcessoNaFase1")
for chave, valor in resposta.items():
    print(str(chave)+'\t\t'+str(valor))

