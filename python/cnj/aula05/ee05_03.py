"""Leitua arquivo TJSP.cvs - ExercicioExtra 05-03

Lê o arquivo TJSP.csv e contabiliza a quantaide de processos
na fase de conhecimento agrupado por códigoIBGE
"""
import utilitarios as utl
import csv

from operator import itemgetter

def dicio_ordernado_por_valor(in_dicio, in_reverse=False):
    """dicio_ordernado_por_valor

    Returns a new dictionary sorted by value.
    If in_reverse=False then from minor to major, otherwise
    from major to minor (default=False)
    """
    
    out_dicio={}
    for item in sorted(in_dicio.items(),key=itemgetter(1),reverse=in_reverse):
        out_dicio[item[0]]=item[1]

    return out_dicio

#------------------------------------------
arq = open("TJSP.csv","r") #abrir aquivo para leitura

primeira_linha = arq.readline()
primeira_linha = primeira_linha.replace('"','')
lista = primeira_linha.split(';')

indice_fase_processual = lista.index('faseProcessual')
indice_codigo_ibge = lista.index('codigoLocalidade')

csv_reader = csv.reader(arq,delimiter=';')

resposta={}

for linha in csv_reader:
    fase_processual = linha[indice_fase_processual]
    codigo_ibge = linha[indice_codigo_ibge]

    if fase_processual=="1":
        if codigo_ibge not in resposta:
            resposta[codigo_ibge] = 1
        else:
            resposta[codigo_ibge] += 1

resposta = dicio_ordernado_por_valor(resposta,True)
print("Código IGBE\tProcessoNaFase1")
for chave, valor in resposta.items():
    print(str(chave)+'\t\t'+str(valor))


