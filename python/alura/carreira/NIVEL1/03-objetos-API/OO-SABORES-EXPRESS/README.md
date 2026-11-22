# OO Sabores Express

Projeto de estudo (Alura – Carreira Python, Nível 1) que trabalha com consumo e criação de APIs em Python:

- **`app.py`**: consome uma API pública de restaurantes e gera um arquivo JSON com o cardápio de cada restaurante.
- **`main.py`**: expõe uma API web com **FastAPI**, servida pelo **Uvicorn**.

---

## Estrutura de pastas

```text
OO-SABORES-EXPRESS/
├── app.py               # Script que consome a API de restaurantes e gera os JSONs
├── main.py              # API FastAPI (endpoint /api/hello)
├── requirements.txt     # Dependências do projeto
├── Burger King.json     # Cardápios gerados por app.py (um arquivo por restaurante)
├── KFC.json
├── McDonald’s.json
├── Pizza Hut.json
├── Taco Bell.json
└── Wendy’s.json
```

---

## Arquitetura

O projeto tem dois componentes independentes:

| Componente | Arquivo | Responsabilidade |
|---|---|---|
| **Cliente de API** | `app.py` | Faz `GET` em `https://guilhermeonrails.github.io/api-restaurantes/restaurantes.json` com `requests`, agrupa os itens por restaurante (`Company`) e grava `<restaurante>.json` com `item`, `price` e `description`. |
| **Servidor de API** | `main.py` | Cria a aplicação `FastAPI` (`app`) e publica as rotas HTTP. |

```mermaid
flowchart LR
    subgraph Cliente["app.py (requests)"]
        A[GET restaurantes.json] --> B[Agrupa por restaurante]
        B --> C[Grava &lt;restaurante&gt;.json]
    end
    EXT[(API pública<br/>api-restaurantes)] --> A

    subgraph Servidor["main.py (FastAPI + Uvicorn)"]
        D["GET /api/hello"]
    end
    U[Navegador / cliente HTTP] --> D
```

### Endpoints

| Método | Rota | Resposta |
|---|---|---|
| `GET` | `/api/hello` | `{"Hello": "World"}` |
| `GET` | `/docs` | Documentação interativa (Swagger UI) gerada pelo FastAPI |
| `GET` | `/redoc` | Documentação alternativa (ReDoc) |

---

## Pacotes necessários

Principais dependências (versões fixadas em [requirements.txt](requirements.txt)):

| Pacote | Uso |
|---|---|
| `fastapi` | Framework para criação da API |
| `uvicorn` | Servidor ASGI que executa a aplicação FastAPI |
| `requests` | Requisições HTTP à API de restaurantes (`app.py`) |
| `pydantic` | Validação de dados (dependência do FastAPI) |
| `starlette` | Base web do FastAPI |

### Instalação

```bash
# Criar e ativar o ambiente virtual
python -m venv .venv
source .venv/bin/activate        # Linux/macOS
# .venv\Scripts\activate         # Windows

# Instalar as dependências
pip install -r requirements.txt
```

---

## Como executar

### Gerar os arquivos JSON dos restaurantes

```bash
python app.py
```

### Iniciar o serviço da API (Uvicorn)

```bash
uvicorn main:app --reload --host=0.0.0.0
```

- `main:app` → módulo `main.py`, objeto `app` (instância do FastAPI).
- `--reload` → reinicia o servidor automaticamente ao alterar o código (uso em desenvolvimento).
- `--host=0.0.0.0` → escuta em todas as interfaces de rede, permitindo acesso a partir de outras máquinas da rede (não apenas `localhost`).

Por padrão o serviço sobe na porta `8000` (altere com `--port=<porta>`). Acesse:

- http://localhost:8000/api/hello
- http://localhost:8000/docs
- De outra máquina: `http://<IP-da-máquina>:8000/api/hello`

> Se o acesso externo não funcionar, verifique se a porta 8000 está liberada no firewall (ex.: `sudo firewall-cmd --add-port=8000/tcp` no Fedora).
