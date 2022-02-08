def obter_float(mensagem):
    digitado = input(mensagem)
    return float(digitado.replace(',','.'))

print("*********************")
print("** Cálculo do  IMC **")
print("*********************")

altura = obter_float("Informe a altura: ")
peso = obter_float("Informe o peso: ")
imc = peso / (altura*altura)

print("altura -> ", altura)
print("peso -> ", peso)
print("imc -> ", imc)