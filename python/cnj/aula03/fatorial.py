def fatorial(n):
    res = n
    n = n -1
    while(n > 1):
        res = res*n
        n = n -1
    print("O fatorial é", res)


valor = int(input("Digite um valor ou -1 para sair: "))
while(valor != -1):
    fatorial(valor)
    valor = int(input("Digite um valor ou -1 para sair: "))

