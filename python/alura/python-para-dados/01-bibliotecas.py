from math import sqrt, pi
from random import choice, randrange
from utilitarios import titulo, obter_int_positivo, obter_float_positivo
from typing import Final
import numpy as utl


# ==================================================
# dez()
# ==================================================
def dez()->None:
    """
    10. Faça um programa para uma loja que vende grama para jardins. Essa loja trabalha com 
    jardins circulares e o preço do metro quadrado da grama é de R$ 25,00. Peça à pessoa usuária o 
    raio da área circular e devolva o valor em reais do quanto precisará pagar. 
        Dica: use a variável pi e o método pow() da biblioteca math. O cálculo da área de um 
        círculo é de: A = π*r^2 (lê-se pi vezes raio ao quadrado).
    """
    titulo('Execício Dez')
    VALOR_M2 : Final[int] = 25
    
    raio = obter_float_positivo('Informe o raio do jardin')
    area_circulo = pi * pow(raio,2)
    valor_pargamento = area_circulo * VALOR_M2

    print(f'Area do círculo: {area_circulo}')
    print(f'Valor pagaento : R${valor_pargamento}')


# ==================================================
# nove()
# ==================================================
def nove()->None:
    """
    9. Você recebeu um desafio de calcular a raiz quadrada de uma lista de números, identificando quais 
    resultaram em um número inteiro. A lista é a seguinte:
        numeros = [2, 8, 15, 23, 91, 112, 256]

    No final, informe quais números possuem raízes inteiras e seus respectivos valores.
    """
    titulo('Programa Nove')

    numeros = (2, 8, 15, 23, 91, 112, 256, 500, 25, 4, 5, 16)
    raises = []
    numeros_com_raiz_inteira = []

    for numero in numeros:
        raises.append(sqrt(numero))

    for i in range(len(raises)):
        if raises[i]//1 == raises[i] :
            numeros_com_raiz_inteira.append(numeros[i])

    print(numeros)
    print(raises)
    print(numeros_com_raiz_inteira)



# ==================================================
# oito()
# ==================================================
def oito()->None:
    """
    8. Para diversificar e atrair novos(as) clientes, uma lanchonete criou um item misterioso em seu 
    cardápio chamado "salada de frutas surpresa". Neste item, são escolhidas aleatoriamente 3 frutas de 
    uma lista de 12 para compor a salada de frutas da pessoa cliente. Crie o código que faça essa 
    seleção aleatória de acordo com a lista abaixo:
        frutas = ["maçã", "banana", "uva", "pêra", 
                 "manga", "coco", "melancia", "mamão",
                 "laranja", "abacaxi", "kiwi", "ameixa"]
    """
    titulo('Programa Oito')
    frutas = ["maçã", "banana", "uva", "pêra", "pupunha", "limão", "cupuaçú",
              "manga", "coco", "melancia", "mamão", 
              "laranja", "abacaxi", "kiwi", "ameixa", "açaí", "tabereba"]
    qdt_frutas=len(frutas)
    sorteadas=[]

    for i in range(3):
        sorteada=choice(frutas)
        sorteadas.append(sorteada)
        frutas.remove(sorteada)

    print(f'Opções de fruta: {qdt_frutas}')
    print(sorteadas)

# ==================================================
# sete()
# ==================================================
def sete()->None:
    """
    7. Você recebeu uma demanda para gerar números de token para acessar o aplicativo de uma empresa. 
    O token precisa ser par e variar de 1000 até 9998. Escreva um código que solicita à pessoa usuária 
    o seu nome e exibe uma mensagem junto a esse token gerado aleatoriamente.
        "Olá, [nome], o seu token de acesso é [token]! Seja bem-vindo(a)!"
    """
    titulo('Programa Sete')
    LIMITE_INFERIOR : Final[int] = 1000
    LIMITE_SUPERIOR : Final[int] = 9998
    nome=input('Informe o nome: ')
    token=randrange(LIMITE_INFERIOR,LIMITE_SUPERIOR)
    print(f'Olá, {nome}, o seu token de acesso é {token}! Seja bem-vindo(a)!')

# ==================================================
# seis()
# ==================================================
def seis()->None:
    """
    6. Um programa deve ser escrito para sortear uma pessoa seguidora de uma rede social para ganhar 
    um prêmio. A lista de participantes é numerada e devemos escolher aleatoriamente um número de acordo 
    com a quantidade de participantes. Peça à pessoa usuária para fornecer o número de participantes do 
    sorteio e devolva para ela o número sorteado.
    """
    titulo('Programa Seis')
    participantes = obter_int_positivo('Informe a quantidade de participantes')
    sorteado=randrange(participantes)
    sorteado += 1
    print(f'O valor sorteado foi {sorteado}')



# ==================================================
# cinco()
# ==================================================
def cinco()->None:
    """
    Crie um programa que solicite à pessoa usuária digitar dois números inteiros e calcular a 
    potência do 1º número elevado ao 2º.
    """
    titulo('Programa Cinco')
    base = obter_int_positivo('Informe a base')
    expoente = obter_int_positivo('Informe o expoente')

    print(f'A potância da base {base} com expoente {expoente} é {pow(base,expoente)}')


# ==================================================
# quatro()
# ==================================================
def quatro()->None:
    """
    4. Crie um programa que sorteia, aleatoriamente, um número inteiro positivo menor que 100.
    """
    titulo('Programa Três')
    LIMITE : Final[int] = 100

    vezes = obter_int_positivo('Informe a quantidade de sorteios')

    for i in range(vezes):
        sorteado = randrange(LIMITE+1)
        if i<vezes-1:
            final_impressao = ', '
        else:
            final_impressao = '\n'
        print(sorteado,end=final_impressao)


# ==================================================
# tres()
# ==================================================
def tres()->None:
    """
    3. Crie um programa que leia a seguinte lista de números e escolha um número desta aleatoriamente.
        lista = [8, 12, 54, 23, 43, 1, 90, 87, 105, 77]
    """
    titulo('Programa Três')
    lista = [8, 12, 54, 23, 43, 1, 90, 87, 105, 77]

    vezes = obter_int_positivo('Informe a quantidade de sorteios')

    for i in range(vezes):
        sorteado = choice(lista)
        if i<vezes-1:
            final_impressao = ', '
        else:
            final_impressao = '\n'
        print(sorteado,end=final_impressao)


# ==================================================
# exibir_menu
# ==================================================
def exibir_menu()-> None:
    menu={
         #1:'?????'
         #,2:'?????'
          3:'Sorteios lista definida'
         ,4:'Sorteios números menor que 100'
         ,5:'Calcular potência'
         ,6:'Sorteio em função de uma quantidade de números informada'
         ,7:'Gerando token'
         ,8:'Salada de Fruta suspresa'
         ,9:'Raiz quandrada de vários números'
         ,10:'Calculo serviço jardinagem'
         }

    titulo('MENU PRINCIPAL')

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
        opcao=int(input("Escolha uma opção (0 para encerrar): "))

        if opcao==0:
            print('Encerrando...')
            break
#        elif opcao==1:
#            um()
#        elif opcao==2:
#            dois()
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

