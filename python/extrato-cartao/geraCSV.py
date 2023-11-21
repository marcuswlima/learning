def extrair_dia(data_lancamento):
    return data_lancamento[0:2]

def extrair_mes(data_lancamento):
    return data_lancamento[3:5]

def extrair_ano(data_lancamento):
    return data_lancamento[6:10]

def tratar_valor(valor):
    out_valor=valor

    out_valor=out_valor.replace(',','.')

    if out_valor.count('.') > 1:
        out_valor=out_valor.replace('.',',',1)

    if out_valor.find('-')>=0:
        out_valor=out_valor.replace('-','')
    else:
        out_valor='-'+out_valor
    
    out_valor=out_valor.replace(',','')
    out_valor=out_valor.replace('.',',')
    return '"'+out_valor+'"'
    pass



def tratar_data(in_data_lancamento):
    mes_fatura='11'
    ano_fatura='2023'
    mes_lancamento = in_data_lancamento[3:]

    ano_lancamento = int(ano_fatura)
    if mes_fatura < mes_lancamento:
        ano_lancamento = int(ano_fatura)-1
    
    return in_data_lancamento + '/' + str(ano_lancamento)
    pass

def func_categoria(descricao):
    resposta=''
    if 'LIDER' in descricao:
        resposta = 'Manutenção AP'
    if 'LIDER' in descricao and 'SUPER' in descricao:
        resposta = 'Manutenção AP'
    elif 'IFOOD' in descricao:
        resposta = 'Refeição Marcus'
    elif 'IFOOD *IFOOD' in descricao:
        resposta = 'Refeição Marcus'
    elif 'UNINASSAU' in descricao:
        resposta = 'Izabel'
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
    elif 'BUTEKO' in descricao in descricao:
        resposta = 'Passeios / Lazer'
    elif '99' in descricao:
        resposta = 'Taxi'
    elif ('SAN TITO' in descricao) \
        or ('BARONCLUB' in descricao) \
        or ('PICANHADPEDY' in descricao) \
        or ('ACAI' in descricao) \
        or ('JA REFEICOES' in descricao) \
        or ('TACACA DO RENATO' in descricao) \
        or ('COSANOSTRA' in descricao) \
        or ('EMPORIO DA PRACA' in descricao) \
        or ('CEARACARNESESERVI' in descricao) \
        or ('GALETO EXPRESS' in descricao):
        resposta = 'Refeição Marcus'
    return resposta
    pass

def gerar_arquivo():
    nome_arquivo="2023-11.txt"
    nome_arquivo_csv="C:\\Users\marcus.william\Developer\github\_dados\\"+nome_arquivo.replace('.txt','')+'.cvs'
    #nome_arquivo_csv="/home/marcus/Developer/github/_dados/"+nome_arquivo.replace('.txt','')+'.cvs'

    print(nome_arquivo_csv)
    
    
    arquivo = open(nome_arquivo, "r")
    arquivo_csv = open(nome_arquivo_csv, "w")

    for linha in arquivo:
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

            linha=linha.replace(dia_mes,'')
            linha=linha.replace(valor,'')
            descricao=linha.strip()
            dia_lancamento=tratar_data(dia_mes)
            valor=tratar_valor(valor)

            categoria=func_categoria(descricao)

            nova_linha = extrair_ano(dia_lancamento)+'\t'+\
                         extrair_mes(dia_lancamento)+'\t'+\
                         extrair_dia(dia_lancamento)+'\t'+\
                         valor+'\t'+\
                         dia_lancamento+'\t'+\
                         descricao+'\t'+\
                         categoria+'\t'+\
                         valor+'\t'+\
                         '\n'

            print(nova_linha)
            arquivo_csv.write(nova_linha)

    arquivo.close()
    arquivo_csv.close()

#------------------------------------------
#print(tratar_data('02/02'))
#print(tratar_data('02/11'))
gerar_arquivo()
#print(tratar_valor('-0,2'))