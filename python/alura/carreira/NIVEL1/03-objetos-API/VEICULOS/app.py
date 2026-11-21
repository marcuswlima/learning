"""Ponto de entrada: demonstra a criação e o uso de carros e motos.

Uso:
    python app.py
"""

from carro import Carro
from moto import Moto


def main() -> None:
    """Cria um carro e uma moto, liga cada um e exibe o estado antes e depois."""
    carro1 = Carro("Toyota", "Corolla", 4)

    print(carro1)
    carro1.ligar()
    print(carro1)

    moto1 = Moto("Harley-Davidson", "Street 750", "Esportiva")
    print(moto1)
    moto1.ligar()
    print(moto1)


if __name__ == "__main__":
    main()
