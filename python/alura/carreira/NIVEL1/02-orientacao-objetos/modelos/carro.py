class Carro(object):
    """
    Destina ao aprendizado de criação de objetos
    """
    modelo=''
    cor=''
    ano=0

    carros=[]

    def __init__(self:Any, in_modelo:str='', in_cor:str='', in_ano:int=0)->Any:
        self.modelo = in_modelo
        self.cor = in_cor
        self.ano = in_ano
        Carro.carros.append(self)

    def __str__(self)->str:
#        """
#        Apresentaçao do objeto na tela
#        """
        return f'Carro: {self.modelo} | Cor: {self.cor} | Ano: {self.ano}'

    def listar_todos():
        for carro in Carro.carros:
            print(carro)



a=Carro(in_ano=1974,in_cor='Azul',in_modelo='Fusca')
b=Carro('Celta','Preta',1958)
c=Carro(in_modelo='Fiat',in_ano=1900, in_cor='vermelho')

Carro.listar_todos()

