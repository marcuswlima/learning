from abc import ABC, abstractmethod

class ItemCardapio(ABC):
    def __init__(self,in_nome:str, in_preco:float) -> None:
        self._nome = in_nome
        self._preco = in_preco

    @abstractmethod
    def aplicar_desconto(self)->None:
        pass