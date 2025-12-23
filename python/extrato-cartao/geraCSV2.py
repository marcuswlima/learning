# Lê todas as linhas de um arquivo e copia para outro

def extrair_dia(data_lancamento):
    return data_lancamento[0:2]

def extrair_mes(data_lancamento):
    return data_lancamento[3:5]

def extrair_ano(data_lancamento):
    return data_lancamento[6:10]

def func_categoria(descricao):
    resposta=''
    if 'LIDER' in descricao and 'SUPER' in descricao:
        resposta = 'Manutenção AP'
    elif 'IFOOD *IFOOD' in descricao:
        resposta = 'Refeição Marcus'
    elif 'FACULDADE COSMOPOLITA' in descricao:
        resposta = 'Izabel'
    elif 'AMAZONPRIMEBR' in descricao:
        resposta = 'Applications'
    elif 'SPOTIFY' in descricao:
        resposta = 'Applications'
    elif 'NETFLIX.COM' in descricao:
        resposta = 'Applications'
    elif 'UBER' in descricao and 'EATS' in descricao:
        resposta = 'Refeição Marcus'
    elif 'UBER' in descricao and not 'EATS' in descricao:
        resposta = 'Taxi'
    elif 'AMAZON.COM.BR DIGITAL' in descricao:
        resposta = 'Livros'
    elif 'FERREGUETE' in descricao:
        resposta = 'Passeios / Lazer'
    elif 'DOM' in descricao and  'BOSCO' in descricao:
        resposta = 'IDB'
    elif 'BUTEKO' in descricao or 'MALLA' in descricao or 'COMPRE BEM CONVENIEN' in descricao:
        resposta = 'Passeios / Lazer'
    elif '99' in descricao:
        resposta = 'Taxi'
    elif ('SAN TITO' in descricao) \
        or ('BARONCLUB' in descricao) \
        or ('PICANHADPEDY' in descricao) \
        or ('ACAI' in descricao) \
        or ('RODRIGODECASTRO' in descricao) \
        or ('CAFEDAGRACA' in descricao) \
        or ('IFD' in descricao) \
        or ('JA REFEICOES' in descricao) \
        or ('TACACA DO RENATO' in descricao) \
        or ('COSANOSTRA' in descricao) \
        or ('EMPORIO DA PRACA' in descricao) \
        or ('GALETO EXPRESS' in descricao):
        resposta = 'Refeição Marcus'
    return resposta
    pass

def tratar_valor(valor):
    out_valor=valor

    out_valor=out_valor.replace(',','.')

    if out_valor.count('.') > 1:
        out_valor=out_valor.replace('.',',',1)

    if out_valor.find('-')>=0:
        out_valor=out_valor.replace('-','')
    else:
        out_valor='-'+out_valor
    
    return out_valor
    pass

def tratar_data(in_data_lancamento):
    mes_fatura='09'
    ano_fatura='2025'
    mes_lancamento = in_data_lancamento[3:]

    ano_lancamento = int(ano_fatura)
    if mes_fatura < mes_lancamento:
        ano_lancamento = int(ano_fatura)-1
    
    return in_data_lancamento + '/' + str(ano_lancamento)
    pass

# Nome dos arquivos
nome_arquivo_origem = "2025-09.txt"
nome_arquivo_destino = "saida.txt"
arquivo_csv = open(nome_arquivo_destino, "w")


# Abrir arquivo de origem para leitura
with open(nome_arquivo_origem, "r", encoding="utf-8") as origem:
    linhas = origem.readlines()  # Lê todas as linhas como lista



## Iniciar registro
rLinhas = []  # Lista vazia para armazenar os registros

saldoFatura=0
for linha in linhas:
    #print(linha, end="")

    primeiraletra = linha[0:1]
    if primeiraletra in ('1','2','3','4','5','6','7','8','9','0'):
        inicio=0
        if linha[1:2]==' ':
            inicio=2
        
        linha = linha[inicio:]

        dia_mes=linha[0:linha.find(' ')]
        dia_mes=dia_mes.strip()

        valor=linha[linha.rfind(' ')+1:len(linha)-1]
        valor=valor.strip()

        saldoFatura = saldoFatura + float(valor.replace(",", "."))

        linha=linha.replace(dia_mes,'')
        linha=linha.replace(valor,'')
        descricao=linha.strip()
        dia_lancamento=tratar_data(dia_mes)
        valor=tratar_valor(valor)
        dia = dia_lancamento[0:2]
        mes = dia_lancamento[3:5]
        ano = dia_lancamento[6:10]

        categoria=func_categoria(descricao)

        nova_linha =    dia_lancamento+'\t'+\
                        descricao+'\t'+\
                        categoria+'\t'+\
                        valor+'\t'+ \
                        dia +'\t' + \
                        mes +'\t' + \
                        ano +'\t' + \
                        '\n'

#        print(nova_linha, end="")
        arquivo_csv.write(nova_linha)
        rLinhas.append({"data": dia_lancamento, "descricao": descricao, "categoria": categoria, "valor": valor, "dia" : dia, "mes" : mes, "ano" : ano})        


print(saldoFatura)

ordenados = sorted(rLinhas, key=lambda r: (r["ano"], r["mes"], r["dia"]))

for i, r in enumerate(rLinhas):
    print(f"{r['data']} {r['descricao']} - {r['categoria']} - {r['valor']}")


'''
ordenados = sorted(rLinhas, key=lambda r: r["dia"])

for i, r in enumerate(ordenados):
    print(f"{i}: {r['dia']} {r['descricao']} - {r['categoria']} - {r['valor']}")

'''