import utilitarios as utl
import numpy       as np


#----------------------------
utl.titulo("Exercicio 06")


data = np.genfromtxt("../../../../../dados/python/Dados.csv", delimiter=';')

ocorrencias = data.shape[0]
qtd_colunas = 15

new = data.reshape(int(ocorrencias/qtd_colunas),qtd_colunas)

print(data)
print(new)

for linha in new:
    print(linha, linha.sum())

print(new.sum(axis=1))
print(new.sum())
