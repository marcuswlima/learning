def virgula_to_ponto(com_virgula):
    return com_virgula.replace(',','.')


print("*********************")
print("** Cálculo do  IMC **")
print("*********************")


altura_informada = input("Informe a altura: ")
peso_informado = input("Informe o peso: ")

altura = float(virgula_to_ponto(altura_informada))
peso = float(virgula_to_ponto(peso_informado))
imc = peso / (altura*altura)

print("altura -> ", altura)
print("peso -> ", peso)
print("imc -> ", imc)
