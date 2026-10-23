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
from utilitarios import imprimir_titulo,obter_inteiro_nao_negativo,obter_racional_nao_netativo


# ==================================================
# cinco()
# ==================================================
def cinco()->None:
    """
    4. Crie uma função que recebe duas listas como parâmetros e agrupe os elementos 
    um a um das listas, formando uma lista de tuplas de 3 elementos, no 
    qual o primeiro e segundo elemento da tupla são os valores na posição i das listas e o 
    terceiro elemento é a soma dos valores na posição i das listas.
    """
    imprimir_titulo(in_mensagem='Programa cinco')


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
    try:
        print(lista1,lista2)
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,6,1,9,10,3]
    lista2 = [-4,6,1,7,9]    
    try:
        print(lista1,lista2)
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,'a',1,9,10]
    lista2 = [-4,6,1,7,9]    
    try:
        print(lista1,lista2)
        resultado = somar_listas(in_lista1=lista1, in_lista2=lista2)
    except Exception as e:
        print(type(e), f'Erro: {e}')
    else:
        print(resultado)

    lista1 = [4,1,1,9,10]
    lista2 = [-4,6,'13r1',7,9]    
    try:
        print(lista1,lista2)
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
    digitado = input('informe o nome: ')
    try:
        idade = idades[digitado]
        print(idade)
    except KeyError:
        print('Nome não encontrado')


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
    try:
        numerador = obter_racional_nao_netativo(in_mensagem='numerador')
        denominador = obter_racional_nao_netativo(in_mensagem='denominador')
        divisao = numerador / denominador
        print(f'divisao {divisao}')
    except Exception as e:
        print(type(e), f'Erro: {e}')

# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    menu={
          1:'Divisão'
         ,2:'Idades'
         ,3:'Converter lista para float'
         ,4:'Somar listas'
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

