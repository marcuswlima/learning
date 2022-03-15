import utilitarios as utl
import numpy as np

utl.titulo("aula05")

vetor = np.array([1.7,2,3,4])
matriz = np.array([[4,5,6],[7,8,9]])

print(vetor.ndim, vetor.shape, vetor.dtype, vetor.size)
print(matriz.ndim, matriz.shape, matriz.dtype, matriz.size)

vetor2 = np.linspace(10,20,1000)
#print(vetor2)

import numpy as np
dados = np.random.randint(0,100,(5,6))
print(dados)

import numpy as np
dados = np.ones((4,3))
print(dados)
soma = dados.sum()
print(soma)