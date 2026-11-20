from modelos.cardapio.item_cardapio import ItemCardapio

class Prato(ItemCardapio):
    def __init__(self,in_nome:str, in_preco:float, in_descricao:str)->None:
        super().__init__(in_nome=in_nome, in_preco=in_preco)
        self.descricao = in_descricao
    
    def __str__(self)->str:
        return self._nome

    def aplicar_desconto(self) -> None:
        self._preco -= (self._preco * 0.08)    