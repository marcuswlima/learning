#include "../../lib/ConsolidatorSystemLib.h"

class Janela {
	private:
		WINDOW *janela;
	public:
		Janela(int, int, int , int);
		void Centralizar(string);
		void Limpar();
		void Imprimir(int, int, string);
};
