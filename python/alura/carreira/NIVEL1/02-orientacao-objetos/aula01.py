class Restaurante:

    retaurantes = []

    def __init__(self, nome:int, categoria:int)->None:
        self.nome = nome
        self.categoria = categoria
        self.ativo = False
        Restaurante.retaurantes.append(self)

    def __str__(objeto)->str:
        return f'{objeto.nome} | {objeto.categoria}'

    def listar_restaurantes():
        for restaurante in Restaurante.retaurantes:
            print(restaurante)



restaurante_praca=Restaurante(nome='Praça',categoria='Gourmet')
restaurante_pizza=Restaurante(nome='Pizza Express',categoria='Italiana')
restaurante_pizza=Restaurante(nome='nome',categoria='categoria')

#restaurantes = [restaurante_praca,restaurante_pizza]

#print(vars(restaurante_praca))
#print(vars(restaurante_pizza))
print(dir(restaurante_praca))
#print(vars(restaurante_pizza))
#print(restaurante_praca)
#print(restaurante_pizza)

Restaurante.listar_restaurantes()
