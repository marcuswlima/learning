# Carreira Python – Alura

Repositório de estudos da **Carreira Python** da Alura. Os projetos estão organizados em uma trilha progressiva: começa com um programa procedural de terminal, passa por orientação a objetos, consumo e criação de APIs, e chega a redes e protocolos.

O tema que atravessa quase toda a trilha é o **Sabor Express**, um app fictício de gestão de restaurantes que vai sendo reescrito a cada etapa com as técnicas novas.

---

## Sumário

- [Estrutura de pastas](#estrutura-de-pastas)
- [Trilha de estudos](#trilha-de-estudos)
- [Conceitos praticados](#conceitos-praticados)
- [Tecnologias](#tecnologias)
- [Como executar](#como-executar)
- [Pontos de atenção](#pontos-de-atenção)

---

## Estrutura de pastas

```text
carreira/
├── base/
│   └── 00-primera-aplicacao/       # Sabor Express procedural (menu no terminal)
└── NIVEL1/
    ├── 02-orientacao-objetos/      # Classes, properties, métodos de classe/estáticos
    │   ├── app.py                  # Demonstração de Restaurante + Avaliacao
    │   ├── aula01.py               # Primeira versão da classe Restaurante
    │   ├── aula04.py               # Exercícios com a classe Livro
    │   ├── modelos/                # Avaliacao, Carro, ContaBancaria, Livro, Musica, Pessoa, Restaurante
    │   └── util/utilitarios.py     # Funções utilitárias (geração de dados, validação de entrada)
    ├── 03-objetos-API/
    │   ├── SABOR-EXPRESS/          # Sabor Express OO com cardápio (herança e classe abstrata)
    │   ├── OO-SABORES-EXPRESS/     # Consumo de API pública + API própria com FastAPI
    │   ├── VALOR_DO_DOLAR/         # Cotação de moedas via AwesomeAPI
    │   └── VEICULOS/               # Hierarquia Veiculo → Carro / Moto
    └── 04-Redes-e-protocolos/
        └── REDES/                  # DNS e HTTP HEAD com a biblioteca padrão + testes
```

---

## Trilha de estudos

| Etapa | Projeto | O que faz | Doc |
|---|---|---|---|
| **Base** | `00-primera-aplicacao` | Menu de terminal para cadastrar, listar e ativar/desativar restaurantes, guardados numa lista de dicionários. Código procedural, apenas `os` da biblioteca padrão. | — |
| **Nível 1 · 02** | `02-orientacao-objetos` | Primeiros passos em OO: a classe `Restaurante` recebe avaliações (`Avaliacao`) e calcula a média. Há modelos de exercício (`Livro`, `ContaBancaria`, `Pessoa`, `Carro`, `Musica`) e um módulo de utilitários. | — |
| **Nível 1 · 03** | `SABOR-EXPRESS` | Sabor Express em camadas (`modelos/`, `util/`). O cardápio usa a classe abstrata `ItemCardapio`, especializada em `Prato`, `Bebida` e `Sobremesa`. | [README](NIVEL1/03-objetos-API/SABOR-EXPRESS/README.md) |
| | `OO-SABORES-EXPRESS` | `app.py` consome a API pública de restaurantes e grava um JSON por restaurante. `main.py` expõe a API com **FastAPI** (`/api/hello` e `/api/restaurantes?restaurante=...`). | [README](NIVEL1/03-objetos-API/OO-SABORES-EXPRESS/README.md) |
| | `VALOR_DO_DOLAR` | Consulta a AwesomeAPI e mostra a cotação de uma moeda em reais (padrão: USD). | [README](NIVEL1/03-objetos-API/VALOR_DO_DOLAR/README.md) |
| | `VEICULOS` | Hierarquia `Veiculo` → `Carro` / `Moto` com herança, `super()` e sobrescrita de métodos. | [README](NIVEL1/03-objetos-API/VEICULOS/README.md) |
| **Nível 1 · 04** | `REDES` | Modela `Pessoa` e `Site`. O serviço `VerificadorDeSite` resolve o DNS (`socket`) e faz um HTTP HEAD (`urllib`), mostrando status, IP, porta e tempo de resposta. Inclui testes com `unittest`. | [README](NIVEL1/04-Redes-e-protocolos/REDES/README.md) |

```mermaid
flowchart LR
    A[Base<br/>procedural] --> B[Orientação<br/>a objetos]
    B --> C[Objetos e APIs<br/>requests · FastAPI]
    C --> D[Redes e<br/>protocolos]
```

---

## Conceitos praticados

- **Python básico:** funções, listas, dicionários, laços, entrada e saída no terminal.
- **Orientação a objetos:** classes, `__init__`, `__str__`, atributos de classe e de instância, encapsulamento com `_atributo` e `@property`, `@classmethod`, `@staticmethod`.
- **Herança e abstração:** `super()`, sobrescrita de métodos, classes abstratas (`abc`).
- **Organização em módulos:** pacotes `modelos/`, `util/`, `servicos/` e separação entre domínio e infraestrutura.
- **APIs:** consumo com `requests`, tratamento de JSON, criação de endpoints com **FastAPI** + **Uvicorn**.
- **Redes:** resolução DNS, requisições HTTP, códigos de status.
- **Testes:** `unittest` no projeto `REDES`.

---

## Tecnologias

| Item | Uso |
|---|---|
| Python 3 | Linguagem de todos os projetos |
| `requests` | Consumo de APIs (`SABOR-EXPRESS`, `OO-SABORES-EXPRESS`, `VALOR_DO_DOLAR`) |
| `fastapi` + `uvicorn` | API web em `OO-SABORES-EXPRESS` |
| Biblioteca padrão (`socket`, `urllib`, `unittest`, `abc`, `os`, `random`) | `REDES`, `base` e utilitários |

As dependências de cada projeto ficam no `requirements.txt` da própria pasta, com versões fixadas.

---

## Como executar

Cada projeto é independente. Entre na pasta dele, crie um ambiente virtual e instale as dependências, quando houver:

```bash
cd NIVEL1/03-objetos-API/OO-SABORES-EXPRESS
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

Exemplos:

```bash
# Base (sem dependências)
python3 base/00-primera-aplicacao/app.py

# Orientação a objetos (rodar de dentro da pasta, por causa dos imports relativos)
cd NIVEL1/02-orientacao-objetos && python3 app.py

# API FastAPI
cd NIVEL1/03-objetos-API/OO-SABORES-EXPRESS && uvicorn main:app --reload
# depois: http://127.0.0.1:8000/docs

# Cotação
cd NIVEL1/03-objetos-API/VALOR_DO_DOLAR && python3 leitura_api.py EUR

# Redes + testes
cd NIVEL1/04-Redes-e-protocolos/REDES && python3 app.py
python3 -m unittest discover tests
```

---

## Pontos de atenção

Achados da análise do código, úteis como próximos passos de estudo:

- **`02-orientacao-objetos/modelos/carro.py`** usa a anotação `Any` sem `from typing import Any`, então importar o módulo gera `NameError`.
- Vários módulos de `02-orientacao-objetos/modelos/` (`carro.py`, `musica.py`, `pessoa.py`) criam objetos ou chamam `help()` no nível do módulo. Isso roda a cada `import`; o ideal é mover para um bloco `if __name__ == "__main__":`.
- **`SABOR-EXPRESS/API/API.py`** só define `dados_json` quando a resposta é `200`, mas o laço seguinte roda sempre. Uma falha na API vira `NameError` em vez de uma mensagem clara.
- Alguns métodos usam `objeto` no lugar de `self` e alguns nomes têm erros de digitação (`_retaurantes`, `in_ano_publicaco`, `is_intiero_par`, `obter_racional_nao_netativo`). Funcionam, mas atrapalham a leitura.
- O menu de `00-primera-aplicacao` volta ao início chamando `main()` de forma recursiva. Em sessões longas isso acumula chamadas na pilha; um laço `while` resolve.
