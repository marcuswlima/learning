"""
Instituição: Alura
Carreira: Engenheiro de Dados
Curso: "Python para Dados: trabalhando com funções, estruturas de dados e exceções"
Capítulo: 02-funções

Autor: Marcus William dos Santos Lima
Data: 12/10/2026
"""

# ==================================================
# Bibliotecas/Importações
# ==================================================
from typing import Final

from random import randrange,choice

from utilitarios import imprimir_titulo ,\
                        gerar_tupla_com_inteiros,\
                        gerar_tupla_com_decimais ,\
                        obter_inteiro_positivo, \
                        gerar_nome ,\
                        obter_inteiro_nao_negativo    

# ==================================================
# dez()
# ==================================================
def dez()->None:
    """
    10. Você iniciou um estágio em uma empresa que trabalha com processamento de linguagem natural (NLP). Sua líder requisitou 
    que você criasse um trecho de código que recebe uma frase digitada pela pessoa usuária e filtre apenas as palavras com tamanho 
    maior ou igual a 5, exibindo-as em uma lista. Essa demanda é voltada para a análise do padrão de comportamento de pessoas na 
    escrita de palavras acima dessa quantidade de caracteres.

    Dica: utilize as funções lambda e filter() para filtrar essas palavras. Lembrando que a função embutida filter() recebe uma 
    função (no nosso exemplo uma função lambda) e filtra um iterável de acordo com a função. Para tratar a frase use replace() para 
    trocar a ',' '.', '!' e '?' por espaço.

    Use a frase "Aprender Python aqui na Alura é muito bom" para testar o código.
    """
    imprimir_titulo(in_mensagem='Programa dez')

    frase = '10. Você iniciou um estágio em uma empresa que trabalha com processamento de linguagem natural (NLP). Sua líder requisitou'
    frase = frase.replace(',',' ').replace('.',' ').replace('!',' ').replace('?',' ').split()
    print('frase',frase)
    frase_filtrada = list(filter(lambda x: len(x) >= 5, frase))
    print('frase_filtrada',frase_filtrada)




# ==================================================
# nove()
# ==================================================

g_cidades   =('Salvador', 'Fortaleza','Natal' ,'Aracaju')
g_gastos    =(200       , 400        , 250    , 300     )
g_distancias=(850       , 800        , 300    , 550     )

def calcular_custos_hotel(in_cidade:str, in_qdt_dias:int)->float:
    return 150 * in_qdt_dias 

def calcular_custos_gasolina(in_cidade:str, in_qdt_dias:int)->float:
    CONSUMO_POR_LITRO : Final[int] = 14
    VALOR_GASOLINA    : Final[int] = 5
    
    indice=0
    for i in range(len(g_cidades)):
        if in_cidade == g_cidades[i]:
            indice = i

    distancia = g_distancias[indice]

    return round(distancia/CONSUMO_POR_LITRO*VALOR_GASOLINA,2)

def calcular_custos_passeio(in_cidade:str, in_qdt_dias:int)->float:
    indice=0
    for i in range(len(g_cidades)):
        if in_cidade == g_cidades[i]:
            indice = i

    return g_gastos[indice]

def calcular_custos(in_cidade:str, in_qdt_dias:int)->None:

    hotel = calcular_custos_hotel(in_cidade,in_qdt_dias)
    gasolina = calcular_custos_gasolina(in_cidade,in_qdt_dias)
    passeio = calcular_custos_passeio(in_cidade,in_qdt_dias)
    total = hotel + gasolina + passeio

    print(f'Hotel   : R${hotel}')
    print(f'Gasolina: R${gasolina}')
    print(f'Passeio : R${passeio}')
    print(f'---------------------')
    print(f'Total   : R${total}')
    print(f'Com base nos gastos definidos, uma viagem de {in_qdt_dias} dias para {in_cidade} saindo de Recife custaria R${total} reais')

