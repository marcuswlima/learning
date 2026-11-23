import unittest

from modelos import Pessoa, Site


class TestSite(unittest.TestCase):
    def test_decompoe_url(self):
        site = Site("Python", "https://www.python.org/downloads")
        self.assertEqual(site.protocolo, "https")
        self.assertEqual(site.host, "www.python.org")
        self.assertEqual(site.porta, 443)
        self.assertEqual(site.caminho, "/downloads")
        self.assertTrue(site.seguro)

    def test_porta_explicita_e_http(self):
        site = Site("Local", "http://localhost:8000")
        self.assertEqual(site.porta, 8000)
        self.assertFalse(site.seguro)

    def test_rejeita_protocolo_invalido(self):
        with self.assertRaises(ValueError):
            Site("FTP", "ftp://arquivos.com")

    def test_rejeita_nome_vazio(self):
        with self.assertRaises(ValueError):
            Site("  ", "https://a.com")


class TestPessoa(unittest.TestCase):
    def setUp(self):
        self.pessoa = Pessoa("Ana", "Ana@Exemplo.com")
        self.site = Site("Python", "https://www.python.org")

    def test_normaliza_email(self):
        self.assertEqual(self.pessoa.email, "ana@exemplo.com")

    def test_rejeita_email_invalido(self):
        with self.assertRaises(ValueError):
            Pessoa("Ana", "sem-arroba")

    def test_favoritar_e_desfavoritar(self):
        self.pessoa.favoritar(self.site)
        self.assertIn(self.site, self.pessoa.favoritos)
        self.pessoa.desfavoritar(self.site)
        self.assertEqual(self.pessoa.favoritos, ())

    def test_nao_duplica_favorito(self):
        self.pessoa.favoritar(self.site)
        with self.assertRaises(ValueError):
            self.pessoa.favoritar(Site("Outro nome", "https://www.python.org"))

    def test_favoritos_e_imutavel(self):
        self.assertIsInstance(self.pessoa.favoritos, tuple)


if __name__ == "__main__":
    unittest.main()
