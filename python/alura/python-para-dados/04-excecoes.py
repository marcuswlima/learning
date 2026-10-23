"""
Instituição: Alura
Carreira: Engenheiro de Dados
Curso: "Python para Dados: trabalhando com funções, estruturas de dados e exceções"
Capítulo: 04-Lidando com exceções

Autor: Marcus William dos Santos Lima
Data: 12/10/2026
"""


# ==================================================
# Bibliotecas/Importações
# ==================================================
from typing import Final

from utilitarios import imprimir_titulo,             \
                        obter_inteiro_nao_negativo,  \
                        obter_racional_nao_netativo, \
                        gerar_tupla_com_inteiros,    \
                        gerar_nome_completo

# ==================================================
# sete()
# ==================================================

def divisao_colunas(in_lista1:list, in_lista2:list)->list:

    if len(in_lista1)!= len(in_lista2):
        raise ValueError("As listas precisam ter o mesmo tamanho")

    resp = [ round(a/b,2) for a, b in zip(in_lista1, in_lista2)]

    return resp

def sete()->None:
    """
    Condição dos teste laboratoriais
    """
    imprimir_titulo(in_mensagem='Programa sete - Condição dos teste laboratoriais')

    pressoes     = [100, 120, 140, 160, 180]
    temperaturas = [20,  25,  30,  35,  40]

    try:
        resposta=divisao_colunas(in_lista1=pressoes, in_lista2=temperaturas)
    except Exception as e:
        print(e)
    else:
        print(resposta)


    pressoes     = [60, 120, 140, 160, 180]
    temperaturas = [0,  25,  30,  35,  40]

    try:
        resposta=divisao_colunas(in_lista1=pressoes, in_lista2=temperaturas)
    except Exception as e:
        print(e)
    else:
        print(resposta)

    pressoes     = [100, 120, 140, 160]
    temperaturas = [20,  25,  30,  35, 40]

    try:
        resposta=divisao_colunas(in_lista1=pressoes, in_lista2=temperaturas)
    except Exception as e:
        print(e)
    else:
        print(resposta)
# ==================================================
# seis()
# ==================================================
def tratar_texto(in_texto:list)->None:
    #print(in_texto)
    for palavra in in_texto:
        #print(palavra)
        if (',' in palavra) or ('.' in palavra) or ('!' in palavra) or ('?' in palavra):
            raise ValueError(f'O texto apresenta pontuações na palavra "{palavra}".')

    return "Texto Tratado"

def seis()->None:
    """
    Tratamento de palavras
    """
    imprimir_titulo(in_mensagem='Programa seis - Tratamento de palavras')

    lista_tratada = ['Python', 'é', 'uma', 'linguagem', 'de', 'programação', 'poderosa', 'versátil',
                  'e', 'fácil', 'de', 'aprender', 'utilizada', 'em', 'diversos', 'campos', 'desde',
                  'análise', 'de', 'dados', 'até', 'inteligência', 'artificial']

    lista_nao_tratada = ['Python', 'é', 'uma', 'linguagem', 'de', 'programação', 'poderosa,', 'versátil',
                    'e', 'fácil,', 'de', 'aprender', 'utilizada', 'em', 'diversos', 'campos,', 'desde',
                    'análise', 'de', 'dados', 'até', 'inteligência', 'artificial!']

    try:
        avaliacao = tratar_texto(lista_tratada)
    except Exception as e:
        print(e)
    else:
        print(avaliacao)

    try:
        avaliacao = tratar_texto(lista_nao_tratada)
    except Exception as e:
        print(e)
    else:
        print(avaliacao)


# ==================================================
# cinco()
# ==================================================

gabarito = ['D', 'A', 'B', 'C', 'A', 'D', 'C', 'A', 'D', 'A']
quantidade_perguntas = len(gabarito)

def avaliar_provas(in_provas:dict)->dict:
    resp={}
    for aluno,notas in in_provas.items():
        anuladas=0
        certas=0
        erradas=0
        for i in range(quantidade_perguntas):
            if notas[i] not in gabarito:
                anuladas += 1
            else:
                if notas[i]==gabarito[i]:
                    certas += 1
                else:
                    erradas += 1
        resp[aluno]=(certas,erradas,anuladas)

    return resp


def passar_a_prova(in_quantidade:int, in_qtd_perguntas:int)->dict:
    resp={}
    for i in range(in_quantidade):
        nome = gerar_nome_completo()

        numeros=gerar_tupla_com_inteiros(65,69,in_qtd_perguntas)
        respostas=[ chr(numero) for numero in numeros]

        resp[nome]=respostas

    return resp

def cinco()->None:
    """
    4. Crie uma função que recebe duas listas como parâmetros e agrupe os elementos 
    um a um das listas, formando uma lista de tuplas de 3 elementos, no 
    qual o primeiro e segundo elemento da tupla são os valores na posição i das listas e o 
    terceiro elemento é a soma dos valores na posição i das listas.
    """
    imprimir_titulo(in_mensagem='Programa cinco')
    QDT_ALUNOS : Final[int] = 10

    print(f'gabarito: {gabarito}')
    provas = passar_a_prova(QDT_ALUNOS,quantidade_perguntas)
    print(f'provas: {provas}')
    avaliacoes = avaliar_provas(provas)
    print(f'avaliacoes: {avaliacoes}')

