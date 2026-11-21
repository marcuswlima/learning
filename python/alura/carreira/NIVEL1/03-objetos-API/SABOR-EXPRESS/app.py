"""Ponto de entrada da aplicação Sabor Express.

Cria um restaurante, monta um cardápio com uma bebida e um prato (ambos
com desconto aplicado) e exibe o resultado no terminal.
"""

from modelos.cardapio.bebida import Bebida
from modelos.cardapio.prato import Prato
from modelos.restaurante import Restaurante

restaurante_praca = Restaurante("praça", "Gourmet")
bebida_suco = Bebida("Suco Melancia", 5.0, "grande")
bebida_suco.aplicar_desconto()
prato_paozinho = Prato("Paozinho", 2.00, "O melhor da cidade")
prato_paozinho.aplicar_desconto()
restaurante_praca.adicionar_no_cardapio(bebida_suco)
restaurante_praca.adicionar_no_cardapio(prato_paozinho)


def main():
    """Imprime os itens criados e o cardápio do restaurante."""
    print(bebida_suco)
    print(prato_paozinho)
    restaurante_praca.exibir_cardapio  # noqa: B018 (property que imprime o cardápio)


if __name__ == "__main__":
    main()
