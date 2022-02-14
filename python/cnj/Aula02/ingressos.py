'''
def eh_numero_natural(digitado):
    resposta = True
    try:
        nnatural = int(digitado)
        resposta = (nnatural >= 0)
    except:
        resposta = False
    return resposta

# print(eh_numero_natural(digitado))

'''

valor_base = 10
# desconto=0
idade = 0

while True:

    digitado = input("Informe uma idade ou digite 'q' para sair: ")

    digitado = digitado.upper()
    if digitado == "Q":
        break

    idade = int(digitado)
    if idade < 5:
        desconto = 100
    elif (idade >= 5) and (idade <= 12):
        desconto = 50
    elif (idade >= 13) and (idade <= 17):
        desconto = 20
    elif (idade >= 18) and (idade < 70):
        desconto = 0
    else:  # idade>=70
        desconto = 100

    print("{}% de desconto".format(desconto))
    print("O valor a ser pago é {}".format(valor_base - (valor_base * desconto / 100)))
