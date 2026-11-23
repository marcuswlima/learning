# ==================================================
# Importacoes
# ==================================================
from utilitarios import titulo, is_primo, obter_int_positivo, obter_int, is_par, obter_uma_letra, obter_float_positivito
from typing import Final


# ==================================================
# quinze()
# ==================================================
def quinze()->None:
    """
    15) O setor de RH da sua empresa te pediu uma ajuda para analisar as idades 
    de colaboradores(as) de 4 setores da empresa. Para isso, foram fornecidos os 
    seguintes dados:
        
        {'Setor A': [22, 26, 30, 30, 35, 38, 40, 56, 57, 65],
         'Setor B': [22, 24, 26, 33, 41, 49, 50, 54, 60, 64],
         'Setor C': [23, 26, 26, 29, 34, 35, 36, 41, 52, 56],
         'Setor D': [19, 20, 25, 27, 34, 39, 42, 44, 50, 65]}

    Sabendo que cada setor tem 10 colaboradores(as), construa um código que calcule a 
    média de idade de cada setor, a idade média geral entre todos os setores e quantas 
    pessoas estão acima da idade média geral.
    """
    titulo('programa quinze')

    idades = {'Setor A': [22, 26, 30, 30, 35, 38, 40, 56, 57, 65],
              'Setor B': [22, 24, 26, 33, 41, 49, 50, 54, 60, 64],
              'Setor C': [23, 26, 26, 29, 34, 35, 36, 41, 52, 56],
              'Setor D': [19, 20, 25, 27, 34, 39, 42, 44, 50, 65]
             }
    medias={}

    todas_idades=0
    
    for tupla in idades.items(): #tupla
        medias[tupla[0]]=sum(tupla[1])/10
        todas_idades += sum(tupla[1])

    print(medias)
    for tupla in medias.items(): #tupla
        print(f'Em {tupla[0]} a média é {tupla[1]}')
    
    print(f'A média total é {round(todas_idades/(10*4),2)}')


# ==================================================
# quatorze()
# ==================================================
def quatorze()->None:
    """
    14) Uma equipe de cientistas de dados está estudando a diversidade biológica em uma 
    floresta. A equipe fez a coleta de informações sobre o número de espécies de plantas e 
    animais em cada área dessa floresta e armazenou essas informações em um dicionário. 
    Nele, a chave descreve a área dos dados e os valores nas listas correspondem às espécies 
    de plantas e animais nas áreas, respectivamente.
        {'Área Norte': [2819, 7236],
        'Área Leste': [1440, 9492],
        'Área Sul': [5969, 7496],
        'Área Oeste': [14446, 49688],
        'Área Centro': [22558, 45148]}

    Escreva um código para calcular a média de espécies por área e identificar a área 
    com a maior diversidade biológica. Dica: use as funções built-in sum() e len().
    """
    titulo('programa quatorze')

    dados = {'Área Norte': [2819, 7236],
             'Área Leste': [1440, 9492],
             'Área Sul':   [5969, 7496],
             'Área Oeste': [14446, 49688],
             'Área Centro':[22558, 45148],
             'Área Nordeste':[28000, 4400008]
             }

    for dado in dados.items():  #tuplas
        print(f'Area: {dado[0]}, fauna {dado[1][0]}, flora {dado[1][1]} e a soma de especies é {dado[1][0]+dado[1][1]}')

    total_especies=0
    maior_diversidade=0
    coletas=len(dados)
    area_maior_diversidade=0

    for chave, valores in dados.items():
        total_especies += sum(valores)
        if sum(valores) > maior_diversidade:
            maior_diversidade = sum(valores)
            area_maior_diversidade = chave

    media_especies_por_area = total_especies/coletas

    print(f'A média de especies por área eh {round(media_especies_por_area,2)}')
    print(f'A area com maior diversidade é {area_maior_diversidade}')



"""
    print('nada/puro')
    for dado in dados:
        print(dado, type(dado))

    print('keys()')
    for dado in dados.keys():
        print(dado, type(dado))

    print('values()')
    for dado in dados.values():
        print(dado, type(dado))

    print('items()')
    dados = {'Área Norte': [2819, 7236],
             'Área Leste': [1440, 9492],
             'Área Sul':   [5969, 7496],
             'Área Oeste': [14446, 49688],
             'Área Centro':[22558, 45148],
             'Área Cetro':5,
             'Área Ce':'5',
             1:1,
             (32453,5453):[43564,4564],
             3:{1:2,3:3},
             30:(1,2,3,3)
             }

    print(dados)
    print(dados.values())
    print(dados.values(), type(dados.values()))

    for area, especie in dados.items():
        print(area, type(area)) 
        print(especie, type(especie)) 
        soma_especies = sum(especie)
        print(soma_especies)
        print(especie[0])
        print(especie[1])
"""


    # ==================================================
