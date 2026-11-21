"""Especialização de Veiculo para motos."""

from veiculo import Veiculo


class Moto(Veiculo):
    """Moto, um veículo identificado também pelo seu tipo.

    Attributes:
        tipo: Categoria da moto (por exemplo, "Esportiva" ou "Custom").
    """

    def __init__(self, marca: str, modelo: str, tipo: str) -> None:
        """Cria uma moto desligada.

        Args:
            marca: Fabricante da moto.
            modelo: Nome do modelo da moto.
            tipo: Categoria da moto (por exemplo, "Esportiva" ou "Custom").
        """
        super().__init__(marca, modelo)
        self.tipo = tipo

    def __str__(self) -> str:
        """Retorna a descrição do veículo acrescida do tipo da moto."""
        return f"{super().__str__()} - Tipo: {self.tipo}"
