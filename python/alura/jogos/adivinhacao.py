print("*********************************")
print("Bem vindo ao jogo de Adivinhação!")
print("*********************************")

numero_secreto = 42
total_de_tentativas = 3
rodada = 1

while rodada <= total_de_tentativas:
    #print("Tentativa", rodada, " de ", total_de_tentativas)
    print("Tentativa {} de {}".format(rodada, total_de_tentativas))
    chute_string = input("Digite o seu palpite: ")
    print("Você digitou", chute_string)
    chute = int(chute_string)

    acertou = chute == numero_secreto
    maior = chute > numero_secreto
    menor = chute < numero_secreto

    if acertou:
        print("você acertou")
    else:
        if maior:
            print("você errou! O seu chute foi maior que o número secreto.")
        elif menor:
            print("você errou! O seu chute foi menor que o número secreto.")

    rodada = rodada + 1

print("fim do jogo")
