"""Funções utilitárias genéricas, independentes do domínio do restaurante.

Grupos de funções:

- Geração de dados aleatórios: nomes, inteiros, decimais e tuplas.
- Verificações numéricas: primo, par e inteiro.
- Entrada validada: leitura repetida via ``input()`` até obter um valor válido.
- Diversos: ordenação de dicionário, cálculo de IMC e impressão formatada.
"""

# ==================================================
# Bibliotecas/Importações
# ==================================================
from operator import itemgetter
from random import choice, randint


# ==================================================
# gerar_nome()
# ==================================================
def gerar_nome() -> str:
    """Sorteia um primeiro nome de uma lista fixa.

    Returns:
        Um primeiro nome, ex.: ``"Maria"``.
    """
    NOMES = (
        "Marcus",
        "João",
        "Maria",
        "Ana",
        "Carlos",
        "Pedro",
        "José",
        "Paulo",
        "Luciana",
        "Fernanda",
        "Izabel",
    )

    return choice(NOMES)


# ==================================================
# gerar_sobrenome()
# ==================================================
def gerar_sobrenome() -> str:
    """Sorteia um sobrenome de uma lista fixa.

    Returns:
        Um sobrenome, ex.: ``"Silva"``.
    """
    SOBRENOMES = (
        "Silva",
        "Santos",
        "Oliveira",
        "Souza",
        "Costa",
        "Lima",
        "Pereira",
        "Ferreira",
        "Rodrigues",
        "Almeida",
        "Ramos",
    )

    return choice(SOBRENOMES)


# ==================================================
# gerar_nome_completo()
# ==================================================
def gerar_nome_completo() -> str:
    """Gera um nome completo aleatório (nome + sobrenome).

    Returns:
        Nome e sobrenome separados por espaço.
    """
    return f"{gerar_nome()} {gerar_sobrenome()}"


# ==================================================
# gerar_um_inteiro()
# ==================================================
def gerar_um_inteiro(in_start: int, in_end: int) -> int:
    """Sorteia um inteiro no intervalo fechado ``[in_start, in_end]``.

    Args:
        in_start: Menor valor possível.
        in_end: Maior valor possível.

    Returns:
        O inteiro sorteado.
    """
    return randint(in_start, in_end)


# ==================================================
# gerar_um_decimal()
# ==================================================
def gerar_um_decimal(in_start: float, in_end: float) -> float:
    """Sorteia um número com duas casas decimais no intervalo ``[in_start, in_end]``.

    Args:
        in_start: Menor valor possível.
        in_end: Maior valor possível.

    Returns:
        O número sorteado, com no máximo duas casas decimais.
    """
    decimal = gerar_um_inteiro(in_start=int(in_start * 100), in_end=int(in_end * 100))
    return decimal / 100


# ==================================================
# gerar_tupla_com_inteiros()
# ==================================================
def gerar_tupla_com_inteiros(in_start: int, in_end: int, in_quantidade: int) -> tuple:
    """Gera uma tupla de inteiros sorteados no intervalo ``[in_start, in_end]``.

    Args:
        in_start: Menor valor possível.
        in_end: Maior valor possível.
        in_quantidade: Quantidade de números gerados.

    Returns:
        Tupla com ``in_quantidade`` inteiros (pode haver repetidos).
    """
    inteiros = []
    for i in range(in_quantidade):
        inteiros.append(gerar_um_inteiro(in_start=in_start, in_end=in_end))

    return tuple(inteiros)


# ==================================================
# gerar_tupla_com_decimais()
# ==================================================
def gerar_tupla_com_decimais(
    in_start: float, in_end: float, in_quantidade: int
) -> tuple:
    """Gera uma tupla de números com duas casas decimais no intervalo ``[in_start, in_end]``.

    Args:
        in_start: Menor valor possível.
        in_end: Maior valor possível.
        in_quantidade: Quantidade de números gerados.

    Returns:
        Tupla com ``in_quantidade`` números (pode haver repetidos).
    """
    inteiros = gerar_tupla_com_inteiros(
        in_start=int(in_start * 100),
        in_end=int(in_end * 100),
        in_quantidade=in_quantidade,
    )

    decimais = tuple(x / 100 for x in inteiros)

    return decimais


# ==================================================
# is_inteiro_primo()
# ==================================================
def is_inteiro_primo(numero: int) -> bool:
    """Verifica se um inteiro é primo.

    Args:
        numero: Inteiro a verificar.

    Returns:
        ``True`` se ``numero`` for primo; ``False`` caso contrário (inclusive para ``numero <= 1``).
    """
    eh_primo = True

    if numero <= 1:
        eh_primo = False
    else:
        for i in range(2, numero):
            if numero % i == 0:
                eh_primo = False
                break

    return eh_primo


# ==================================================
# is_intiero_par()
# ==================================================
def is_intiero_par(numero: int) -> bool:
    """Verifica se um inteiro é par.

    Args:
        numero: Inteiro a verificar.

    Returns:
        ``True`` se ``numero`` for par.
    """
    return numero % 2 == 0


# ==================================================
# is_inteiro()
# ==================================================
def is_inteiro(numero: float) -> bool:
    """Verifica se um número não tem parte fracionária.

    Args:
        numero: Número a verificar.

    Returns:
        ``True`` se ``numero`` for inteiro (ex.: ``3.0``).
    """
    return numero % 1 == 0


# ==================================================
# obter_racional()
# ==================================================
def obter_racional(in_mensagem: str) -> float:
    """Lê um número racional do teclado, repetindo até a entrada ser válida.

    Aceita vírgula ou ponto como separador decimal.

    Args:
        in_mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O número informado.
    """
    while True:
        numero_racional = input(in_mensagem + ": ")

        try:
            numero_racional = float(numero_racional.replace(",", "."))
            return numero_racional

        except ValueError:
            print("Erro: o texto informado não representa um numero racional.")


