class Pessoa(object):
    """
    Representa uma pessoa

    Utilaza no curso de Paython da Alura

    Atributes
        nome: Nome da pessoa
        idade: idade da pessoa
        profissao: profissao da pessoa
    """
    def __init__(self, in_nome:str='', in_idade:int=0,in_profissao:str=''):
        self._nome = in_nome
        self._idade = in_idade
        self._profissao = in_profissao

    def __str__(self) ->str:
        return f'{self._nome}, {self._idade} anos, {self._profissao}'

    def aniversario(self):
        self._idade += 1 

    @property
    def saudacao(self):
        if self._profissao:
            return f'Olá, sou {self._nome}! Trabalho como {self._profissao}.'
        else:
            return f'Olá, sou {self._nome}!'

help(Pessoa)

# Criando 3 instâncias da classe Pessoa
pessoa1 = Pessoa(in_nome='Alice', in_idade=25, in_profissao='Engenheira')
pessoa2 = Pessoa(in_nome='Luiza', in_idade=30, in_profissao='Desenvolvedor')
pessoa3 = Pessoa(in_nome='Jaque', in_idade=22)

# Imprimindo informações iniciais
print("Informações Iniciais:")
print(pessoa1)
print(pessoa2)
print(pessoa3)
print()

pessoa1.aniversario()
pessoa3.aniversario()

# Imprimindo informações após aniversário
print("Informações após aniversário:")
print(pessoa1)
print(pessoa3)
print()

# Utilizando o método de classe saudacao para exibir mensagens personalizadas
print(pessoa1.saudacao)
print(pessoa2.saudacao)
print(pessoa3.saudacao)