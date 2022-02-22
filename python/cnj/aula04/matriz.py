Matriz = [ [0, 1, 2], [3, 4, 5] ]
Matriz.insert(2, [6, "marcus", 8])
print(Matriz)
Matriz[0] = [4,5,6]
print(Matriz)
Matriz[0][2] = 9999
print(Matriz)
del(Matriz[1])
print(Matriz)
Matriz.insert(90, [6, 7, 8])
print(Matriz)
Matriz2 = Matriz[:3]
print(Matriz2)