# treze()
# ==================================================
def treze()->None:
    """
    13) As pessoas colaboradoras de um setor da empresa que você trabalha vão receber um abono correspondente a 
    10% do salário devido ao ótimo desempenho do time. O setor financeiro solicitou sua ajuda para a verificação das 
    consequências financeiras que esse abono irá gerar nos recursos. Assim, foi encaminhada para você uma lista com os 
    salários que receberão o abono: [1172, 1644, 2617, 5130, 5532, 6341, 6650, 7238, 7685, 7782, 7903]. O abono de cada 
    colaborador(a) não pode ser inferior a 200. Em código, transforme cada um dos salários em chaves de um dicionário e 
    o abono de cada salário no elemento. Depois, informe o total de gastos com o abono, quantos(as) colaboradores(as) 
    receberam o abono mínimo e qual o maior valor de abono fornecido.
    """

    titulo('programa treze')

    dic_abonos = {} # Dicionário de abonos
    salarios = [1172, 1644, 2617, 5130, 5532, 6341, 6650, 7238, 7685, 7782, 7903,30]
    ABONO        : Final[float] = 0.3
    ABONO_MINIMO : Final[int] = 200

    for salario in salarios:
        abono = salario * ABONO
        if abono<ABONO_MINIMO:
            abono=ABONO_MINIMO

        dic_abonos[salario]=abono

    total_de_abonos=0
    maior_abono=0
    abono_200=0
    for abono in dic_abonos.values():
        total_de_abonos += abono
        if abono > maior_abono:
            maior_abono = abono
        if abono==ABONO_MINIMO:
            abono_200 += 1

    print()
    print(f'* Salários: \n {salarios}')
    print(f'* Abonos: \n {dic_abonos}')
    print()
    print(f'* Total de gastos com abono: {total_de_abonos}')
    print(f'* O maio abono será de {maior_abono}')
    print(f'* Abono mínimo {abono_200}')
    print()



# ==================================================
# doze()
# ==================================================
def doze()->None:
    pass
    """
    12) Uma pesquisa de mercado foi feita para decidir qual design de marca infantil mais agrada as crianças. 
    A pesquisa foi feita e o votos computados podem ser observados abaixo:
    '''
    Tabela de votos da marca
    Design 1 - 1334 votos
    Design 2 - 982 votos
    Design 3 - 1751 votos
    Design 4 - 210 votos
    Design 5 - 1811 votos
    '''
    Adapte os dados fornecidos para uma estrutura de dicionário. A partir dele, informe o design vencedor e a porcentagem de votos recebidos.
    """
    titulo('programa doze')

    votos={'1':1334,'2':982,'3':1751,'4':210,'5':1811}

    todos_votos=0
    maior_votacao=0
    o_mais_votado=''
    for i in votos.keys():
        todos_votos += votos[i]
        if votos[i] > maior_votacao:
            maior_votacao = votos[i]
            o_mais_votado = i

    print(f'Todos os votos: {todos_votos}')
    print(f'O mais votado foi Design {o_mais_votado} com {maior_votacao} votos')
    print(f'e representa {round(maior_votacao*100/todos_votos,2)}% de todos os votos')



# ==================================================
# onze()
# ==================================================
def onze()->None:
    pass
    """
    11) Uma empresa de e-commerce está interessada em analisar as vendas dos seus produtos. Os dados das vendas foram armazenados em um dicionário:
    {'Produto A': 300, 'Produto B': 80 , 'Produto C': 60,'Produto D': 200, 'Produto E': 250, 'Produto F': 30}
    Escreva um código que calcule o total de vendas e o produto mais vendido.
    """
    titulo('programa onze')

    vendas={'Produto A': 300, 'Produto B': 80 , 'Produto C': 60,'Produto D': 200, 'Produto E': 250, 'Produto F': 30}

    maior_venda=0
    produto_mais_vendido=''
    total_vendas=0

    for chave in vendas.keys():
        total_vendas += vendas[chave]
        if vendas[chave] > maior_venda:
            maior_venda = vendas[chave]
            produto_mais_vendido = chave

    print(f'Total de vendas:{total_vendas}')
    print(f'O {produto_mais_vendido} foi o produto mais vendido com {maior_venda} vendas')






