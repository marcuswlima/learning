import sys

import requests

URL_BASE = "https://economia.awesomeapi.com.br/last"
TIMEOUT_SEGUNDOS = 10


def obter_cotacao(moeda: str = "USD", moeda_destino: str = "BRL") -> float:
    """Retorna a cotação de compra (bid) de `moeda` em `moeda_destino`.

    Lança requests.RequestException em falhas de rede ou status HTTP de erro.
    """
    moeda = moeda.upper()
    moeda_destino = moeda_destino.upper()

    response = requests.get(
        f"{URL_BASE}/{moeda}-{moeda_destino}", timeout=TIMEOUT_SEGUNDOS
    )
    response.raise_for_status()

    data = response.json()
    return float(data[f"{moeda}{moeda_destino}"]["bid"])


def main() -> int:
    moeda = sys.argv[1] if len(sys.argv) > 1 else "USD"
    moeda_destino = sys.argv[2] if len(sys.argv) > 2 else "BRL"

    try:
        cotacao = obter_cotacao(moeda, moeda_destino)
    except requests.HTTPError as erro:
        print(f"A requisição falhou com o código de status {erro.response.status_code}")
        return 1
    except requests.Timeout:
        print(f"A API não respondeu em {TIMEOUT_SEGUNDOS} segundos.")
        return 1
    except requests.RequestException as erro:
        print(f"Erro de conexão com a API: {erro}")
        return 1
    except (KeyError, ValueError):
        print("A resposta da API veio em um formato inesperado.")
        return 1

    print(f"1 {moeda.upper()} corresponde a {cotacao:.2f} {moeda_destino.upper()}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
