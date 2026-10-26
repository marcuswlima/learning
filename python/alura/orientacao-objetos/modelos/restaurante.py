from modelos.avaliacao import Avaliacao

class Restaurante(object):
    """
    Representa os retaurantes

    Utilaza no curso de Paython da Alura

    Atributes
        _nome: Nome do restaurante
        _categoria: Categoria do restaurante
        _ativo: Sutuação do restauranto [true|false] indica se o restarante 
                está em atividade ou não
    """

    _retaurantes = []

    def __init__(self, in_nome:str, in_categoria:str):
        self._nome = in_nome.title()
        self._categoria = in_categoria.upper()
        self._ativo = False
        self._avaliacoes = []
        Restaurante._retaurantes.append(self)

    def __str__(objeto)->str:
        return f'{objeto._nome} | {objeto._categoria} | {objeto._ativo} '

    @classmethod
    def listar_restaurantes(cls)->None:
        """
        Listar todos os objetos da classe na tela
        """
        tananho_coluna=20
        print('-'*(tananho_coluna+1),'-'*(tananho_coluna+2),'-'*(tananho_coluna+2),'-'*(tananho_coluna+2))        
        print(f'{'Nome do restaurante'.ljust(tananho_coluna)} | {'Categoria'.ljust(tananho_coluna)} | {'Avaliação'.ljust(tananho_coluna)} | {'Status'}'
             )        
        print('-'*(tananho_coluna+1),'-'*(tananho_coluna+2),'-'*(tananho_coluna+2),'-'*(tananho_coluna+2))        
        for restaurante in cls._retaurantes:
            print(f'{restaurante._nome.ljust(tananho_coluna)} | {restaurante._categoria.ljust(tananho_coluna)} | {str(restaurante.media_avaliacoes).ljust(tananho_coluna)} | {restaurante.ativo}'
                  )

    @property
    def ativo(self)->str:
        return '⌧' if self._ativo else '☐'

    @property
    def nome(self):
        return self._nome

    @property
    def categoria(self):
        return self._categoria

    def alternar_estado(self)->None:
        self._ativo = not self._ativo

    def receber_avaliacao(self, in_cliente:str, in_nota:float)->None:
        if 0 < in_nota <= 5 :
            avaliacao = Avaliacao(in_cliente=in_cliente, in_nota=in_nota)
            self._avaliacoes.append(avaliacao)
    
    @property
    def media_avaliacoes(self):
        if not self._avaliacoes:
            return '-'
        else:
            somas_das_notas = sum(avaliacao._nota for avaliacao in self._avaliacoes)
            quantidade_de_notas = len(self._avaliacoes)
            media_avaliacoes = round(somas_das_notas/quantidade_de_notas,1)

        return media_avaliacoes
