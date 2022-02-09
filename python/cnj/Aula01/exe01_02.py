import utilitarios

def executar():

    utilitarios.titulo("Informações de um círculo")

    pi=3.14

    raio = utilitarios.obter_float("Informe o raio do cículo: ")
    perimetro = 2*pi*(raio**2)
    area = pi*(raio**2)
    print("perimetro -> ", perimetro)
    print("area -> ", area)

if __name__ == "__main__":
    executar()
