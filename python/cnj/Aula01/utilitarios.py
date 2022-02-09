def obter_float(mensagem):
    digitado = input(mensagem)
    return float(digitado.replace(',','.'))

def escrever_linha(tamanho_texto):
    print("***",end="")
    for i in range(tamanho_texto):
        print("*",end="")
    print("***")

def titulo(mensagem):
    escrever_linha(len(mensagem))
    print("**",mensagem, "**")
    escrever_linha(len(mensagem))

def imc(peso,altura):
    return peso / (altura**2)