# ==================================================
# obter_racional_positivo()
# ==================================================
def obter_racional_positivo(in_mensagem: str) -> float:
    """Lê um número racional maior ou igual a 1, repetindo até a entrada ser válida.

    Args:
        in_mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O número informado (``>= 1``).
    """
    while True:
        numero_racional = obter_racional(in_mensagem)

        if numero_racional >= 1:
            return numero_racional

        print(
            "Erro: o texto informado não representa um numero racional potivio (n>0)."
        )


# ==================================================
# obter_racional_nao_netativo()
# ==================================================
def obter_racional_nao_netativo(in_mensagem: str) -> float:
    """Lê um número racional não negativo, repetindo até a entrada ser válida.

    Args:
        in_mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O número informado (``>= 0``).
    """
    while True:
        numero_racional = obter_racional(in_mensagem)

        if numero_racional >= 0:
            return numero_racional

        print(
            "Erro: o texto informado não representa um numero racional não negativo (n>=0)."
        )


# ==================================================
# obter_inteiro()
# ==================================================
def obter_inteiro(in_mensagem: str) -> int:
    """Lê um número inteiro do teclado, repetindo até a entrada ser válida.

    Args:
        in_mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O inteiro informado.
    """
    while True:
        caractere = input(in_mensagem + ": ")

        try:
            numero = int(caractere)
            return numero

        except ValueError:
            print("Erro: o texto informado não representa um número inteiro.")


# ==================================================
# obter_inteiro_positivo()
# ==================================================
def obter_inteiro_positivo(mensagem: str) -> int:
    """Lê um inteiro positivo, repetindo até a entrada ser válida.

    Args:
        mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O inteiro informado (``> 0``).
    """
    while True:
        inteiro = obter_inteiro(mensagem)

        if inteiro > 0:
            return inteiro

        print("Erro: o texto digitado não representa um inteiro positivo (n>0).")


# ==================================================
# obter_inteiro_nao_negativo()
# ==================================================
def obter_inteiro_nao_negativo(mensagem: str) -> int:
    """Lê um inteiro não negativo, repetindo até a entrada ser válida.

    Args:
        mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        O inteiro informado (``>= 0``).
    """
    while True:
        numero = obter_inteiro(mensagem)

        if numero >= 0:
            return numero

        print("Erro: o texto digitado não representa um inteiro não negativo (n>=0).")


# ==================================================
# obter_uma_letra()
# ==================================================
def obter_uma_letra(mensagem: str) -> str:
    """Lê uma única letra do teclado, repetindo até a entrada ser válida.

    Args:
        mensagem: Texto exibido ao usuário (seguido de ``": "``).

    Returns:
        A letra informada.
    """
    while True:
        caractere = input(mensagem + ": ")

        if len(caractere) == 1 and caractere.isalpha():
            return caractere

        print("Erro: informe apenas uma letra.")


# ==================================================
# ordernar_dicit_por_valor()
# ==================================================
def ordernar_dicit_por_valor(in_dicio: dict, in_reverse=False):
    """Retorna um novo dicionário ordenado pelos valores.

    Args:
        in_dicio: Dicionário a ordenar (não é alterado).
        in_reverse: Se ``True``, ordena do maior para o menor valor;
            se ``False`` (padrão), do menor para o maior.

    Returns:
        Novo dicionário com as mesmas chaves, na ordem dos valores.
    """
    out_dicio = {}
    for item in sorted(in_dicio.items(), key=itemgetter(1), reverse=in_reverse):
        out_dicio[item[0]] = item[1]

    return out_dicio


# ==================================================
# calcular_imc()
# ==================================================
def calcular_imc(in_peso: float, in_altura: float) -> float:
    """Calcula o Índice de Massa Corporal (IMC).

    Args:
        in_peso: Peso, em quilogramas.
        in_altura: Altura, em metros.

    Returns:
        O IMC (``peso / altura²``).
    """
    return in_peso / (in_altura**2)


# ==================================================
# imprimir_titulo
# ==================================================
def imprimir_titulo(in_mensagem: str) -> None:
    """Imprime um título emoldurado por asteriscos.

    Args:
        in_mensagem: Texto do título.
    """

    def escrever_linha(in_tamanho_texto: int) -> None:
        """Imprime uma linha de asteriscos proporcional ao tamanho do texto."""
        print("***", end="")
        for i in range(in_tamanho_texto):
            print("*", end="")
        print("****")

    escrever_linha(in_tamanho_texto=len(in_mensagem))
    print("**", in_mensagem, "**")
    escrever_linha(in_tamanho_texto=len(in_mensagem))


# ==================================================
# imprime_matriz
# ==================================================
def imprime_matriz(matriz):
    """Imprime uma matriz como tabela, com o índice das linhas e das colunas.

    Args:
        matriz: Lista de listas; as linhas podem ter tamanhos diferentes.
    """

    def transformar_int_to_str(inteiro: int) -> str:
        """Converte o valor em texto alinhado à esquerda com 4 posições."""
        return str(inteiro).ljust(4, " ")

    qtd_colunas = 0
    for linha in matriz:
        tamanho_linha = len(linha)
        qtd_colunas = max(qtd_colunas, tamanho_linha)

    print("|    ", end="")
    for c in range(qtd_colunas):
        print("|", transformar_int_to_str(c), sep="", end="")
    print()
    for i in range(6 + (qtd_colunas * 5)):
        print("-", end="")
    print()

    for l in range(len(matriz)):
        print("|", transformar_int_to_str(l), sep="", end="")
        for c in range(len(matriz[l])):
            print("|", transformar_int_to_str(matriz[l][c]), sep="", end="")
        print()
