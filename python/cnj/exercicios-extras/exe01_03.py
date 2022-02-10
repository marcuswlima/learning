import utilitarios
import math

def executar():
    utilitarios.titulo("Fórmula de Baskara")
    a = int(input("Digite a: "))
    b = int(input("Digite b: "))
    c = int(input("Digite c: "))

    delta=(b**2) - (4*a*c)

    if (a==0):
        print("o valor de a dever ser difirente de 0")
    elif (delta < 0):
        print("Esta equação não tem raízes reais")
    else:
        print("delta", delta)

        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)

        print("x1: {}, x2: {}".format(x1, x2))


if __name__ == "__main__":
    executar()
