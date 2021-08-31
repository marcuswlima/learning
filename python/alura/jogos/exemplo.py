numero_secreto=42

chute_string = input("Digite o seu palpite: ")
print("Você digitou",chute_string)
chute = int(chute_string)

acertou = chute == numero_secreto

type(acertou)
