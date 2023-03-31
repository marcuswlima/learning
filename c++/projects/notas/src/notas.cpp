#include "Triade.h"


int menu();
void Notas();
void MenuIntervalos();
void MenuTriades();
void TesteTodosAcordes();
void ChamarMenu();
void Testar22();
Nota n;
/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    //srand( time(0) );

    ImprimirTitulo("Nota Musicais");

	//TesteTodosAcordes();
	//ChamarMenu();
	Testar22();

    cout << endl;
    cout << "*******************" << endl;
	return 0; //indica o fim do programa
}

void ChamarMenu(){
    int opcao=0;
	do{
        opcao=menu();

		switch(opcao){
			case 1:MenuIntervalos();break;
			case 2:MenuTriades();break;
		}
    }while (opcao!=0);

}

/*
void TesteTodosAcordes(){
	Triade tri(n);
	cout << "Maiores"    << "\t\t\t\t" 
	     << "Menores"    << "\t\t\t\t"  
	     << "Aumentados" << "\t\t\t"  
	     << "Diminutos"  
		 << endl;
	for (int i=1;i<=7;i++){
		n.setNota(7,i,0);
		tri.GerarTriade(n,"M");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"m");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"A");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"d");
		tri.ImprimirEmTela();
		cout << endl;
	}
}
*/

/*
void EncontrarQualificacao(int n, int a){
	Intervalo i(3,n,a);
	Nota t;
	}
*/

int menu(){
	int escolha;
    cout << "**********************\n";
    cout << "** 1 - Intervalos   **\n";
    cout << "** 2 - Triades      **\n";
    cout << "** 0 - Sair         **\n";
    cout << "***********************\n";
	escolha=ObterNumeroNaFaixa("Indique qual módulo [1,2,0] -> ",0,2);
    return escolha;
}

void Notas(){	
	cout << endl << endl;
	ImprimirTitulo("Notas Soltas");
	int quantNotas=ObterNumeroNaFaixa("Digite a quantidade[1:30] -> ",1,30);
	cout << endl;
     
	for (int i=1;i<=quantNotas;i++){
		n.RandomizarNota();
		n.ImprimirEmTela();
	}

	cout << endl << endl;
}

void MenuIntervalos(){	
	cout << endl << endl;
	ImprimirTitulo("Intervalos");
    cout << "****************************************\n";
    cout << "** A partir de uma nota aleatória     **\n";
    cout << "** 1) Apresentar um intervalo simples **\n";
    cout << "** 2) Apresentar uma segunda nota     **\n";
    cout << "****************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
	cout << endl;

	Nota n;
	Intervalo inte;

	for (int i=1; i<=quantidade; i++){	
		if (opcao==1){
			n.RandomizarNota();
			n.ImprimirEmTela();
			cout <<  inte.RandomizarDescricao();
		}
		else {
			n.RandomizarNota();
			inte.setN1(n);
			inte.RandomizarSegundaNota();
			inte.ImprimirEmTela();
		}

		cout << " / ";
	}

	cout << endl;
	cout << endl;

}


void MenuTriades(){	
	cout << endl << endl;
	ImprimirTitulo("Triades");
    cout << "****************************************************\n";
    cout << "** A partir de uma nota aleatória                 **\n";
    cout << "** 1) Apresentar um tipo de triade(M,m,A,d)       **\n";
    cout << "** 2) Apresentar uma terça nota e uma quinta nota **\n";
    cout << "****************************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
	cout << endl;

	Nota n;
	Triade t;

	for(int i=1; i<quantidade; i++){

		if (opcao==1){
			n.RandomizarNota();
			n.ImprimirEmTela();
			cout << t.RandomizarTipoTriade();
		}
/*
		else{
			n.Aleatorio();
			t.setN1(n);
			t.RandomizarTriade();
			t.ImprimirEmTela();
		}
*/
		cout << " / ";

	}


	
	cout << endl << endl;
}

void Testar22(){

	Nota n(4,1,0);
	n.ImprimirEmTela();
	Intervalo i(n,n);
	i.ImprimirEmTela();
	Triade t(i,i);
	t.ImprimirEmTela();
	cout << endl;
	t.RandomizarTriade();
	t.ImprimirEmTela();
	cout << endl;

/*


	Nota n1(1,4,0);
	Nota n2(2,3,0);
	Nota n3(3,2,0);
	Nota n4(4,1,0);

	Intervalo i1(n1,n2);
	Intervalo i2(n3,n4);

	Triade t(i1,i2);
	t.ImprimirEmTela();

	Nota n2(4,2,0);
	n2.ImprimirEmTela();
	cout << endl;
	Nota n3(4,9,0);
	n3.ImprimirEmTela();
	cout << endl;
	Nota n4(4,4,0);
	n4.ImprimirEmTela();
	cout << endl;

	Intervalo i(n);
	i.ImprimirEmTela();

	i.setN1(n);
	i.setN2(n);
	Triade t(i);
	t.ImprimirEmTela();

	cout << endl;
*/
}

