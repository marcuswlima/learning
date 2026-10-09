import utilitarios as utl
from typing import Final

"""
Consolidar os exercícios do terceiro módulo do curso de python

Autor: Marcus William
Data: 03/10/2026
"""

# ==================================================
# treze
# ==================================================
def treze()-> None:
    """
    13) Em uma empresa de venda de imóveis você precisa criar um código que analise os dados de vendas 
    anuais para ajudar a diretoria na tomada de decisão. O código precisa coletar os dados de quantidade 
    de venda durante os anos de 2022 e 2023 e fazer um cálculo de variação percentual. A partir do valor 
    da variação, deve ser enviada às seguintes sugestões:
        - Para variação acima de 20%: bonificação para o time de vendas.
        - Para variação entre 2% e 20%: pequena bonificação para time de vendas.
        - Para variação entre 2% e -10%: planejamento de políticas de incentivo às vendas.
        - Para variação abaixo de -10%: corte de gastos.
    """
    utl.titulo('Projeto 13')

# ==================================================
# doze
# ==================================================
def doze()-> None:
    """
    12) Um estabelecimento está vendendo combustíveis com descontos variados. Para o etanol, se a quantidade 
    comprada for até 15 litros, o desconto será de 2% por litro. Caso contrário, será de 4% por litro. 
    Para o diesel, se a quantidade comprada for até 15 litros, o desconto será de 3% por litro. 
    Caso contrário, será de 5% por litro. O preço do litro de diesel é R$ 2,00 e o preço do 
    litro de etanol é R$ 1,70. Escreva um programa que leia a quantidade de litros vendidos e o
    tipo de combustível (E para etanol e D para diesel) e calcule o valor a ser pago pelo cliente. 
    Tenha em mente algumas dicas:
       - O do valor do desconto será a multiplicação entre preço do litro, quantidade de litros e o valor do desconto.
       - O valor a ser pago por um cliente será o resultado da multiplicação do preço do litro pela quantidade de litros menos o valor de desconto resultante do cálculo.
    """
    utl.titulo('Projeto 12')

    #Constantes
    LIMITE_DESCONTO           : Final[int] = 15
    DESCONTO_ETANOL_15_ABAIXO : Final[float] = 0.02
    DESCONTO_ETANOL_15_ACIMA  : Final[float] = 0.04
    DESCONTO_DIESEL_15_ABAIXO : Final[float] = 0.03
    DESCONTO_DIESEL_15_ACIMA  : Final[float] = 0.05
    VALOR_LITRO_DIESEL        : Final[float] = 2
    VALOR_LITRO_ETANOL        : Final[float] = 1.7

    quantidade_venda=utl.obter_float('Informe a quantidade da venda')
    tipo_combustivel=input('Informe o tipo de combustível [E|D]: ')


    if tipo_combustivel == 'E':
        if quantidade_venda < LIMITE_DESCONTO:
            valor_a_ser_pago = quantidade_venda * VALOR_LITRO_ETANOL * DESCONTO_ETANOL_15_ABAIXO
        else:
            valor_a_ser_pago = quantidade_venda * VALOR_LITRO_ETANOL * DESCONTO_ETANOL_15_ACIMA

    if tipo_combustivel == 'D':
        if quantidade_venda < LIMITE_DESCONTO:
            valor_a_ser_pago = quantidade_venda * VALOR_LITRO_DIESEL * DESCONTO_DIESEL_15_ABAIXO
        else:
            valor_a_ser_pago = quantidade_venda * VALOR_LITRO_DIESEL * DESCONTO_DIESEL_15_ACIMA

    print('valor a ser pago',valor_a_ser_pago)


