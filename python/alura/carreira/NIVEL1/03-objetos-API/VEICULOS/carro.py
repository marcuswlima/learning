"""Especialização de Veiculo para carros."""

from veiculo import Veiculo


class Carro(Veiculo):
    """Carro, um veículo identificado também pela quantidade de portas.

    Attributes:
        portas: Quantidade de portas do carro.
        cor: Cor do carro.
    """

    def __init__(self, marca: str, modelo: str, portas: int, cor: str) -> None:
        """Cria um carro desligado.

        Args:
            marca: Fabricante do carro.
            modelo: Nome do modelo do carro.
            portas: Quantidade de portas do carro.
            cor: Cor do carro.
        """
        super().__init__(marca, modelo)
        self.portas = portas
        self.cor = cor

    def __str__(self) -> str:
        """Retorna a descrição do veículo acrescida das portas e da cor."""
        return f"{super().__str__()} - Portas: {self.portas} - Cor: {self.cor}"

    def ligar(self) -> None:
        """Liga o carro."""
        self.ligado = True
