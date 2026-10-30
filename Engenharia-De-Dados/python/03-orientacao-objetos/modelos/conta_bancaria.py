
# ==================================================
# class ContaBancaria
# ==================================================
class ContaBancaria(object):
    """
    Representa uma conta bancaria

    Utilaza no curso de Paython da Alura

    Atributes
        titular: titular da conta
        saldo: saldo da conta
        _ativo: Situação da conta [true|false] indica se a conta
                está em atividade ou não
    """

    def __init__(self, in_titular:str='', in_saldo:float=0):
        self._titular = in_titular
        self._saldo = in_saldo
        self._ativo = False  # Atributo protegido

    @property
    def titular(self):
        return self._titular

    @property
    def ativo(self):
        return self._ativo

    @property
    def saldo(self):
        return self._saldo

    def __str__(self):
        return f"Conta de {self.titular} - Saldo: R${self.saldo}"


    def ativar_conta(self):
        self._ativo = True

# ==================================================
# class ClienteBanco
# ==================================================
class ClienteBanco(object):
    """
    Representa um cliente do banco

    Utilaza no curso de Paython da Alura

    Atributes
        titular: titular da conta
        saldo: saldo da conta
        _ativo: Situação da conta [true|false] indica se a conta
                está em atividade ou não
    """

    contaBancaria=ContaBancaria()
    def __init__(self, nome, idade, endereco, cpf, profissao):
        self.nome = nome
        self.idade = idade
        self.endereco = endereco
        self.cpf = cpf
        self.profissao = profissao

    @classmethod
    def criar_conta(cls, titular, saldo_inicial):
        conta = ContaBancaria(titular, saldo_inicial)
        return conta

# ==================================================
# main
# ==================================================
help(ContaBancaria)
help(ClienteBanco)

conta1 = ContaBancaria("João", 1000)
conta2 = ContaBancaria("Maria", 500)

print(vars(conta1))
conta1.ativar_conta()
print(vars(conta1))


print(conta1.titular)
print(conta1)



#conta3 = ContaBancaria("Carlos", 200)
##print(vars(conta3))
#print(f"Antes de ativar: Conta ativa? {conta3._ativo}")
#conta3.ativar_conta()
#print(f"Depois de ativar: Conta ativa? {conta3._ativo}")


cliente1 = ClienteBanco("Ana", 30, "Rua A", "123.456.789-01", "Backend")
cliente2 = ClienteBanco("Luiza", 25, "Rua B", "987.654.321-01", "Estudante")
cliente3 = ClienteBanco("Vinny Neves", 40, "Rua C", "111.222.333-44", "Frontend")


conta_cliente1 = ClienteBanco.criar_conta("Ana", 2000)
print(f"Conta de {conta_cliente1.titular} criada com saldo inicial de R${conta_cliente1.saldo}")

