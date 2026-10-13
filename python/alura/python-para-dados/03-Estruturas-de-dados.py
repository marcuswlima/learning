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
#       elif opcao==4:
#           quatro()
#       elif opcao==5:
#           cinco()
#       elif opcao==6:
#           seis()
#       elif opcao==7:
#           sete()
#       elif opcao==8:
#           oito()
#       elif opcao==9:
#           nove()
#       elif opcao==10:
#           dez()
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

