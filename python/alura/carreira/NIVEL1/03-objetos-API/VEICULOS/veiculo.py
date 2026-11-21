"""Classe base dos veículos vendidos pela loja."""

from abc import ABC, abstractmethod


class Veiculo(ABC):
    """Veículo genérico, com marca, modelo e estado ligado/desligado.

    Serve de base para as especializações ``Carro`` e ``Moto``.

    Attributes:
        marca: Fabricante do veículo.
        modelo: Nome do modelo do veículo.
    """

    def __init__(self, marca: str, modelo: str) -> None:
        """Cria um veículo desligado.

        Args:
            marca: Fabricante do veículo.
            modelo: Nome do modelo do veículo.
        """
        self.marca = marca
        self.modelo = modelo
        self._ligado = False

    def __str__(self) -> str:
        """Retorna a marca, o modelo e o status do veículo em texto legível."""
        status = "ligado" if self._ligado else "desligado"
        return f"Marca: {self.marca}, Modelo: {self.modelo}, Status: {status}"

    @property
    def ligado(self) -> bool:
        """Indica se o veículo está ligado."""
        return self._ligado

    @ligado.setter
    def ligado(self, valor: bool) -> None:
        """Define o estado ligado/desligado do veículo.

        Args:
            valor: ``True`` para ligar o veículo, ``False`` para desligá-lo.

        Raises:
            TypeError: Se ``valor`` não for um ``bool``.
        """
        if not isinstance(valor, bool):
            raise TypeError(f"'ligado' deve ser bool, não {type(valor).__name__}")
        self._ligado = valor

    @abstractmethod
    def ligar(self) -> None:
        """Liga o veículo. Deve ser implementado pelas subclasses."""


#    def desligar(self) -> None:
#        """Desliga o veículo."""
#        self.ligado = False
