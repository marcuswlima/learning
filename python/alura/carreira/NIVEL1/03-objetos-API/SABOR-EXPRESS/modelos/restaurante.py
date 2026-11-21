"""Entidade central do sistema: o restaurante."""

from typing import ClassVar

from modelos.avaliacao import Avaliacao
from modelos.cardapio.item_cardapio import ItemCardapio


class Restaurante:
    """Restaurante com status, avaliações de clientes e cardápio.

    Toda instância criada é registrada automaticamente em
    ``Restaurante.restaurantes``.

    Attributes:
        restaurantes: Lista de todos os restaurantes já criados (atributo de classe).
        _nome: Nome do restaurante, normalizado com ``title()``.
        _categoria: Categoria do restaurante, normalizada com ``upper()``.
        _ativo: Indica se o restaurante está ativo; começa como ``False``.
        _avaliacao: Avaliações recebidas dos clientes.
        _cardapio: Itens do cardápio.
    """

    restaurantes: ClassVar[list["Restaurante"]] = []

    def __init__(self, nome, categoria):
        """Cria um restaurante inativo, sem avaliações e com cardápio vazio.

        Args:
            nome: Nome do restaurante.
            categoria: Categoria do restaurante (ex.: ``"Gourmet"``).
        """
        self._nome = nome.title()
        self._categoria = categoria.upper()
        self._ativo = False
        self._avaliacao = []
        self._cardapio = []
        Restaurante.restaurantes.append(self)

    def __str__(self):
        """Retorna o nome e a categoria do restaurante."""
        return f"{self._nome} | {self._categoria}"

    @classmethod
    def listar_restaurantes(cls):
        """Imprime uma tabela com nome, categoria, média e status de cada restaurante."""
        print(
            f"{'Nome do restaurante'.ljust(25)} | {'Categoria'.ljust(25)} | {'Avaliação'.ljust(25)} |{'Status'}"
        )
        for restaurante in cls.restaurantes:
            print(
                f"{restaurante._nome.ljust(25)} | {restaurante._categoria.ljust(25)} | {str(restaurante.media_avaliacoes).ljust(25)} |{restaurante.ativo}"
            )

    @property
    def ativo(self):
        """Símbolo do status: ``"⌧"`` se ativo, ``"☐"`` se inativo."""
        return "⌧" if self._ativo else "☐"

    def alternar_estado(self):
        """Inverte o status do restaurante (ativo ↔ inativo)."""
        self._ativo = not self._ativo

    def receber_avaliacao(self, cliente, nota):
        """Registra uma avaliação, desde que a nota esteja entre 0 (exclusivo) e 5.

        Notas fora do intervalo são ignoradas sem aviso.

        Args:
            cliente: Nome do cliente que avalia.
            nota: Nota atribuída; aceita se ``0 < nota <= 5``.
        """
        if 0 < nota <= 5:
            avaliacao = Avaliacao(cliente, nota)
            self._avaliacao.append(avaliacao)

    @property
    def media_avaliacoes(self):
        """Média das notas com uma casa decimal, ou ``"-"`` se não houver avaliações."""
        if not self._avaliacao:
            return "-"
        soma_das_notas = sum(avaliacao._nota for avaliacao in self._avaliacao)
        quantidade_de_notas = len(self._avaliacao)
        media = round(soma_das_notas / quantidade_de_notas, 1)
        return media

    def adicionar_bebida_no_cardapio(self, in_bebida) -> None:
        """Adiciona uma bebida ao cardápio, sem validar o tipo.

        Prefira ``adicionar_no_cardapio()``, que aceita qualquer item.

        Args:
            in_bebida: Bebida a adicionar.
        """
        self._cardapio.append(in_bebida)

    def adicionar_prato_no_cardapio(self, in_prato) -> None:
        """Adiciona um prato ao cardápio, sem validar o tipo.

        Prefira ``adicionar_no_cardapio()``, que aceita qualquer item.

        Args:
            in_prato: Prato a adicionar.
        """
        self._cardapio.append(in_prato)

    def adicionar_no_cardapio(self, in_item: ItemCardapio) -> None:
        """Adiciona um item ao cardápio se ele for um ``ItemCardapio``.

        Objetos de outros tipos são ignorados sem aviso.

        Args:
            in_item: Prato, bebida, sobremesa ou outro ``ItemCardapio``.
        """
        if isinstance(in_item, ItemCardapio):
            self._cardapio.append(in_item)

    @property
    def exibir_cardapio(self) -> None:
        """Imprime os itens do cardápio, numerados a partir de 1.

        Itens com ``descricao`` (pratos e sobremesas) mostram a descrição;
        os demais (bebidas) mostram o tamanho.
        """
        print(f"Cardápio do restaurante {self._nome}")
        for i, item in enumerate(self._cardapio, start=1):
            if hasattr(item, "descricao"):
                mensagem_prato = f"{i}.Nome {item._nome} | Preço: R$ {item._preco} | Descricao: {item.descricao}"
                print(mensagem_prato)
            else:
                mensagem_bebida = f"{i}.Nome {item._nome} | Preço: R$ {item._preco} | Tamanho: {item.tamanho}"
                print(mensagem_bebida)
