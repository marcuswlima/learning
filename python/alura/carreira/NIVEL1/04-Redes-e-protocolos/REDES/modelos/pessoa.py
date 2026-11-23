"""Modelo que representa uma pessoa que navega na internet."""

import re

from modelos.site import Site

_PADRAO_EMAIL = re.compile(r"^[^@\s]+@[^@\s]+\.[^@\s]+$")


class Pessoa:
    """Uma pessoa com nome, e-mail e uma lista de sites favoritos."""

    def __init__(self, nome: str, email: str) -> None:
        if not nome or not nome.strip():
            raise ValueError("O nome da pessoa não pode ser vazio.")
        if not _PADRAO_EMAIL.match(email or ""):
            raise ValueError(f"E-mail inválido: '{email}'.")
        self._nome = nome.strip()
        self._email = email.strip().lower()
        self._favoritos: list[Site] = []

    @property
    def nome(self) -> str:
        return self._nome

    @property
    def email(self) -> str:
        return self._email

    @property
    def favoritos(self) -> tuple[Site, ...]:
        """Cópia imutável dos favoritos, para proteger o estado interno."""
        return tuple(self._favoritos)

    def favoritar(self, site: Site) -> None:
        if not isinstance(site, Site):
            raise TypeError("Só é possível favoritar objetos do tipo Site.")
        if site in self._favoritos:
            raise ValueError(f"'{site.nome}' já está nos favoritos.")
        self._favoritos.append(site)

    def desfavoritar(self, site: Site) -> None:
        try:
            self._favoritos.remove(site)
        except ValueError:
            raise ValueError(f"'{site.nome}' não está nos favoritos.") from None

    def __str__(self) -> str:
        return f"{self._nome} <{self._email}>"

    def __repr__(self) -> str:
        return f"Pessoa(nome={self._nome!r}, email={self._email!r})"
