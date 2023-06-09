#include "../../lib/ConsolidatorSystemLib.h"

class Janela {
	private:
		WINDOW *janela;
	public:
		Janela();
		Janela(int, int, int , int);
		void Instanciar(int, int, int , int);
		void Centralizar(string);
		void Limpar();
		void Imprimir(int, int, string);
		void Imprimir(string);
		string CapturarPalavra(int);
};
