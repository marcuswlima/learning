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
    elif 'BUTEKO' in descricao and  'MALLA' in descricao:
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
    mes_fatura='07'
    ano_fatura='2025'
    mes_lancamento = in_data_lancamento[3:]

    ano_lancamento = int(ano_fatura)
    if mes_fatura < mes_lancamento:
        ano_lancamento = int(ano_fatura)-1
    
    return in_data_lancamento + '/' + str(ano_lancamento)
    pass

# Nome dos arquivos
arquivo_origem = "2025-07.txt"
arquivo_destino = "saida.txt"

# Abrir arquivo de origem para leitura
with open(arquivo_origem, "r", encoding="utf-8") as origem:
    linhas = origem.readlines()  # Lê todas as linhas como lista

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

        categoria=func_categoria(descricao)

        nova_linha =    dia_lancamento+'\t'+\
                        descricao+'\t'+\
                        categoria+'\t'+\
                        valor+'\t'+\
                        '\n'

        print(nova_linha, end="")

print(saldoFatura)
