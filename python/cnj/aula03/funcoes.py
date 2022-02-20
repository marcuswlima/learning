def saudacao(nome, periodo = 'm'):
    if (periodo == 'm'):
        print("Bom dia,", nome + '.', "Essa é a saudação padrão.")
    elif(periodo == 't'):
        print("Boa tarde,", nome + '.')
    elif(periodo == 'n'):
        print("Boa noite,", nome + '.')
    else:
        print("Ops, período inválido.")

print("Esse é o curso de Python.")

saudacao("Paulo",'t')