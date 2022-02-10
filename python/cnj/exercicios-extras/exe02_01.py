import utilitarios

def executar():
    utilitarios.titulo("IMC Qualificado")
    altura = utilitarios.obter_float("Informe a altura: ")
    peso = utilitarios.obter_float("Informe o peso: ")
    imc = utilitarios.imc(peso,altura)

    print("altura -> ", altura)
    print("peso -> ", peso)
    print("imc -> ", imc)


    print("Qualificação: ",end="")
    if (imc < 18.5):
        print("Magreza")
    elif (imc >= 18.5) and ( imc <  25):
        print("Normal")
    elif (imc >= 25) and ( imc <  30):
        print("Sebrepeso")
    elif (imc >= 30) and ( imc <  40):
        print("Obesidade")
    elif (imc >= 40):
        print("Obesidade grave")


if __name__ == "__main__":
    executar()
