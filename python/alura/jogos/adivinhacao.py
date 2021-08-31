print("*********************************")
print("Bem vindo ao jogo de Adivinhação!")
print("*********************************")

numero_secreto=50

chute_string = input("Digite o seu palpite: ")

print("Você digitou",chute_string)

chute = int(chute_string)

if (numero_secreto == chute):
    print("você acertou")
else:
    print("você errou")

print("fim do jogo")
