class Avaliacao(object):
    """
    Representa as avaliacos dos clientes

    Utilaza no curso de Paython da Alura

    Atributes
        Cliente: Nome do cliente
        Nota: nota dada pelo cliente
    """
    def __init__(self, in_cliente:str, in_nota:float):
        self._cliente = in_cliente
        self._nota = in_nota

    def __str__(objeto)->str:
        return f'{objeto._cliente} votou {objeto._nota} '
