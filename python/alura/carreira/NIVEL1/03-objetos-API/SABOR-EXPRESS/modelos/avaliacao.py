"""Avaliação feita por um cliente a um restaurante."""


class Avaliacao:
    """Nota atribuída por um cliente a um restaurante.

    As instâncias são criadas por ``Restaurante.receber_avaliacao()``, que
    valida a nota antes de registrá-la.

    Attributes:
        _cliente: Nome do cliente que fez a avaliação.
        _nota: Nota atribuída pelo cliente.
    """

    def __init__(self, cliente, nota):
        """Cria uma avaliação.

        Args:
            cliente: Nome do cliente que fez a avaliação.
            nota: Nota atribuída ao restaurante.
        """
        self._cliente = cliente
        self._nota = nota
