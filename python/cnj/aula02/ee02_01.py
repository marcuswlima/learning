import utilitarios

def executar_01_01():
    utilitarios.titulo("Cálculo do IMC")

    altura = utilitarios.obter_float("Informe a altura: ")
    peso = utilitarios.obter_float("Informe o peso: ")
    imc = utilitarios.imc(peso,altura)

    print("altura -> ", altura)
    print("peso -> ", peso)
    print("imc -> ", imc)

    faixa="Normal"

    if (imc<18.5):
        faixa="Magreza"
    elif imc>=18.5 and imc<=24.9:
        faixa="Nornal"

    print("Com o IMC={} de desconto".format(desconto))
    

if __name__ == "__main__":
    executar_01_01()