# ==================================================
# onze
# ==================================================
def onze()-> None:
    """
    10. Escreva um programa que peça à pessoa usuária três números que representam os lados de um triângulo. 
    O programa deve informar se os valores podem ser utilizados para formar um triângulo e, caso afirmativo, 
    se ele é equilátero, isósceles ou escaleno. Tenha em mente algumas dicas:
       Três lados formam um triângulo quando a soma de quaisquer dois lados for maior que o terceiro;
       Triângulo Equilátero: três lados iguais;
       Triângulo Isósceles: quaisquer dois lados iguais;
       Triângulo Escaleno: três lados diferentes.
    """
    utl.titulo('Projeto 11')
    l1=utl.obter_float('Primeiro lado')
    l2=utl.obter_float('Segundo lado')
    l3=utl.obter_float('terceiro lado')

    if (l1 + l2 > l3) and (l1 + l3 > l2) and (l2 + l3 > l1) :
        if l1 == l2 and l2 == l3 :
            print('forma triangulo equilátero')
        else:
            if (l1 == l2) or (l1 == l3) or (l2 == l3):
                print('forma triangulo Isósceles')
            else:
                print('forma triangulo Escaleno')
    else:
        print('não forma triangulo')

# ==================================================
# dez
# ==================================================
def dez()-> None:
    """
    10. Um programa deve ser escrito para ler dois números e, em seguida, perguntar à pessoa usuária 
    qual operação ele deseja realizar. O resultado da operação deve incluir informações sobre o 
    número - se é par ou ímpar, positivo ou negativo e inteiro ou decimal.
    """
    utl.titulo('Projeto 10')
    f1=utl.obter_float('Primeiro Número')
    f2=utl.obter_float('Segundo Número')
    operador = input("Informe o operador [ + , - , * , / ]: ")

    if operador == '+':
        resultado = f1 + f2
    elif operador == '-':
        resultado = f1 - f2
    elif operador == '*':
        resultado = f1 * f2
    elif operador == '/':
        resultado = f1 / f2

    print('resultado',resultado)

    if utl.is_par(resultado):
        print('eh par')
    else:
        print('eh impar')

    if resultado > 0 :
        print('eh positivo')
    else:
        print('eh negativo')

    if utl.is_inteiro(resultado):
        print('eh inteiro')
    else:
        print('eh decimal')


# ==================================================
# Nove
# ==================================================
def nove()-> None:
    """
    9. Escreva um programa que peça um número à pessoa usuária e informe se ele é inteiro ou decimal
    """
    utl.titulo('programa 09')

    f = utl.obter_float('Informe um número')

    if f % 1 == 0 :
        print('inteiro')
    else:
        print('decimal')

# ==================================================
# oito
# ==================================================
def oito()-> None:
    """
    8) Escreva um programa que peça um número inteiro à pessoa usuária e determine se ele é par ou ímpar.
    """

    n = utl.obter_int('Informe um número: ')

    if utl.is_par(n):
        print('é par')
    else:
        print('é impar')

# ==================================================
# sete
# ==================================================
def sete()-> None:
    """
    7) Escreva um programa que pergunte em qual turno a pessoa usuária estuda ("manhã", "tarde" ou "noite") e exiba a mensagem "Bom Dia!", "Boa Tarde!", "Boa Noite!", ou "Valor Inválido!", conforme o caso.
    """
    caractere = input('Informe o turno [1,2,3] ')

    if caractere.isnumeric() and caractere in ('1','2','3'):

        if caractere == '1':
            utl.titulo('Bom dia!!')
        if caractere == '2':
            utl.titulo('Bom Tarde!!')
        if caractere == '3':
            utl.titulo('Bom Noite!!')
    else:
        print("Erro: Número Inválido")






# ==================================================
# seis
# ==================================================
def seis()-> None:
    """
    Exercicio 03.06

    6) Escreva um programa que leia três números e os exiba em ordem decrescente.
    """

    utl.titulo('Seis, seis')
    n1 = utl.obter_int('Informe um número: ')
    n2 = utl.obter_int('Informe outro número: ')
    n3 = utl.obter_int('Informe mais um número: ')

    maior = utl.indicar_maior_numero(n1,n2,n3)
    menor = utl.indicar_menor_numero(n1,n2,n3)

    if menor < n1 and n1 < maior:
        meio=n1
    elif menor < n2 and n2 < maior:
        meio=n2
    else:
        meio=n3



    print('Primerio '+menor);
    print('Segundo '+meio);
    print('Terceito '+maior);


