def virgura_to_ponto(com_virgula):
    return com_virgula.replace(',','.')


print("***********************************")
print(" IMC=peso/(altura*altura)")
print("***********************************")

print("peso")
print("altura")

altura_informada = input("Informe a altura: ")
peso_informado = input("Informe o peso: ")

altura = float(virgura_to_ponto(altura_informada))
peso = float(virgura_to_ponto(peso_informado))
imc = peso / (altura*altura)

print("altura -> ", altura)
print("peso -> ", peso)
print("imc -> ", imc)
