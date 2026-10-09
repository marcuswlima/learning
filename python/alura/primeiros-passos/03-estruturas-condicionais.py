import utilitarios as utl

"""
Consolidar os exercícios do terceiro módulo do curso de python

Autor: Marcus William
Data: 03/10/2026
"""

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
    print("\n=== MENU PRINCIPAL ===")
    print("1 - um")
    print("2 - dois")
    print("3 - Determine se uma letra fornecida pela pessoa usuária é uma vogal ou consoante")
    print("4 - Excluir usuário")
    print("5 - Cinco")
    print("6 - Seis")
    print("7 - Sete")
    print("8 - Oito")
    print("0 - Sair")

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
        elif opcao == "0":
            print("Programa encerrado.")
            break
        else:
            print("Opção inválida.")

if __name__ == "__main__":
    main()