class Programa:
    def __init__(self, nome, ano):
        self._nome = nome.title()
        self.ano = ano
        self._likes = 0

    @property
    def likes(self):
        return self._likes

    def dar_like(self):
        self._likes += 1

    @property
    def nome(self):
        return self._nome

    def imprime(self):
        print(f'Nome: {self._nome} - Ano: {self.ano} - {self._likes} likes')

    def __str__(self):
        return f'{self._nome} / {self.ano} / {self._likes} Likes'

class Filme(Programa):
    def __init__(self, nome, ano, duracao):
        super().__init__(nome,ano)
        self.duracao = duracao


    def imprime(self):
        print(f'Nome: {self._nome} - Duracao: {self.duracao} mim - Ano: {self.ano} - {self._likes} like(s)')

    def __str__(self):
        return f'{self._nome} / {self.duracao} mim / {self.ano} / {self._likes} Likes'


class Serie(Programa):
    def __init__(self, nome, ano, temporadas):
        super().__init__(nome, ano)
        self.temporadas = temporadas

    def imprime(self):
        print(f'Nome: {self._nome} - Temporadas: {self.temporadas} - Ano: {self.ano} - {self._likes} like(s)')


    def __str__(self):
        return f'{self._nome} / {self.temporadas} temporadas / {self.ano} / {self._likes} Likes'


class Playlist():
    def __init__(self, nome, programas):
        self.nome = nome
        self._programas = programas

    def __getitem__(self, item):
        return self._programas[item]

    def __len__(self):
        return len(self._programas)

vingadores = Filme('Vingadores - guerra infinita',2018,160)
atlanta = Serie('atlanta',2018,2)
tmep = Filme('todo mundo em panico',1999,100)
demolidor = Serie('Demolidor',2016,2)
opc = Filme('o poderoso chefao',1979,200)
twd = Serie('The walkind dead',2010,10)

vingadores.dar_like()
tmep.dar_like()
tmep.dar_like()
tmep.dar_like()
tmep.dar_like()
atlanta.dar_like()
atlanta.dar_like()
atlanta.dar_like()
demolidor.dar_like()
demolidor.dar_like()
opc.dar_like()
opc.dar_like()
twd.dar_like()
twd.dar_like()
twd.dar_like()

filmes_e_series = [vingadores, twd, atlanta, demolidor, tmep, twd]

play_list_fim_de_semana = Playlist('fim de semana',filmes_e_series)

print (f'O tamanho da play_list: {len(play_list_fim_de_semana._programas)}')

for programa in play_list_fim_de_semana:
    print(programa)

