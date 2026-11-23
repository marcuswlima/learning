"""
Instituição: Alura
Carreira: Engenheiro de Dados
Curso: "Python para Dados: trabalhando com funções, estruturas de dados e exceções"
Capítulo: 03-Estruturas de Dados

Autor: Marcus William dos Santos Lima
Data: 12/10/2026
"""

# ==================================================
# Bibliotecas/Importações
# ==================================================
from utilitarios import imprimir_titulo         ,\
                        gerar_tupla_com_inteiros,\
                        gerar_nome              ,\
                        gerar_um_decimal        ,\
                        gerar_um_inteiro        ,\
                        calcular_imc            ,\
                        gerar_nome_completo     ,\
                        obter_inteiro_nao_negativo
from typing import Final

# ==================================================
# dez()
# ==================================================
def dez()->None:
    """
    10. Nessa mesma tabela de cadastro de filiais, há uma coluna com as informações da quantidade de pessoas colaboradoras e 
    o(a) gestor(a) gostaria de ter um agrupamento da soma dessas pessoas para cada estado. As informações contidas na tabela são:
        
        funcionarios = [('SP', 16), ('ES', 8), ('MG', 9), ('MG', 6), ('SP', 10), ('MG', 4), ('ES',9), ('ES', 7), ('ES', 12), ('SP', 7), ('SP', 11), ('MG',8), ('ES',8), ('SP',9), ('RJ', 13), ('MG', 5), ('RJ', 9), ('SP', 12), ('MG', 10), ('SP', 7), ('ES', 14), ('SP', 10), ('MG', 12)]

    A partir da lista de tuplas, crie um dicionário em que as chaves são os nomes dos Estados únicos e os valores são as 
    listas com o número de colaboradores(as) referentes ao Estado. Crie também um dicionário em que as chaves são os nomes dos 
    Estados e os valores são a soma de colaboradores(as) por Estado.

    Dica: Você pode fazer um passo intermediário para gerar uma lista de listas em que cada uma das listas possui apenas os 
    valores numéricos de funcionários(as) de cada Estado.
    """
    imprimir_titulo(in_mensagem='Programa dez')

    quant_funcionarios_nas_filiais = [('SP', 16), ('ES', 8),  ('MG', 9),  ('MG', 6), ('SP', 10), ('MG', 4),  
                                      ('ES',9),   ('ES', 7),  ('ES', 12), ('SP', 7),  ('SP', 11), ('MG',8),  
                                      ('ES',8),   ('SP',9),   ('RJ', 13), ('MG', 5), ('RJ',9), ('SP', 12), 
                                      ('MG', 10), ('SP', 7), ('ES', 14), ('SP', 10), ('MG', 12)
                                      ]
    print(f'quant_funcionarios_nas_filiais: {type(quant_funcionarios_nas_filiais)} - {quant_funcionarios_nas_filiais}')

    estados_do_sudeste = list(set([quant_funcionario_em_uma_filial[0] 
                                       for quant_funcionario_em_uma_filial in quant_funcionarios_nas_filiais]
                                 )
                            )
    print(f'estados_do_sudeste: {type(estados_do_sudeste)} - {estados_do_sudeste}')

    for estado_do_sudeste in estados_do_sudeste:
        temp=[quant_funcionario_em_uma_filial[0] 
                 for quant_funcionario_em_uma_filial in quant_funcionarios_nas_filiais 
                     if quant_funcionario_em_uma_filial[0]==estado_do_sudeste[0]
              ]

    estados = {'Bahia': 1, 'São Paulo': 2, 'Goiás': 3}
    estados["Amazonas"]


