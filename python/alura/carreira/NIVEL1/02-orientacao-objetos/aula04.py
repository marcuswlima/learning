# ==================================================
# Bibliotecas/Importações
# ==================================================
from util.utilitarios import imprimir_titulo
from modelos.livro import Livro

# ==================================================
# globais
# ==================================================
livro1 = Livro("Aprendendo Python", "John Doe", 2022)
livro2 = Livro("Data Science Fundamentals", "Jane Smith", 2020)
livro3 = Livro("Python Cookbook", "Samuel Developer", 2019)
livro4 = Livro(in_titulo='Primo Basilio',in_autor='Eça de Queiroz',in_ano_publicaco=1874)
livro5 = Livro(in_titulo='O Tempo e o Vento',in_autor='Erico Verissimo',in_ano_publicaco=2022)

# ==================================================
# main()
# ==================================================
def main():
    pass
    imprimir_titulo('Aula04')
    print(help(Livro))

    Livro.listar_livros()
    print()

    
    # 4) Adicione um método estático chamado verificar_disponibilidade à classe 
    # Livro que recebe um ano como parâmetro e retorna uma lista dos livros disponíveis 
    # publicados nesse ano.
    l2022=Livro.verificar_disponibilidade(2022)
    for livro in l2022:
        print(livro)
    print()

    # 6) No arquivo biblioteca.py, empreste o livro chamando o método emprestar e 
    # imprima se o livro está disponível ou não após o empréstimo.
    livro5.emprestar()
    Livro.listar_livros()
    print()


if __name__ == '__main__':
    main()