# ==================================================
# quatro()
# ==================================================
def lista_com_inteiros(in_lista:list)->bool:
    resp=False
    try:
        temp=[int(x) for x in in_lista]
    except Exception as e:
        resp=False
    else:
        resp=True
    
    return resp


def somar_listas(in_lista1:list, in_lista2:list)->list:
    if len(in_lista1)!=len(in_lista2):
        raise IndexError('A quantidade de elementos em cada lista é diferente.')

    if not lista_com_inteiros(in_lista1):
        raise TypeError('Primeira Lista inválida')

    if not lista_com_inteiros(in_lista2):
        raise TypeError('Segunda Lista inválida')

    resp = [(in_lista1[i],in_lista2[i],in_lista1[i]+in_lista2[i]) for i in range(len(in_lista1))]
    return resp


def quatro()->None:
    """
    4. Crie uma função que recebe duas listas como parâmetros e agrupe os elementos 
    um a um das listas, formando uma lista de tuplas de 3 elementos, no 
    qual o primeiro e segundo elemento da tupla são os valores na posição i das listas e o 
    terceiro elemento é a soma dos valores na posição i das listas.
    """
    imprimir_titulo(in_mensagem='Programa quatro')
    lista1 = [4,6,1,9,10]
    lista2 = [-4,6,1,7,9]    
    print(lista1,lista2)
    try:
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,6,1,9,10,3]
    lista2 = [-4,6,1,7,9]    
    print(lista1,lista2)
    try:
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,'a',1,9,10]
    lista2 = [-4,6,1,7,9]    
    print(lista1,lista2)
    try:
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,1,1,9,10]
    lista2 = [-4,6,'13r1',7,9]    
    print(lista1,lista2)
    try:
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)


# ==================================================
# tres()
# ==================================================
def converter_lista(in_lista:list)->list:
    try:
        resp=[float(x) for x in in_lista]
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        return resp
    finally:
        print('execução concluida')




def tres()->None:
    """
    3. Crie uma função que recebe uma lista como parâmetro e converta todos os valores da 
    lista para float. A função deve conter um tratamento de erro indicando o tipo de erro 
    gerado e retornar a lista caso não tenha ocorrido nenhum erro. Por fim, deve ter a 
    cláusula finally para imprimir o texto: 'Fim da execução da função'.
    """
    imprimir_titulo(in_mensagem='Programa tres')
    lista=[1,2,3]
    novalista=converter_lista(in_lista=lista)
    print(novalista)

    lista=[1,'w',3]
    novalista=converter_lista(in_lista=lista)
    print(novalista)

# ==================================================
# dois()
# ==================================================
def dois()->None:
    """
    2. Faça um programa que solicite à pessoa usuária digitar um texto que será uma chave a 
    ser pesquisada no seguinte dicionário: 
        idades = {'Júlia': 16, 'Carol': 23, 'Alberto': 19, 'Roberta': 17}, 
    armazenando o resultado do valor em uma variável. O código deve conter um 
    tratamento de erro KeyError, imprimindo a informação 'Nome não encontrado', caso 
    ocorra o erro; e imprimir o valor caso não ocorra nenhum.

    Teste o programa com um nome presente em uma das chaves do dicionário e 
    com um que não esteja no dicionário para verificar a mensagem de erro.
    """
    imprimir_titulo(in_mensagem='Programa dois')
    idades = {'Júlia': 16, 'Carol': 23, 'Alberto': 19, 'Roberta': 17, 'Marcus': 50}
    print(f'idades: {idades}')
    digitado = input('informe o nome: ')
    try:
        idade = idades[digitado]
    except KeyError:
        print('Nome não encontrado')
    else:
        print(f'A idade de {digitado} é {idade}')


# ==================================================
# um()
# ==================================================
def um()->None:
    """
    1. Faça um programa que solicite à pessoa usuária digitar dois números float e calcular 
    a divisão entre esses números. O código deve conter um tratamento de erro, indicando
    o tipo de erro que foi gerado caso a divisão não seja possível de realizar.

    Teste o programa com o segundo valor numérico do input igual a 0. Também teste 
    utilizando caracteres textuais no input para checar os tipos de erro que ocorrem.
    """
    imprimir_titulo(in_mensagem='Programa um')
    numerador = obter_racional_nao_netativo(in_mensagem='numerador')
    denominador = obter_racional_nao_netativo(in_mensagem='denominador')
    try:
        divisao = numerador / denominador
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(f'divisao {divisao}')

# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    menu={
          1:'Divisão'
         ,2:'Idades'
         ,3:'Converter lista para float'
         ,4:'Somar listas'
         ,5:'Correções'
         ,6:'Tratamento de palavras'
         ,7:'Condição dos teste laboratoriais'
         }

    imprimir_titulo('MENU PRINCIPAL')

    for chave,valor in menu.items():
        print(f'{chave}) {valor}')
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

