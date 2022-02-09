import utilitarios


def executar():
    utilitarios.titulo("Cálculo do IMC")

    altura = utilitarios.obter_float("Informe a altura: ")
    peso = utilitarios.obter_float("Informe o peso: ")
    imc = utilitarios.imc(peso,altura)

    print("altura -> ", altura)
    print("peso -> ", peso)
    print("imc -> ", imc)

if __name__ == "__main__":
    executar()