# ==================================================
# dez()
# ==================================================
def dez()->None:
    pass
    """
    10) Um instituto de meteorologia deseja fazer um estudo de temperatura média de cada mês do ano. 
    Para isso, você precisa fazer um código que colete e armazene essas temperaturas médias em uma lista. 
    Depois, calcule a média anual das temperaturas e mostre todas as temperaturas acima da média anual e em 
    que mês elas ocorreram, mostrando os meses por extenso (Janeiro, Fevereiro, etc.).
    """
    titulo('programa dez')

    meses=['Janeiro','Fevereiro','Março','Abril','Maio','Junho','Julho','Agosto','Setembro','Outubro','Novembro','Dezembro']
    temperaturas=[]

    for i in range(0,12):
        temperaturas.append(obter_float_positivito(f'Informe para o mes de {meses[i]}'))
    
    media_temperatira = sum(temperaturas) / len(temperaturas)

    print(f'Media de Temperatura: {media_temperatira}')

    meses_acima=[]
    meses_abaixo=[]

    for i in range(0,12):
        if temperaturas[i]>media_temperatira:
            meses_acima.append(meses[i])
        else:
            meses_abaixo.append(meses[i])

    print(f'Os meses acima são: \n{meses_acima}')
    print(f'Os meses abaixo são: \n{meses_abaixo}')

# ==================================================
# nove()
# ==================================================
def nove()->None:
    pass
    """
    9) Desenvolva um programa que informa a nota de um(a) aluno(a) de acordo com suas respostas. Ele deve pedir a 
    resposta desse(a) aluno(a) para cada questão e é preciso verificar se a resposta foi igual ao gabarito. Cada questão 
    vale um ponto e existem as alternativas A, B, C ou D.
    """
    titulo('programa nove')
    gabarito = ['D', 'A', 'C', 'B', 'A', 'D', 'C', 'C', 'A', 'B']
    respostas = []
    nota=0

    for i in range(0,10):
        respostas.append(obter_uma_letra(f'Informe a {i+1}° resposa').upper())

    print(gabarito)
    print(respostas)

    for i in range(0,10):
        if gabarito[i]==respostas[i]:
            nota += 1

    print(f'notas: {nota}')


# ==================================================
# oito()
# ==================================================
def oito()->None:
    pass
    """
    8) Para uma seleção de produtos alimentícios, precisamos separar o conjunto de IDs dados por números 
    inteiros sabendo que os produtos com ID par são doces e os com ID ímpar são amargos. Monte um código 
    que colete 10 IDs. Depois, calcule e mostre a quantidade de produtos doces e amargos.
    """
    titulo('programa oito')

    ids=[]
    doces=0
    amargos=0

    for i in range(1,11):
        ids.append(obter_int(f'Digite o {i}° ID'))

    for id in ids:
        print(id)
        if is_par(id):
            doces += 1
        else:
            amargos += 1

    print(f'Doces: {doces}')
    print(f'Amargos: {amargos}')

# ==================================================
# sete()
# ==================================================
def sete()->None:
    pass
    """
    7) Para um estudo envolvendo o nível de multiplicação de bactérias em uma colônia, foi coletado o número de bactérias por dia 
    (em milhares) e pode ser observado a seguir: [1.2, 2.1, 3.3, 5.0, 7.8, 11.3, 16.6, 25.1, 37.8, 56.9]. Tendo esses valores, 
    faça um código que gere uma lista contendo o percentual de crescimento de bactérias por dia, comparando o número de bactérias em 
    cada dia com o número de bactérias do dia anterior. Dica: para calcular o percentual de crescimento usamos a seguinte equação: 
        100 * (amostra_atual - amostra_passada) / (amostra_passada).
    """
    titulo('programa sete')

    amostras=[1.2, 2.1, 3.3, 5.0, 7.8, 11.3, 16.6, 25.1, 37.8, 56.9]

    for i in range(len(amostras)):
        amostra_atual = 0
        amostra_passada = 0
        crescimento = 0 

        amostra_atual = amostras[i]
        if i==0:
            cescimento=0
        else:
            amostra_passada = amostras[i-1]
            crescimento=100 * (amostra_atual - amostra_passada) / amostra_passada

        print(amostra_atual, round(crescimento,2))

    #--------–        
    amostras=[1.2, 2.1, 3.3, 5.0, 7.8, 11.3, 16.6, 25.1, 37.8, 56.9]
    porcentagem_crescimento = [0]
    for i in range(1,len(amostras)):
        print(amostras[i])
        porcentagem = 100 * (amostras[i] - amostras[i-1]) / amostras[i-1]
        porcentagem_crescimento.append(porcentagem)
    
    print(f'Porcentagens de crescimento:\n{porcentagem_crescimento}')



# ==================================================
# seis()
# ==================================================
def seis()->None:
    pass
    """
    6) Escreva um programa que peça uma data informando o dia, mês e ano e determine se ela é válida para uma análise.
    """
    titulo('programa 06')

    bEhValido=True
    
    dia = obter_int_positivo('Informe o dia')
    mes = obter_int_positivo('Informe o mes')
    ano = obter_int_positivo('Informe o ano')

    if mes == 2:
        if ano % 4 == 0 and ( ano % 400 ==0 or ano % 100 != 0):
            dias_02 = 29
        else:
            dias_02 = 28

        if not( dia >= 1 and dia <= dias_02):
            bEhValido=False
    elif mes in [1,5,7,8,10,12]:
        if not( dia >= 1 and dia <= 31):
            bEhValido=False
    elif mes in [4,6,9,11]:
        if not( dia >= 1 and dia <= 30):
            bEhValido=False
    else:
        bEhValido=False

    if bEhValido:
        print('Valido')
    else:
        print('Invalido')