def nove()->None:
    """
    9) Você recebeu o desafio de criar um código que calcula os gastos de uma viagem para um das quatro cidades partindo de 
    Recife, sendo elas: Salvador, Fortaleza, Natal e Aracaju.
    
    O custo da diária do hotel é de 150 reais em todas elas e o consumo de gasolina na viagem de carro é de 14 km/l, 
    sendo que o valor da gasolina é de 5 reais o litro. O gastos com passeios e alimentação a se fazer em cada uma delas 
    por dia seria de [200, 400, 250, 300], respectivamente.
    
    Sabendo que as distâncias entre Recife e cada uma das cidades é de aproximadamente [850, 800, 300, 550] km, crie três 
    funções nas quais: a 1ª função calcule os gastos com hotel (gasto_hotel), a 2ª calcule os gastos com a gasolina (gasto_gasolina) 
    e a 3ª os gastos com passeio e alimentação (gasto_passeio).
    
    Para testar, simule uma viagem de 3 dias para Salvador partindo de Recife. Considere a viagem de ida e volta de carro.
        "Com base nos gastos definidos, uma viagem de [dias] dias para [cidade] saindo de Recife custaria [gastos] reais"
    """
    imprimir_titulo(in_mensagem='Programa nove')
    ITERACOES : Final[int] = 5
    
    for i in range(ITERACOES):
        cidade = choice(g_cidades)
        dias = randrange(1,6)
        print(cidade, dias, 'dias')
        calcular_custos(cidade,dias)
        print()

# ==================================================
# oito()
# ==================================================

def calcular_pontos(in_gols_marcados:tuple, in_gols_sofridos:tuple):
    pontos_acumulados=0
    for i in range(len(in_gols_marcados)):
        if in_gols_marcados[i] > in_gols_sofridos[i]:
            pontos_no_jogo = 3
        elif in_gols_marcados[i] == in_gols_sofridos[i]:
            pontos_no_jogo = 1
        else:
            pontos_no_jogo = 0

        pontos_acumulados += pontos_no_jogo

        print(f'{i+1} Rodada {in_gols_marcados[i]} x {in_gols_sofridos[i]} - {pontos_no_jogo}')

    aproveitamento = round((pontos_acumulados*100)/(len(in_gols_marcados)*3),2)

    print(f'A pontuação do time foi de {pontos_acumulados} e seu aproveitamento foi de {aproveitamento}%')


def oito()->None:
    """
    8. Como cientista de dados em um time de futebol, você precisa implementar novas formas de 
    coleta de dados sobre o desempenho de jogadores e do time como um todo. Sua primeira ação 
    é criar uma forma de calcular a pontuação do time no campeonato nacional a partir dos dados 
    de gols marcados e sofridos em cada jogo.
    Escreva uma função chamada calcula_pontos que recebe como parâmetros duas listas de números 
    inteiros, representando os gols marcados e sofridos pelo time em cada partida do campeonato. 
    A função deve retornar a pontuação do time e o aproveitamento em percentual, levando em 
    consideração que a vitória vale 3 pontos, o empate vale 1 ponto e a derrota 0 pontos.

    Observação: se a quantidade de gols marcados numa partida for maior que a de sofridos, 
    o time venceu. Caso seja igual, o time empatou e se for menor, o time perdeu. Para calcular 
    o aproveitamento devemos fazer a razão entre a pontuação do time pela pontuação máxima que 
    ele poderia receber.

    Para teste, utilize as seguintes listas de gols marcados e sofridos:
        gols_marcados = [2, 1, 3, 1, 0]
        gols_sofridos = [1, 2, 2, 1, 3]

    Provável texto exibido:
        "A pontuação do time foi de [pontos] e seu aproveitamento foi de [aprov]%"
    """
    imprimir_titulo(in_mensagem='Programa Oito')
    campeonato=[]
    QTD_TIMES : Final[int] = 5
    QTD_RODADAS : Final[int] = 4
    for i in range(QTD_TIMES):
        time=gerar_nome()
        gols_marcados = gerar_tupla_com_inteiros(0,5,QTD_RODADAS)
        gols_sofridos = gerar_tupla_com_inteiros(0,5,QTD_RODADAS)
        campeonato.append([time,gols_marcados,gols_sofridos])

    print(campeonato)

    for item in campeonato:
        print(item[0])
        calcular_pontos(item[1],item[2])


