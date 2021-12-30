import random

print("***********************************")
print("Bem vindo ao jogo de adivinhação!!!")
print("***********************************")

numero_secreto = random.randrange(1,101)
total_de_tentativas = 3
print(numero_secreto)

for rodada in range(1,total_de_tentativas+1 ):
    print("Tentativa {} de {}".format(rodada,total_de_tentativas))
    chute_str = input("DIgite o seu núnero entre 1 e 100: ")
    print("Você digitou", chute_str)
    chute = int(chute_str)

    if (chute < 1 or chute > 100):
        print("Digite [1,100]")
        continue

    acertou = chute == numero_secreto
    maior   = chute >  numero_secreto
    menor   = chute <  numero_secreto

    if (acertou):
        print("Você acertou")
        break
    elif(maior):
        print("maior")
    elif(menor):
        print("menor")

print("Fim do Jogo")