# ==================================================
# nove()
# ==================================================
def nove()->None:
    """
    9. Uma empresa possui filiais espalhadas nos Estados da região Sudeste do Brasil. Em uma das 
    tabelas de cadastro das filiais há uma coluna contendo a informação de qual é o Estado a que 
    pertence: 
    
    estados = ['SP', 'ES', 'MG', 'MG', 'SP', 'MG', 'ES', 'ES', 'ES', 'SP', 'SP', 'MG', 'ES', 'SP', 'RJ', 'MG', 'RJ', 'SP', 'MG', 'SP', 'ES', 'SP', 'MG'].
    
    A empresa sempre está abrindo novas filiais, de modo que a tabela está constantemente recebendo 
    novos registros e o gestor gostaria de possuir a informação atualizada da quantidade de 
    filiais em cada Estado.

    A partir da coluna com a informação dos Estados, crie um dicionário usando dict 
    comprehension com a chave sendo o nome de um Estado e o valor sendo a contagem de vezes 
    em que o Estado aparece na lista.

    Dica: Você pode fazer um passo intermediário para gerar uma lista de listas em que cada 
    uma das listas possui o nome de apenas um Estado com valores repetidos.
    """
    imprimir_titulo(in_mensagem='Programa nove')

    estados_das_filiais = ['SP', 'ES', 'MG', 'MG', 'SP', 'MG', 
                           'ES', 'ES', 'ES', 'SP', 'SP', 'MG', 
                           'ES', 'SP', 'RJ', 'MG', 'RJ', 'SP', 
                           'MG', 'SP', 'ES', 'SP', 'MG', 'PA'
                          ]


    

    print(f'estados_das_filiais: {type(estados_das_filiais)} - {estados_das_filiais}')

    estados_do_sudeste=['SP','MG','RJ','ES','PA', 'MA']
    quantidades_por_estado={}
    for estado_do_sufeste in range(len(estados_do_sudeste)):
        temp = [estados_do_sudeste[estado_do_sufeste] 
                    for estado_da_filial in range(len(estados_das_filiais)) 
                        if estados_das_filiais[estado_da_filial]==estados_do_sudeste[estado_do_sufeste]
               ]
        quantidades_por_estado[estados_do_sudeste[estado_do_sufeste]]=len(temp)

    print(f'quantidades_por_estado: {type(quantidades_por_estado)} - {quantidades_por_estado}')



# ==================================================
# oito()
# ==================================================
def oito()->None:
    """
    8. Um e-commerce possui as informações de id de venda, quantidade vendida e preço do produto 
    divididos nas seguintes listas:
        id = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        quantidade = [15, 12, 1, 15, 2, 11, 2, 12, 2, 4]
        preco = [93.0, 102.0, 18.0, 41.0, 122.0, 14.0, 71.0, 48.0, 14.0, 144.0]

    O e-commerce precisa estruturar esses dados em uma tabela contendo o valor total da venda, 
    que é obtida multiplicando a quantidade pelo preço unitário. Além disso, a tabela precisa 
    conter um cabeçalho indicando as colunas: 'id', 'quantidade', 'preco' e 'total'.

    Crie uma lista de tuplas em que cada tupla tenha id, quantidade, preço e valor total, 
    na qual a primeira tupla é o cabeçalho da tabela.
    """
    imprimir_titulo(in_mensagem='Programa oito')
    ids = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    quantidades = [15, 12, 1, 15, 2, 11, 2, 12, 2, 40]
    precos = [93.0, 102.0, 18.0, 41.0, 122.0, 14.0, 71.0, 48.0, 14.0, 144.0]
    vendas = [('id', 'quantidade', 'preco' ,'total')]
    vendas += [(ids[i], quantidades[i], precos[i], quantidades[i]*precos[i]) 
               for i in range(len(ids))
              ]
    print(f'vendas: {type(vendas)} - {vendas}')




# ==================================================
# sete()
# ==================================================
def sete()->None:
    """
    7. Uma clínica analisa dados de pacientes e armazena o valor numérico da glicose em um banco 
    de dados e gostaria de rotular os dados da seguinte maneira:

        -Glicose igual ou inferior a 70: 'Hipoglicemia'
        -Glicose entre 70 a 99: 'Normal'
        -Glicose entre 100 e 125: 'Alterada'
        -Glicose superior a 125: 'Diabetes'
    
    A clínica disponibilizou parte dos valores e sua tarefa é criar uma lista de tuplas usando
     list comprehension contendo o rótulo e o valor da glicemia em cada tupla.

    glicemia = [129, 82, 60, 97, 101, 65, 62, 167, 87, 53, 58, 92, 66, 120, 109, 62, 86, 96, 103, 88, 155, 52, 89, 73]
    """
    imprimir_titulo(in_mensagem='Programa sete')
    glicemia = [129, 82, 60, 97, 101, 65, 62, 167, 87, 53, 58, 92, 66, 120, 109, 62, 86, 96, 103, 88, 155, 52, 89, 73]
    print(f'glicemia: {type(glicemia)} - {glicemia}')

    rotulos = [('Hipoglicemia', glicose) if glicose <= 70 
          else ('Normal', glicose)       if glicose < 100 
          else ('Alterada', glicose)     if glicose < 125 
          else ('Diabetes', glicose) 
          for glicose in glicemia]
    print(f'rotulos: {type(rotulos)} - {rotulos}')

