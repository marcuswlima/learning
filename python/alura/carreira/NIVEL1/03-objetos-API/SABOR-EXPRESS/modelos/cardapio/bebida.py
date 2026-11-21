"""Bebida do cardápio."""

from modelos.cardapio.item_cardapio import ItemCardapio


class Bebida(ItemCardapio):
    """Bebida servida pelo restaurante, com desconto de 5%.

    Attributes:
        tamanho: Tamanho da bebida (ex.: ``"grande"``).
    """

    def __init__(self, in_nome: str, in_preco: float, in_tamanho: str) -> None:
        """Cria uma bebida.

        Args:
            in_nome: Nome da bebida.
            in_preco: Preço da bebida, em reais.
            in_tamanho: Tamanho da bebida.
        """
        super().__init__(in_nome=in_nome, in_preco=in_preco)
        self.tamanho = in_tamanho

    def __str__(self) -> str:
        """Retorna o nome da bebida."""
        return self._nome

    def aplicar_desconto(self) -> None:
        """Reduz o preço da bebida em 5%."""
        self._preco -= self._preco * 0.05
