"""Prato do cardápio."""

from modelos.cardapio.item_cardapio import ItemCardapio


class Prato(ItemCardapio):
    """Prato servido pelo restaurante, com desconto de 8%.

    Attributes:
        descricao: Descrição do prato.
    """

    def __init__(self, in_nome: str, in_preco: float, in_descricao: str) -> None:
        """Cria um prato.

        Args:
            in_nome: Nome do prato.
            in_preco: Preço do prato, em reais.
            in_descricao: Descrição do prato.
        """
        super().__init__(in_nome=in_nome, in_preco=in_preco)
        self.descricao = in_descricao

    def __str__(self) -> str:
        """Retorna o nome do prato."""
        return self._nome

    def aplicar_desconto(self) -> None:
        """Reduz o preço do prato em 8%."""
        self._preco -= self._preco * 0.08