# ==================================================
# seis()
# ==================================================
def seis()->None:
    """
    6. Uma loja possui um banco de dados com a informação de venda de cada representante e de 
    cada ano e precisa filtrar somente os dados do ano 2022 com venda maior do que 6000. 
    A loja forneceu uma amostra contendo apenas as colunas com os anos e os valores de 
    venda para que você ajude a realizar a filtragem dos dados a partir de um código:
        vendas = [('2023', 4093), ('2021', 4320), ('2021', 5959), ('2022', 8883)
                 , ('2023', 9859), ('2022', 5141), ('2022', 7688), ('2022', 9544)
                 , ('2023', 4794), ('2021', 7178), ('2022', 3030), ('2021', 7471)
                 , ('2022', 4226), ('2022', 8190), ('2021', 9680), ('2022', 5616)]

    Crie uma lista usando list comprehension para filtrar os valores de 2022 e que sejam 
    maiores que 6000.
    """
    imprimir_titulo(in_mensagem='Programa seis')
    vendas = [ ('2023', 4093), ('2021', 4320), ('2021', 5959), ('2022', 8883)
             , ('2023', 9859), ('2022', 5141), ('2022', 7688), ('2022', 9544)
             , ('2023', 4794), ('2021', 7178), ('2022', 3030), ('2021', 7471)
             , ('2022', 4226), ('2022', 8190), ('2021', 9680), ('2022', 5616)]
    print(f'vendas: {type(vendas)} - {vendas}')

    vendas_2021 = [tupla[1] for tupla in vendas if tupla[0] == '2021']
    vendas_2022 = [tupla[1] for tupla in vendas if tupla[0] == '2022']
    vendas_2023 = [tupla[1] for tupla in vendas if tupla[0] == '2023']

    print(f'vendas_2021: {type(vendas_2021)} - {vendas_2021}')
    print(f'vendas_2022: {type(vendas_2022)} - {vendas_2022}')
    print(f'vendas_2023: {type(vendas_2023)} - {vendas_2023}')

    vendas_interesantes = [tupla[1] if tupla[0] == '2022' and tupla[1] > 6000 
                                    else '999999'
                           for tupla in vendas
                          ]
    print(f'vendas_interesantes: {type(vendas_interesantes)} - {vendas_interesantes}')

# ==================================================
# cinco()
# ==================================================
def cinco()->None:
    """
    5. Crie um dicionário usando o dict comprehension em que as chaves estão na lista
      meses = ['Jan', 'Fev', 'Mar', 'Abr', 'Mai', 'Jun', 'Jul', 'Ago', 'Set', 'Out', 'Nov', 'Dez'] 
      e os valores estão em 
      despesa = [860, 490, 1010, 780, 900, 630, 590, 770, 620, 560, 840, 360].    
      """
    imprimir_titulo(in_mensagem='Programa cinco')
    meses = ['Jan', 'Fev', 'Mar', 'Abr', 'Mai', 'Jun', 'Jul', 'Ago', 'Set', 'Out', 'Nov', 'Dez'] 
    despesa = [860, 490, 1010, 780, 900, 630, 590, 770, 620, 560, 840, 360]
    print(f'meses: {type(meses)} - {meses}')
    print(f'despesa: {type(despesa)} - {despesa}')

    dicio=dict(zip(meses,despesa))
    print(f'dicio: {type(dicio)} - {dicio}')


# ==================================================
# quatro()
# ==================================================
def quatro()->None:
    """
    4. Crie uma lista usando o list comprehension que armazena somente o valor numérico de cada 
    tupla caso o primeiro elemento seja 'Apartamento', a partir da seguinte lista de tuplas:
        aluguel = [('Apartamento', 1700), 
                   ('Apartamento', 1400), 
                   ('Casa', 2150), 
                   ('Apartamento', 1900), 
                   ('Casa', 1100)
                   ]

    """
    imprimir_titulo(in_mensagem='Programa quatro')

    aluguel = [('Apartamento', 1700), 
                ('Apartamento', 1400), 
                ('Casa', 2150), 
                ('Apartamento', 1900), 
                ('Casa', 1100)
                ]

    print(f'aluguel: {type(aluguel)} - {aluguel}')

    quatro=[aluguel[i][1] for i in range(len(aluguel)) if aluguel[i][0]=='Apartamento']

    print(f'quatro: {type(quatro)} - {quatro}')

    lista = [tupla[1] for tupla in aluguel if tupla[0]== 'Apartamento']
    print(f'lista: {type(lista)} - {lista}')