# ==================================================
# sete()
# ==================================================
def sete()->None:
    """
    7. Você recebeu uma demanda para tratar 2 listas com os nomes e sobrenomes de cada 
    estudante concatenando-as para apresentar seus nomes completos na forma Nome Sobrenome. 
    As listas são:
        nomes = ["joão", "MaRia", "JOSÉ"]
        sobrenomes = ["SILVA", "souza", "Tavares"]
    """
    imprimir_titulo(in_mensagem='Programa Sete')
    nomes = ["joão", "MaRia", "JOSÉ"]
    sobrenomes = ["SILVA", "souza", "Tavares"]
    
    # Função lambda que recebe duas listas e itera em cada uma concatenando seu 
    # nome e sobrenome na forma desejada e cria um objeto do tipo 'map'
    nome_completo = map(lambda x, y: f'{x.title()} {y.title()}', nomes, sobrenomes)

    # Leitura do objeto mapa(iterável)
    for n in nome_completo:
        print(f'Nome completo: {n}')

    print(nomes)
    print(sobrenomes)
    print(type(nome_completo))

# ==================================================
# seis()
# ==================================================
def avaliar_notas(in_notas:list)->None:
    """
        Imprimir avaliação de aluno na tela
    """
    dados={}
    dados['maior']=max(in_notas)
    dados['menor']=min(in_notas)
    dados['media']=round(sum(in_notas)/len(in_notas),2)
    if dados['media'] >= 7:
        dados['situacao']='Aprovado'
    else:
        dados['situacao']='Reprovado'

    print(f'O(a) estudante obteve uma média de {dados['media']}, com a sua maior nota de {dados['maior']} pontos e a menor nota de {dados['menor']} pontos e foi {dados['situacao']}')

def seis()->None:
    """
    6. Para atender a uma demanda de uma instituição de ensino para a análise do desempenho 
    de seus(suas) estudantes, você precisa criar uma função que receba uma lista de 4 notas e 
    retorne:
        - maior nota
        - menor nota
        - média
        - situação (Aprovado(a) ou Reprovado(a))
    Para testar o comportamento da função, os dados podem ser exibidos em um texto:
        "O(a) estudante obteve uma média de [media], com a sua maior nota de [maior] pontos e 
        a menor nota de [menor] pontos e foi [situacao]"
    """
    imprimir_titulo(in_mensagem='Programa seis')
    competicao={}
    QTD_ALUNOS : Final[int] = 10
    QTD_NOTAS : Final[int] = 4

    notas_dos_alunos={}
    for i in range(QTD_ALUNOS):
        nome_aluno = gerar_nome()
        notas=list(gerar_tupla_com_decimais(0,10,QTD_NOTAS))
        notas_dos_alunos[nome_aluno]=notas

    print(f'notas_dos_alunos: {notas_dos_alunos}')

    for aluno in notas_dos_alunos.items():
        print(aluno[0],end=' ')
        avaliar_notas(aluno[1])


# ==================================================
# cinco()
# ==================================================

def processar_concurso(in_concurso:dict)->None:

    medias=[]
    for notas in in_concurso.values():
        medias.append(sum(notas)/len(notas))


    print(f'Medias: {medias}')
    maior_nota_media = max(medias)
    print(f'A maior média é {maior_nota_media}')

    indice_vencedor=0
    for i in range(len(medias)):
        if medias[i]==maior_nota_media:
            indice_vencedor=i
    print(f'O indice vencedor foi {indice_vencedor}')

    nomes=list(in_concurso.keys())
    print(f'O vencedire foi {nomes[indice_vencedor]}')

def cinco()->None:
    """
    5. Você foi contratado(a) como cientista de dados de uma associação de skate. ,
    Para analisar as notas recebidas de skatistas em algumas competições ao longo do ano, 
    você precisa criar um código que calcula a pontuação dos(as) atletas. Para isso, 
    o seu código deve receber 5 notas digitadas pelas pessoas juradas. Para calcular a pontuação 
    de um(a) skatista, você precisa eliminar a maior e a menor pontuação dentre as 5 notas e 
    tirar a média das 3 notas que sobraram. Retorne a média para apresentar o texto:
        "Nota da manobra: [media]"
    """
    imprimir_titulo(in_mensagem='Programa cinco')

    competicao={}
    CONCORRENTES : Final[int] = 10
    NOTAS : Final[int] = 5

    for i in range(CONCORRENTES):
        concorrente = gerar_nome()
        notas=list(gerar_tupla_com_decimais(9,10,NOTAS))
        notas.remove(max(notas))
        notas.remove(min(notas))
        competicao[concorrente]=notas


    print(f'Competicao: {competicao}')
    processar_concurso(competicao)
  


