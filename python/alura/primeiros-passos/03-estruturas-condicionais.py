"""
Consolidar os exercícios do terceiro módulo do curso de python

Autor: Marcus William
Data: 03/10/2026
"""

def um()-> none:


    """
    Exercicio 03.01
    
    01. Escreva um programa que peça à pessoa usuária para fornecer dois números e exibir o número maior.

    Args:

    Returns:
    """

    with arquivo.open("r", encoding="utf-8") as f:
        return sum(1 for _ in f)

    print("***********************")
    print("*** um")
    print("***********************")
    n1 = float(input('Primeiro Numero: '))
    n2 = float(input('Segundo Numero: '))
    if n1 > n2:
        print('O maior numero é',n1)
    else:
        print('O maior numero é',n2)


def consultar_usuario():
    print("Executando procedure: consultar usuário")


def atualizar_usuario():
    print("Executando procedure: atualizar usuário")


def excluir_usuario():
    print("Executando procedure: excluir usuário")


def exibir_menu():
    print("\n=== MENU PRINCIPAL ===")
    print("1 - um")
    print("2 - Consultar usuário")
    print("3 - Atualizar usuário")
    print("4 - Excluir usuário")
    print("0 - Sair")


def main():
    while True:
        exibir_menu()

        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            um()

        elif opcao == "2":
            consultar_usuario()

        elif opcao == "3":
            atualizar_usuario()

        elif opcao == "4":
            excluir_usuario()

        elif opcao == "0":
            print("Programa encerrado.")
            break

        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()