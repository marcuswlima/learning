"""Modelo que representa um site na internet."""

from urllib.parse import urlparse

PROTOCOLOS_SUPORTADOS = ("http", "https")
PORTAS_PADRAO = {"http": 80, "https": 443}


class Site:
    """Um site identificado por nome e URL.

    A URL é validada na criação e decomposta em protocolo, host, porta e caminho,
    conceitos básicos de redes e protocolos.
    """

    def __init__(self, nome: str, url: str) -> None:
        if not nome or not nome.strip():
            raise ValueError("O nome do site não pode ser vazio.")
        self._nome = nome.strip()
        self._url = self._validar_url(url)

    @staticmethod
    def _validar_url(url: str) -> str:
        partes = urlparse(url.strip())
        if partes.scheme not in PROTOCOLOS_SUPORTADOS:
            raise ValueError(
                f"Protocolo inválido em '{url}'. Use: {', '.join(PROTOCOLOS_SUPORTADOS)}."
            )
        if not partes.hostname:
            raise ValueError(f"URL sem host: '{url}'.")
        return url.strip()

    @property
    def nome(self) -> str:
        return self._nome

    @property
    def url(self) -> str:
        return self._url

    @property
    def protocolo(self) -> str:
        return urlparse(self._url).scheme

    @property
    def host(self) -> str:
        return urlparse(self._url).hostname or ""

    @property
    def porta(self) -> int:
        partes = urlparse(self._url)
        return partes.port or PORTAS_PADRAO[partes.scheme]

    @property
    def caminho(self) -> str:
        return urlparse(self._url).path or "/"

    @property
    def seguro(self) -> bool:
        """Indica se o site usa HTTPS (tráfego criptografado com TLS)."""
        return self.protocolo == "https"

    def __eq__(self, outro: object) -> bool:
        if not isinstance(outro, Site):
            return NotImplemented
        return self._url == outro._url

    def __hash__(self) -> int:
        return hash(self._url)

    def __str__(self) -> str:
        return f"{self._nome} ({self._url})"

    def __repr__(self) -> str:
        return f"Site(nome={self._nome!r}, url={self._url!r})"
