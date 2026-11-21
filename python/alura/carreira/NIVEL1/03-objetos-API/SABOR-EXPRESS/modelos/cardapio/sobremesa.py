"""Sobremesa do cardápio."""

from modelos.cardapio.item_cardapio import ItemCardapio


class Sobremesa(ItemCardapio):
    """Sobremesa servida pelo restaurante, com desconto de 15%.

    Attributes:
        descricao: Descrição da sobremesa.
        tipo: Tipo da sobremesa (ex.: bolo, sorvete).
        tamanho: Tamanho da porção.
    """

    def __init__(self, nome, preco, descricao, tipo, tamanho) -> None:
        """Cria uma sobremesa.

        Args:
            nome: Nome da sobremesa.
            preco: Preço da sobremesa, em reais.
            descricao: Descrição da sobremesa.
            tipo: Tipo da sobremesa.
            tamanho: Tamanho da porção.
        """
        super().__init__(nome, preco)
        self.descricao = descricao
        self.tipo = tipo
        self.tamanho = tamanho

    def __str__(self) -> str:
        """Retorna o nome da sobremesa."""
        return self._nome

    def aplicar_desconto(self) -> None:
        """Reduz o preço da sobremesa em 15%."""
        self._preco -= self._preco * 0.15
