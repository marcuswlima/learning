class Veiculo(object):
    def __init__(self, in_marca, in_modelo):
        self.marca = in_marca
        self.modelo = in_modelo
        self._ligado = False

    def __str__(self):
       status = "ligado" if self._ligado else "desligado"
       return f'{self.marca} - {self.modelo} - {status}'
    
    def ligar(self) -> None:
        self._ligado = True

    def desligar(self) -> None:
        self._ligado = False
