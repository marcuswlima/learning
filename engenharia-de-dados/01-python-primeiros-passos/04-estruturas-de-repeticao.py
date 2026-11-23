import utilitarios as utl
from typing import Final

"""
Consolidar os exercícios do quarto módulo do curso de python

Autor: Marcus William
Data: 09/10/2026
"""

# ==================================================
# Nove
# ==================================================
def nove()-> None:
    """
    9) Em uma eleição para gerência em uma empresa com 20 pessoas colaboradoras, existem quatro 
    candidatos(as). Escreva um programa que calcule o(a) vencedor(a) da eleição. A votação ocorreu da seguinte maneira:
     - Cada colaborador(a) votou em uma das quatro pessoas candidatas (que representamos pelos números 1, 2, 3 e 4).
     - Também foram contabilizados os votos nulos (representados pelo número 5) e os votos em branco (representados pelo número 6).
    Ao final da votação, o programa deve exibir o número total de votos para cada candidato(a), os nulos e os votos 
    em branco. Além disso, deve calcular e exibir a porcentagem de votos nulos em relação ao total de votos e a 
    porcentagem de votos em branco em relação ao total de votos.
    0-sair
    1-1
    2-2
    3-3
    4-4
    5-nulo
    6-em branco
    """
    utl.titulo('programa 09')

    v1=0
    v2=0
    v3=0
    v4=0
    v5=0
    v6=0
    votos=0
    vInvalido=0
    
    voto = int(input('Informe o voto (0 para encerrar): '))

    while voto>0:

        if voto == 1:
            v1 += 1
        elif voto == 2:
            v2 += 1
        elif voto == 3:
            v3 += 1
        elif voto == 4:
            v4 += 1
        elif voto == 5:
            v5 += 1
        elif voto == 6:
            v6 += 1
        else:
            vInvalido +=1

        votos += 1

        voto = int(input('Informe o voto (0 para encerrar): '))

    print(f'Total de votos: {votos}')
    print(f'Invalidos:  {vInvalido} - {round(vInvalido*100/votos,2)}%')
    print(f'Candidato1: {v1} - {round(v1*100/votos,2)}%')
    print(f'Candidato2: {v2} - {round(v2*100/votos,2)}%')
    print(f'Candidato3: {v3} - {round(v3*100/votos,2)}%')
    print(f'Candidato4: {v4} - {round(v4*100/votos,2)}%')
    print(f'Nulos     : {v5} - {round(v5*100/votos,2)}%')
    print(f'Em Branco : {v6} - {round(v6*100/votos,2)}%')

# ==================================================
# oito
# ==================================================
def oito()-> None:
    """
    8) Vamos entender a distribuição de idades de pensionistas de uma empresa de previdência. 
    Escreva um programa que leia as idades de uma quantidade não informada de clientes e mostre 
    a distribuição em intervalos de [0-25], [26-50], [51-75] e [76-100]. 
    Encerre a entrada de dados com um número negativo.
    """
    # Coletamos as idades dos clientes
    idade = int(input('Informe a idade (ou um número negativo para encerrar): '))

    # Inicializamos as variáveis de contadores
    contador_0_25 = 0 # contador de idades entre 0 e 25
    contador_26_50 = 0 # contador de idades entre 26 e 50
    contador_51_75 = 0 # contador de idades entre 51 e 75
    contador_76_100 = 0 # contador de idades entre 76 e 100

    while idade >=0:
        if idade >=0 and idade<=25:
            contador_0_25 += 1
        elif idade >=26 and idade<=50:
            contador_26_50 += 1
        elif idade >= 51 and idade <= 75:
            contador_51_75 += 1
        elif idade >= 76 and idade <= 100:
            contador_76_100 += 1
        idade = int(input('Informe a idade (ou um número negativo para encerrar): '))

    # Mostramos os resultados
    print('Distribuição de idades:')
    print('[0-25]:', contador_0_25)
    print('[26-50]:', contador_26_50)
    print('[51-75]:', contador_51_75)
    print('[76-100]:', contador_76_100)

# ==================================================
# sete
# ==================================================
def sete()-> None:
    """
    7) Os números primos possuem várias aplicações dentro da Ciência de Dados em criptografia e segurança, 
    por exemplo. Um número primo é aquele que é divisível apenas por um e por ele mesmo. Assim, 
    faça um programa que peça um número inteiro e determine se ele é ou não um número primo.
    """
    utl.titulo('Exercicio 07')

    num = int(input('Informe um número: '))

    eh_primo=True

    if num <= 1:
        eh_primo=False
    else:
        for i in range(2,num):
            if num % i == 0:
                eh_primo=False
                break

    if eh_primo:
        print(f'O número {num} é primo')
    else:
        print(f'O número {num} não é primo')

