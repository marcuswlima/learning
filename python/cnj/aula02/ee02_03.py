import utilitarios

def ee02_03():
    utilitarios.titulo("exercicio extra 02.03")

    cidade_informada = "inicio"
    maior_populacao=0
    cidade_mais_populosa="inicio"
    while (cidade_informada!="sair"):
        cidade_informada = input("Informe o nome da cidade: ")
        if(cidade_informada!="sair"):
            populacao_da_cidade = int(input("Informe a polulação: "))
            if (int(populacao_da_cidade) > int(maior_populacao)):
                maior_populacao = populacao_da_cidade
                cidade_mais_populosa = cidade_informada

                
    print("A cidade com maior população é {} com seus {} habitantes".format(cidade_mais_populosa,maior_populacao))

if __name__ == "__main__":
    ee02_03()
