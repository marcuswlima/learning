class Livro:
    """
    Representa os livros

    Utilaza no curso de Paython da Alura

    Atributes
        _titulo: titulo do livro
        _autor: autor do livro
        _ano_publicacao: ano de publicação do livro
        _quantidade_paginas : quantidade de paginas do livro
    """

    livros=[]

    def __init__(self, in_titulo:str='', in_autor:str='', in_ano_publicaco:int=0, in_paginas:int=100):
        self._titulo = in_titulo
        self._autor = in_autor
        self._ano_publicaco = in_ano_publicaco
        #self._quantidade_paginas = in_paginas
        self._disponivel=True
        Livro.livros.append(self)


    def __str__(self):
        return f'{self._titulo} | {self._autor} | {self._ano_publicaco} | {self._disponivel}'

    @property
    def titulo(self)->str:
        return self._titulo

    @property
    def autor(self)->str:
        return self._autor

    @property
    def ano_publicaco(self)->int:
        return self._ano_publicaco

    @property
    def disponivel(self)->bool:
        return self._disponivel

    @property
    def titulo_autor(self)->str:
        return f'{self.titulo} por {self.autor}'

    def aumentar_paginas(self, in_quantidade)->None:
        self._quantidade_paginas += in_quantidade

    def emprestar(self)->None:
        if self._disponivel==False:
            print(f'O livro {self._titulo} já está emprestado')
        else:
            self._disponivel=False

    def devolver(self)->None:
        if self._disponivel==True:
            print(f'O livro {self._titulo} não já está emprestado')      
        else:
            self._disponivel=True

    @staticmethod
    def verificar_disponibilidade(ano)->list:
        livros_disponiveis = [livro for livro in Livro.livros if livro.ano_publicaco == ano and livro.disponivel]
        return livros_disponiveis

    @classmethod
    def listar_livros(cls)->None:
        for livro in cls.livros:
            print(livro)