# ==================================================
# tres()
# ==================================================
def tres()->None:
    """
    3. A partir da lista: lista = ['Pedro', 'Júlia', 'Otávio', 'Eduardo'], crie um código para gerar 
    uma lista de tuplas em que cada tupla tenha o primeiro elemento como a posição do nome 
    na lista original e o segundo elemento sendo o próprio nome.
    """
    imprimir_titulo(in_mensagem='Programa tres')

    #-------------------
    # Montagem
    #-------------------
    QDT_NOMES : Final[int] = 10
    lista=[]
    for i in range(QDT_NOMES):
        lista.append(gerar_nome_completo())

    print(f'lista {lista}')
    #-------------------
    lista_de_tupla=[]
    for item in lista:
        print(item)
        lista_de_tupla.append( (lista.index(item),item) )

    print(f'lista_de_tupla: {lista_de_tupla}')

# ==================================================
# dois()
# ==================================================
def dois()->None:
    """
    2. Crie um código para gerar uma lista que armazena o terceiro elemento de cada tupla contida na seguinte lista de tuplas:
        lista_de_tuplas = [('Pedro', 1.74, 81), ('Júlia', 1.65, 67), ('Otávio', 1.81, 83)]
    """
    imprimir_titulo(in_mensagem='Programa dois')

    #-------------------
    # Montagem
    #-------------------
    QDT_TUPLAS : Final[int] = 100
    lista_de_tuplas=[]
    for i in range(QDT_TUPLAS):
        lista_de_tuplas.append(
            ( gerar_nome(),
              gerar_um_decimal(in_start=1.50, in_end=2.20),
              gerar_um_inteiro(in_start=40, in_end=120)
            )

        )
    print(f'lista_de_tuplas {lista_de_tuplas}')
    #-------------------
    pesos=[]
    for nome, altura, peso in lista_de_tuplas:
        print(nome, altura, peso, calcular_imc(in_altura=altura,in_peso=peso) )
        pesos.append(peso)

    print(f'pesos {pesos}')
# ==================================================
# um()
# ==================================================
def um()->None:
    """
    1. Crie um código para imprimir a soma dos elementos de cada uma das listas contidas na 
    seguinte lista:
        lista_de_listas = [[4,6,5,9], [1,0,7,2], [3,4,1,8]]
    """
    imprimir_titulo(in_mensagem='Programa Um')

    lista_de_listas = [[4,6,5,9], [1,0,7,2], [3,4,1,8]]

    LINHAS : Final[int] = 5
    COLUNAS : Final[int] = 5

    lista_de_listas=[]
    for lin in range(LINHAS):
        lista_de_listas.append(list(gerar_tupla_com_inteiros(in_start=0,in_end=10,in_quantidade=COLUNAS)))

    print(f'lista_de_listas {lista_de_listas}')

    for lista in lista_de_listas:
        print(sum(lista))


# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    menu={
          1:'Atributos Lista'
         ,2:'Acesando lista de tupla'
         ,3:'Acesando lista de tupla'
         ,4:'list comprehension'
         ,5:'Class zip'
         ,6:'Vendas'
         ,7:'Teste Glicemia'
         ,8:'Vendas'
         ,9:'Filiais'
         ,10:'Filiais'
         }

    imprimir_titulo('MENU PRINCIPAL')

    for chave,valor in menu.items():
        print(f'{chave} - {valor}')
    print("0 - Sair")
    print()

# ==================================================
# main
# ==================================================
def main()-> None:
    while True:
        exibir_menu()
        opcao=obter_inteiro_nao_negativo("Escolha uma opção (0 para encerrar)")

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
#        elif opcao==11:
#            onze()
#        elif opcao==12:
#            doze()
#        elif opcao==13:
#            treze()
#        elif opcao==14:
#            quatorze()
#        elif opcao==15:
#            quinze()
        else:
            print('Opção Inválida')

        print()

if __name__ == "__main__":
    main()        