# ==================================================
# seis
# ==================================================
def seis()-> None:
    """
    6) Escreva um programa que gere a tabuada de um número inteiro de 1 a 10, de acordo 
    com a escolha da pessoa usuária. Como exemplo, para o número 2, a tabuada deve 
    ser mostrada no seguinte formato:
    """
    utl.titulo('Exercicio 06')

    num = int(input('Informe um númnero: '))

    for i in range(10):
        print(f'{num} x {i+1} = {num*(i+1)}')


# ==================================================
# cinco
# ==================================================
def cinco()-> None:
    """
    5) Escreva um programa que calcule o fatorial de um número inteiro fornecido pela pessoa usuária. 
    Lembrando que o fatorial de um número inteiro é a multiplicação desse número por todos os seus
    antecessores até o número 1. Por exemplo, o fatorial de 5 é 5 x 4 x 3 x 2 x 1 = 120.
    """
    utl.titulo('Exercicio 05')

    numero = int(input('Informe o número: '))
    fatorial = 1

    i=numero
    while (i>=1):
        fatorial *= i
        i -= 1

    print(f'{numero}!={fatorial}')

# ==================================================
# quatro
# ==================================================
def quatro()-> None:
    """
    4) Desenvolva um programa que leia um conjunto indeterminado de temperaturas em 
    Celsius e informe a média delas. A leitura deve ser encerrada ao ser enviado o valor -273°C.
    """
    utl.titulo('Exercicio 04')

    # coletar
    temperatura = float(input('Insira a temperatura em Celcius: '))

    contador = 0
    soma = 0

    while temperatura != -273:
        soma += temperatura
        contador =+ 1

        # coletar
        temperatura = float(input('Insira a temperatura em Celcius: '))

    media = soma / contador

    print(f'A media das temperatira é : {media}')


# ==================================================
# tres
# ==================================================
def tres()-> None:
    """
    3) Para tratar uma quantidade de 15 dados de avaliações de pessoas usuárias de um 
    serviço da empresa, precisamos verificar se as notas são válidas. Então, escreva 
    um programa que vai receber a nota de 0 a 5 de todos os dados e verificar se é um 
    valor válido. Caso seja inserido uma nota acima de 5 ou abaixo de 0, repita 
    até que a pessoa usuária insira um valor válido.
    
    Args:

    Returns:
    """
    utl.titulo('Exercicio 03')

    # laço para pegar as 15 notas
    for i in range(16):

        if i == 0:
            continue
            
        nota = float(input(f'Insira a nota da pessoa usuária {i} [0,5]: '))

        # verifica se a nota está entre 0 e 5
        # se estiver, o laço rodará ininterruptamente até ser obtido um valor válido
        while (nota < 0) or (nota > 5):
            nota = float(input(f'Nota inválida, insira novamente a nota da pessoa usuária {i}: '))

    print('Verificação feita. Todas as notas são válidas')

# ==================================================
# dois
# ==================================================
def dois()-> None:
    """
    2) Escreva um programa para calcular quantos dias levará para a colônia de uma 
    bactéria A ultrapassar ou igualar a colônia de uma bactéria B, com base nas 
    taxas de crescimento de 3% e 1,5% respectivamente. Considere que a colônia A inicia 
    com 4 elementos e a B com 10.

    Args:

    Returns:
    """

    utl.titulo('Exercicio 02')
    
    TAXA_CRESCIMENTO_A : Final[float] = 3
    TAXA_CRESCIMENTO_B : Final[float] = 1.5

    pop_a=4.0
    pop_b=10.0
    iteracoes=1

    while pop_a < pop_b:
        print(iteracoes, pop_a, pop_b)
        pop_a += pop_a*TAXA_CRESCIMENTO_A/100
        pop_b += pop_b*TAXA_CRESCIMENTO_B/100
        iteracoes += 1

    



# ==================================================
# um
# ==================================================
def um()-> None:

    """
    01. Escreva um programa que peça à pessoa usuária para fornecer dois números e exibir o número maior.

    Args:

    Returns:
    """
    utl.titulo('programa 01')

    n1 = utl.obter_int('Primeiro Numero')
    n2 = utl.obter_int('Segundo Numero')

    if n1 > n2:
        maior = n1
        menor = n2
    else:
        maior = n2
        menor = n1

    for i in range(menor+1,maior):
        print(i)

# ==================================================
# exibir_menu
# ==================================================
def exibir_menu():
    utl.titulo('MENU PRINCIPAL')
    print("1 - um")
    print("2 - dois")
    print("3 - Três")
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
        elif opcao == "0":
            print("Programa encerrado.")
            break
        else:
            print("Opção inválida.")

        print()

if __name__ == "__main__":
    main()