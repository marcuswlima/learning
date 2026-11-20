
# ==================================================
# Bibliotecas/Importações
# ==================================================
from util.utilitarios import imprimir_titulo
from modelos.restaurante import Restaurante
from modelos.avaliacao import Avaliacao


# ==================================================
# globais
# ==================================================
restaurante_praca = Restaurante('praça', 'Gourmet')
restaurante_praca.receber_avaliacao(in_cliente='Gui',in_nota=10)
restaurante_praca.receber_avaliacao(in_cliente='Lais',in_nota=8)
restaurante_praca.receber_avaliacao(in_cliente='Emy',in_nota=2)
#restaurante_mexicano = Restaurante('Mexican Food', 'Mexicana')
#restaurante_mexicano.alternar_estado()
#restaurante_japones = Restaurante('Japa', 'Japonesa')

# ==================================================
# main()
# ==================================================
def main():
    help(Restaurante)
    help(Avaliacao)
    imprimir_titulo('Main')
    Restaurante.listar_restaurantes()

if __name__ == '__main__':
    main()