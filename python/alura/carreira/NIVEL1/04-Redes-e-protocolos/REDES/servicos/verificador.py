"""Serviço que acessa sites pela rede usando HTTP.

Fica separado dos modelos para que Pessoa e Site não dependam de rede
(regra de negócio isolada da infraestrutura) e para facilitar os testes.
"""

import socket
import time
import urllib.error
import urllib.request
from dataclasses import dataclass

from modelos.site import Site


@dataclass(frozen=True)
class ResultadoAcesso:
    site: Site
    online: bool
    status_http: int | None
    ip: str | None
    tempo_ms: float | None
    erro: str | None = None

    def __str__(self) -> str:
        if not self.online:
            return f"[OFFLINE] {self.site.nome}: {self.erro}"
        return (
            f"[{self.status_http}] {self.site.nome} -> {self.ip}:{self.site.porta} "
            f"({self.tempo_ms:.0f} ms)"
        )


class VerificadorDeSite:
    """Resolve o DNS do site e faz uma requisição HTTP HEAD."""

    def __init__(self, timeout: float = 5.0) -> None:
        self._timeout = timeout

    def resolver_ip(self, site: Site) -> str:
        return socket.gethostbyname(site.host)

    def acessar(self, site: Site) -> ResultadoAcesso:
        try:
            ip = self.resolver_ip(site)
            requisicao = urllib.request.Request(
                site.url, method="HEAD", headers={"User-Agent": "REDES/1.0"}
            )
            inicio = time.perf_counter()
            with urllib.request.urlopen(requisicao, timeout=self._timeout) as resposta:
                status = resposta.status
            tempo_ms = (time.perf_counter() - inicio) * 1000
            return ResultadoAcesso(site, True, status, ip, tempo_ms)
        except urllib.error.HTTPError as erro:
            # O servidor respondeu, então o site está online, mesmo com erro HTTP.
            return ResultadoAcesso(site, True, erro.code, ip, None, str(erro.reason))
        except (urllib.error.URLError, OSError) as erro:
            return ResultadoAcesso(site, False, None, None, None, str(erro))
