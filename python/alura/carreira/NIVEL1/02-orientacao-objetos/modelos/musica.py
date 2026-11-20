class Musica(object):
    """
    Aprender a criar classes no Python
    """
    nome=''
    artista=''
    duracao=0.0
    musicas=[]
    def __init__(self,nome:str='', artista:str='', duracao:float=0)->None:
#        """
#        Iniciando objeto
#        """
        self.nome = nome
        self.artista = artista
        self.duracao = duracao
        Musica.musicas.append(self)

    def __str__(self):
#        """
#        Apresentaçao do objeto na tela
#        """
        return f'Música: {self.nome} - Artista: {self.artista} - {self.duracao} segundos'

    def listar_musicas()->None:
        for musica in Musica.musicas:
            print(musica)

musica1 = Musica('Bohemian Rhapsody','Queen',355 )
musica2 = Musica('Imagine','John Lennon', 183)
musica3 = Musica('Shape of You', 'Ed Sheeran', 234)


print(musica1)
print(musica2)
print(musica3)
Musica.listar_musicas()

print(help(musica1))
print(help(Musica))
