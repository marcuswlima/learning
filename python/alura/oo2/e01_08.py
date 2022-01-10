class Pessoa:
    pass

pessoa = Pessoa()
pessoa.nome = 'Jade'
print(pessoa.nome)

print("*****************")


class Pessoa:
    tamanho_cpf = 11 ## atributo de uma classe

    def __init__(self, cpf, nome):
        self.cpf = cpf
        self.nome = nome

    def valida_cpf(self):
        return True if len(self.cpf) == __class__.tamanho_cpf else False

pe = Pessoa('00000000001', 'Ruby')
print(pe.nome)
print(pe.valida_cpf())

pe = Pessoa('00000800000', 'Cristal')
print(pe.nome)
print(pe.valida_cpf())