# ==================================================
# cinco()
# ==================================================
def cinco()->None:
    """
    5) Faça um programa que, ao inserir um número qualquer, cria uma lista contendo todos os números primos entre 1 e o número digitado.
    """
    titulo('programa 05')

    primos=[]

    numero = int(input("Informe um número: "))

    for i in range(1,numero):
        #print(i)
        if is_primo(i):
            primos.append(i)

    print(primos)

# ==================================================
# quantro()
# ==================================================
def quatro()->None:
    """
    4) Colete novamente 5 inteiros e imprima a lista em ordem inversa à enviada.
    """
    titulo('programa 04')

    lista=[]

    for i in range(1,5):
        lista.append(int(input('Informe um número: ')))

    print(lista)
    print(sorted(lista))


# ==================================================
# tres()
# ==================================================
def tres()->None:
    """
    3) Faça um código que colete em uma lista 5 números inteiros quaisquer e imprima a lista. 
    """
    titulo('programa 03')

    lista=[]

    for i in range(0,5):
        lista.append(int(input('Informe um número: ')))

    print(lista)


# ==================================================
# dois()
# ==================================================
def dois()->None:
    """
    2) Com os mesmos dados da questão anterior, defina quantas compras foram realizadas acima de 3000 
    reais e calcule a porcentagem quanto ao total de compras.
    """
    titulo('programa 02')
    VALOR_30_MIL : Final[int] = 3000

    gastos=[2172.54, 3701.35, 3518.09, 3456.61, 3249.38, 2840.82, 3891.45, 3075.26, 2317.64, 3219.08, 3, 40000.01]

    soma_gostos=sum(gastos)
    qtd_gastos=len(gastos)
    media_gastos = soma_gostos/qtd_gastos
    qtd_acima_30_mil=0
    valor_acima_30_mil=0

    print(f'A soma de gastos é: {soma_gostos}')
    print(f'A quantidade de gastos é: {qtd_gastos}')
    print(f'A media de gastos é: {media_gastos}')

    for gasto in gastos:
        if gasto >= VALOR_30_MIL:
            qtd_acima_30_mil += 1
            valor_acima_30_mil += gasto 

    print(f'Quantidade de gastos acima de 30mil: {qtd_acima_30_mil}')
    print(f'Gastos acima de 30mil: {valor_acima_30_mil}')

# ==================================================
# um()
# ==================================================
def um()->None:
    """
    1) Faça um programa que tenha a seguinte lista contendo os valores de gastos de uma 
    empresa de papel [2172.54, 3701.35, 3518.09, 3456.61, 3249.38, 2840.82, 3891.45, 
    3075.26, 2317.64, 3219.08]. Com esses valores, faça um programa que calcule a média de gastos. 
    Dica: use as funções built-in sum() e len().
    """
    titulo('programa 01')
    gastos=[2172.54, 3701.35, 3518.09, 3456.61, 3249.38, 2840.82, 3891.45, 3075.26, 2317.64, 3219.08]

    soma_gostos=sum(gastos)
    qtd_gastos=len(gastos)
    media_gastos = soma_gostos/qtd_gastos

    print(f'A soma de gastos é: {soma_gostos}')
    print(f'A quantidade de gastos é: {qtd_gastos}')
    print(f'A media de gastos é: {media_gastos}')



# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    titulo('MENU PRINCIPAL')
    print("1 - um")
    print("2 - dois")
    print("3 - Tres")
    print("4 - quatro")
    print("0 - Sair")
    print(" ")

# ==================================================
# main
# ==================================================
def main()-> None:
    while True:
        exibir_menu()
        opcao=int(input("Escolha uma opção (0 para encerrar): "))

        if opcao==0:
            print('Encerrando...')
            break
        elif opcao==1:
            um()
        elif opcao==2:
            dois()
        elif opcao==3:
            tres()
        elif opcao==4:
            quatro()
        elif opcao==5:
            cinco()
        elif opcao==6:
            seis()
        elif opcao==7:
            sete()
        elif opcao==8:
            oito()
        elif opcao==9:
            nove()
        elif opcao==10:
            dez()
        elif opcao==11:
            onze()
        elif opcao==12:
            doze()
        elif opcao==13:
            treze()
        elif opcao==14:
            quatorze()
        elif opcao==15:
            quinze()
        else:
            print('Opção Inválida')

        print()

if __name__ == "__main__":
    main()        

