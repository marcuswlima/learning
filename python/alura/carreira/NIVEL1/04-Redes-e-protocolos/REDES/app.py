"""Ponto de entrada da aplicação REDES."""

from modelos import Pessoa, Site
from servicos import VerificadorDeSite


def main() -> None:
    pessoa = Pessoa("Marcus", "marcus@exemplo.com")
    for nome, url in [
        ("Python", "https://www.python.org"),
        ("Alura", "https://www.alura.com.br"),
        ("Exemplo HTTP", "http://example.com"),
    ]:
        pessoa.favoritar(Site(nome, url))

    print(f"Favoritos de {pessoa}:\n")
    for site in pessoa.favoritos:
        cadeado = "🔒" if site.seguro else "⚠️ "
        print(
            f"{cadeado} {site.nome}: protocolo={site.protocolo} "
            f"host={site.host} porta={site.porta} caminho={site.caminho}"
        )

    print("\nVerificando acesso:\n")
    verificador = VerificadorDeSite(timeout=5)
    for site in pessoa.favoritos:
        print(verificador.acessar(site))


if __name__ == "__main__":
    main()