# ==================================================
# quatro()
# ==================================================
def quatro()->None:
    """
    4. Crie uma lista dos quadrados dos números da seguinte lista 
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]. Lembre-se de utilizar as funções lambda e 
    map() para calcular o quadrado de cada elemento da lista.
    """
    imprimir_titulo(in_mensagem='Programa quantro')
    numeros=gerar_tupla_com_inteiros(1,100,30)
    quadrados = list(
        map(lambda n: pow(n,2), numeros)
    )

    print(numeros)
    print(quadrados)


    numeros=gerar_tupla_com_decimais(1,100,30)
    print(numeros)
    

# ==================================================
# tres()
# ==================================================
def tres()->None:
    """
    3. Crie a função que leia a lista abaixo e retorne uma nova lista com os múltiplos de 3:
        [97, 80, 94, 88, 80, 1, 16, 53, 62, 32, 24, 99]

    Utilize o return na função e salve a nova lista na variável mult_3.
    """
    imprimir_titulo(in_mensagem='Programa três')

    # Lista Original-------------------------------
    lista = (97, 80, 94, 88, 80, 1, 16, 53, 62, 32, 24, 99, 3, 15)

    # Usando sub-funcao-------------------------------
    def filtrar_multiplos_de_3(in_tupla:tuple)->list:
        resp=[]
        for numero in in_tupla:
            if numero % 3 == 0 :
                resp.append(numero)

        return resp

    multiplos_3 = filtrar_multiplos_de_3(lista)

    print(lista)
    print(multiplos_3)

    # Usando filter+funcao lambda-------------------------------
    multiplos_3 = list(
        filter(lambda n: n % 3 == 0, lista)
    )
    print(lista)
    print(multiplos_3)

# ==================================================
# dois()
# ==================================================
def imprimir_tabuada(numero:int)->None:
    """
    Imprime a tabuada do numero gerado na tela

    Args:
        numero:
            Número para gerar a tabuada

    Returns:
        Nones
    """
    print(f"Tabuada de {numero}:")

    for i in range(11):
        if i==0:
            continue
        print(f'{numero} x {i} = {numero*i}')


def dois()->None:
    """
    2. Escreva uma função que gere a tabuada de um número inteiro de 1 a 10, 
    de acordo com a escolha da pessoa usuária. 
    Como exemplo, para o número 7, a tabuada deve 
    ser mostrada no seguinte formato:


    Copiar
    Tabuada do 7:
    7 x 0 = 0
    7 x 1 = 7
    [...]
    7 x 10 = 70    
    """
    imprimir_titulo(in_mensagem='Programa Dois')
    numero = obter_inteiro_positivo('Informe um número')
    imprimir_tabuada(numero)


# ==================================================
# um()
# ==================================================
def um()->None:
    """
    1. Escreva um código que lê a lista abaixo e faça:
        lista = [16, 14, 63, 65, 17, 99, 70, 11, 20, 48, 79, 32, 17, 89, 12, 25, 66]

        A leitura do tamanho da lista
        A leitura do maior e menor valor
        A soma dos valores da lista
        
        Ao final exiba uma mensagem dizendo:
        "A lista possui [tam] números em que o maior número é [maior] e o menor número é [menor
    """
    imprimir_titulo(in_mensagem='Programa um')
    lista = [16, 14, 63, 65, 17, 99, 70, 11, 20, 48, 79, 32, 17, 89, 12, 25, 66, 3453, -3]

    print(f'A lista possiu {len(lista)} números em que \
o maior número é {max(lista)}, \
o menor é {min(lista)} e \
a soma de todos é {sum(lista)}  '
          )


# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    menu={
         1:'Atributos Lista'
        ,2:'Imprimir Tabuada'
        ,3:'Separar multiplos de 3'
        ,4:'Quadrados de vários números'
        ,5:'Concurso de Skate'
        ,6:'Avaliacao do aluno'
        ,7:'Ajustando Nomes'
        ,8:'Campeonato de Futebol'
        ,9:'Orçamento Viagem'
        ,10:'Linguagem Natutal'
         }

    imprimir_titulo('MENU PRINCIPAL')

    for tupla in menu.items():
        print(f'{tupla[0]} - {tupla[1]}')
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

