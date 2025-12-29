def func_categoria(descricao):
    resposta=''
    descricao = descricao.upper()
    #print(descricao)
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
    elif 'MERCADINHO BRAZAO' in descricao:
        resposta = 'Passeios / Lazer'
    elif 'BUTEKO' in descricao or 'MALLA' in descricao or 'COMPRE BEM CONVENIEN' in descricao:
        resposta = 'Passeios / Lazer'
    elif '99' in descricao:
        resposta = 'Taxi'
    elif 'PRO-MUSIC' in descricao:
        resposta = 'Música'
    elif ('SAN TITO' in descricao) \
        or ('BARONCLUB' in descricao) \
        or ('PICANHADPEDY' in descricao) \
        or ('RESTAURANTE ROTA' in descricao) \
        or ('ACAI' in descricao) \
        or ('RODRIGODECASTRO' in descricao) \
        or ('CAFEDAGRACA' in descricao) \
        or ('IFD' in descricao) \
        or ('JA REFEICOES' in descricao) \
        or ('TACACA DO RENATO' in descricao) \
        or ('COSANOSTRA' in descricao) \
        or ('EMPORIO DA PRACA' in descricao) \
        or ('MP*RMCANTINA' in descricao) \
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


nome_arquivo_origem = "2026-01.txt"
nome_arquivo_destino = "saida.txt"
arquivo_csv = open(nome_arquivo_destino, "w")

# Abrir arquivo de origem para leitura
with open(nome_arquivo_origem, "r", encoding="utf-8") as origem:
    linhas = origem.readlines()  # Lê todas as linhas como lista

## Iniciar registro
rLinhas = []  # Lista vazia para armazenar os registros

for linha in linhas:
    #print("#####",linha, end="")
    data_lacamento = linha[0:10]
    descricao = linha[11:linha.find("US$")-1]
    categoria = func_categoria(descricao)
    valor = linha[linha.find("R$")+3:len(linha)]
    valor = tratar_valor(valor)
    #print(data_lacamento, descricao, categoria, valor, end="")
    nova_linha =    data_lacamento+'\t'+\
                    descricao+'\t'+\
                    categoria+'\t'+\
                    valor

    rLinhas.append({"data": data_lacamento, "descricao": descricao, "categoria": categoria, "valor": valor})        


    arquivo_csv.write(nova_linha)
    print(nova_linha, end="")

#ordenados = sorted(rLinhas, key=lambda r: (r["valor"]))

#for linha in ordenados:
    #print(linha)