# ==================================================
# cinco
# ==================================================
def cinco()-> None:
    """
    Exercicio 03.05

    5) Escreva um programa que pergunte sobre o preço de três produtos e indique qual é o produto mais barato para comprar.
    """
    utl.titulo('cinco')
    f1=utl.obter_float('Primeiro preço: ')
    f2=utl.obter_float('Segundo preço: ')
    f3=utl.obter_float('Terceiro preço: ')
    maisbarato=0

    if f1 < f2 and f1 < f3:
        maisbarato=f1
    elif f2 < f1 and f2 < f3:
        maisbarato=f2
    elif f3 < f1 and f3 < f2:
        maisbarato=f3

    print('O preço mais barato é '+str(maisbarato))



# ==================================================
# quatro
# ==================================================
def quatro()-> None:
    """
    Exercicio 03.04

    4) Escreva um programa que leia valores médios de preços de um modelo de carro por 3 anos consecutivos e exiba o valor mais alto e mais baixo entre esses três anos.
    """
    utl.titulo('3 valores')
    n1 = utl.obter_int('Informe um número: ')
    n2 = utl.obter_int('Informe outro número: ')
    n3 = utl.obter_int('Informe mais um número: ')

    maior = utl.indicar_maior_numero(n1,n2,n3)
    menor = utl.indicar_menor_numero(n1,n2,n3)

    print('maior ',maior)
    print('menor ',menor)

# ==================================================
# tres
# ==================================================
def tres()-> None:
    """
    Exercicio 03.03
    
    3) Escreva um programa que determine se uma letra fornecida pela pessoa usuária é uma vogal ou consoante.

    Args:

    Returns:
    """
    letra=utl.obter_uma_letra()

    if letra in ('A','a') :
        print('Vogal')
    elif letra in ('E','e'):
        print('Vogal')
    elif letra in ('I','i'):
        print('Vogal')
    elif letra in ('O','o'):
        print('Vogal')
    elif letra in ('U','u'):
        print('Vogal')
    else:
        print('Consoante')

# ==================================================
# dois
# ==================================================
def dois()-> None:
    """
    Exercicio 03.02
    
    01. Escreva um programa que solicite o percentual de crescimento de produção de uma empresa e 
    informe se houve um crescimento (porcentagem positiva) ou decrescimento (porcentagem negativa).

    Args:

    Returns:
    """
    percentual = float(input('Informe o Percetual: '))
    if percentual > 0 :
        print('positivo')
    else:
        print('negativo')


# ==================================================
# um
# ==================================================
def um()-> None:

    """
    Exercicio 03.01
    
    01. Escreva um programa que peça à pessoa usuária para fornecer dois números e exibir o número maior.

    Args:

    Returns:
    """
    utl.titulo('programa 01')

    n1 = float(input('Primeiro Numero: '))
    n2 = float(input('Segundo Numero: '))
    if n1 > n2:
        print('O maior numero é',n1)
    else:
        print('O maior numero é',n2)

# ==================================================
# exibir_menu
# ==================================================
def exibir_menu():
    utl.titulo('MENU PRINCIPAL')
    print("1 - um")
    print("2 - dois")
    print("3 - Determine se uma letra fornecida pela pessoa usuária é uma vogal ou consoante")
    print("4 - Excluir usuário")
    print("5 - Cinco")
    print("6 - Seis")
    print("7 - Sete")
    print("8 - Oito")
    print("9 - Nove")
    print("10 - Dez")
    print("11 - Onze")
    print("12 - Doze")
    print("13 - Treze")
    print("0 - Sair")
    print(" ")

# ==================================================
# main
# ==================================================

def main():
    while True:
        exibir_menu()

        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            um()
        elif opcao == "2":
            dois()
        elif opcao == "3":
            tres()
        elif opcao == "4":
            quatro()
        elif opcao == "5":
            cinco()
        elif opcao == "6":
            seis()
        elif opcao == "7":
            sete()
        elif opcao == "8":
            oito()
        elif opcao == "9":
            nove()
        elif opcao == "10":
            dez()
        elif opcao == "11":
            onze()
        elif opcao == "12":
            doze()
        elif opcao == "13":
            treze()
        elif opcao == "0":
            print("Programa encerrado.")
            break
        else:
            print("Opção inválida.")

        print()

if __name__ == "__main__":
    main()