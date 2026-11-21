"""Classe base dos veículos vendidos pela loja."""


class Veiculo:
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

    @property
    def ligado(self) -> bool:
        """Indica se o veículo está ligado."""
        return self._ligado

    def __str__(self) -> str:
        """Retorna a marca, o modelo e o status do veículo em texto legível."""
        status = "ligado" if self.ligado else "desligado"
        return f"Marca: {self.marca}, Modelo: {self.modelo}, Status: {status}"

    def ligar(self) -> None:
        """Liga o veículo."""
        self._ligado = True

    def desligar(self) -> None:
        """Desliga o veículo."""
        self._ligado = False
