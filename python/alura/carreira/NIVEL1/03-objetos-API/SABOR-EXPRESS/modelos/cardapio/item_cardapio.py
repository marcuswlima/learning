"""Classe abstrata base dos itens do cardápio."""

from abc import ABC, abstractmethod


class ItemCardapio(ABC):
    """Item vendável do cardápio de um restaurante.

    Classe abstrata: não pode ser instanciada diretamente. Cada subclasse
    deve implementar ``aplicar_desconto()`` com sua própria política.

    Attributes:
        _nome: Nome do item.
        _preco: Preço do item, em reais.
    """

    def __init__(self, in_nome: str, in_preco: float) -> None:
        """Inicializa os atributos comuns a todo item do cardápio.

        Args:
            in_nome: Nome do item.
            in_preco: Preço do item, em reais.
        """
        self._nome = in_nome
        self._preco = in_preco

    @abstractmethod
    def aplicar_desconto(self) -> None:
        """Aplica o desconto do item, alterando ``_preco`` no próprio objeto."""
