#include "Triade.h"

//Tecla i3M(Tecla);
//Tecla i3m(Tecla);
Tecla GerarSegundaNota(Tecla, string);
Tecla GerarSegundaNota(Tecla t, int quantidadeNotas, int quantidadeSemitons);

Triade::Triade(Tecla t){
    this->GerarTriade(t,"M"); //maior
}

void Triade::setT1(Tecla t){
    t1 = t;
}

Tecla Triade::getT1(){
    return t1;
}

void Triade::setT3(Tecla t){
    t3 = t;
}

Tecla Triade::getT3(){
    return t3;
}

void Triade::setT5(Tecla t){
    t5 = t;
}

Tecla Triade::getT5(){
    return t5;
}

void Triade::ImprimirEmTela(){
	cout << this->GerarDescricao()<< endl;
}

string Triade::GerarDescricao(){
	string resposta=""; 
    resposta += this->getT1().GerarDescricao()+ " ";
    resposta += this->getT3().GerarDescricao()+ " ";
    resposta += this->getT5().GerarDescricao();
	return resposta;
}

void Triade::GerarTriade(Tecla t, string tipoIntervalo){
    this->setT1(t);

    if (tipoIntervalo=="M"){
        this->setT3(GerarSegundaNota(t,"3M"));
        this->setT5(GerarSegundaNota(this->getT3(),"3m"));
    }else if (tipoIntervalo=="m"){
        this->setT3(GerarSegundaNota(t,"3m"));
        this->setT5(GerarSegundaNota(this->getT3(),"3M"));
    }else if (tipoIntervalo=="d"){
        this->setT3(GerarSegundaNota(t,"3m"));
        this->setT5(GerarSegundaNota(this->getT3(),"3m"));
    }else if (tipoIntervalo=="A"){
        this->setT3(GerarSegundaNota(t,"3M"));
        this->setT5(GerarSegundaNota(this->getT3(),"3M"));
    }

}


int umaoitava[]={0,1,0,2,0,3,4,0,5,0,6,0,7};
int RetornarSubescrito(int n){
    int resposta;
    for (int i=1;i<=12;i++){
        if (umaoitava[i]==n){
            resposta = i;
            break; 
        }
    }
    return resposta;
}


Tecla GerarSegundaNota(Tecla t, string ti){
    int quantidadeNotas, quantidadeSemitons;

    if (ti=="2m"){
        quantidadeNotas=2;
		quantidadeSemitons=1;
    }else if (ti=="2M"){
        quantidadeNotas=2;
		quantidadeSemitons=3;
    }else if (ti=="3m"){
        quantidadeNotas=3;
		quantidadeSemitons=4;
    }else if (ti=="3M"){
        quantidadeNotas=3;
		quantidadeSemitons=5;
    }

    return GerarSegundaNota(t, quantidadeNotas, quantidadeSemitons);

}

Tecla GerarSegundaNota(Tecla t, int quantidadeNotas, int quantidadeSemitons){
	Tecla r;

    r = t.qualRelativa(quantidadeNotas);
    
    // determinar acidente adequado
    int sub1=RetornarSubescrito(t.getNota()); //1
    int sub2=RetornarSubescrito(r.getNota()); //5
    int diffSemiToms = (sub2-sub1+1);
    int a = quantidadeSemitons - diffSemiToms;

	r.setAcidente(a);

	return r;
	
}

/*

Tecla i3m(Tecla t){  //4 semitons
	Tecla r;
	int quantidadeNotas=3,
		quantidadeSemitons=4,
		o = t.getOitava(),
		n = t.getNota(),
		a = t.getAcidente();

	n += (quantidadeNotas-1);
	if (n>7){
		n -= 7;
		o++;
	}

    cout << "n " << n << endl;

    // t.getNota() x n
    int sub1=RetornarSubescrito(t.getNota()); //1
    int sub2=RetornarSubescrito(n);           //5
    int diffSemiToms = (sub2-sub1+1);
    a = quantidadeSemitons - diffSemiToms;

    //cout << "sub1 " << sub1 << endl;
    //cout << "sub2 " << sub2 << endl;
    //cout << "diffSemiToms " << diffSemiToms << endl;

	r.setOitava(o);
	r.setNota(n);
	r.setAcidente(a);

	return r;
	
}
Tecla i3M(Tecla t){
	Tecla r;
	int quantidadeNotas=3,
		quantidadeSemitons=5,
		o = t.getOitava(),
		n = t.getNota(),
		a = t.getAcidente();

    //cout << "n " << n << endl;

	//n += (quantidadeNotas-1);
	if (n>7){
		n -= 7;
		o++;
	}

    // t.getNota() x n
    int sub1=RetornarSubescrito(t.getNota()); //1
    int sub2=RetornarSubescrito(n);           //5
    int diffSemiToms = (sub2-sub1+1);
    a = quantidadeSemitons - diffSemiToms;

    //cout << "sub1 " << sub1 << endl;
    //cout << "sub2 " << sub2 << endl;
    //cout << "diffSemiToms " << diffSemiToms << endl;

	r.setOitava(o);
	r.setNota(n);
	r.setAcidente(a);

	return r;
}
 
Tecla gerar3M_2(Tecla t){
    Tecla r;

    r.setOitava(t.getOitava());
    r.setNota(t.getNota());
    r.setAcidente(t.getAcidente());

    aumentarAlturaEmUmTom_2(r);
    aumentarAlturaEmUmTom_2(r);
    return r;
}

void aumentarAlturaEmUmTom_2(Tecla &t){
    aumentarAlturaEmMeioTom_2(t);
    aumentarAlturaEmMeioTom_2(t);
}


// aumentar a tecla em 1/2 tom
void aumentarAlturaEmMeioTom_2(Tecla &t){

    if (t.getOitava()!=9){

        if (t.getAcidente()==0) {// teclas bancas 
            if (t.getNota() == 3)
                t.setNota(4);
            else if (t.getNota() == 7 ){
                t.setNota(1);
                t.setOitava(t.getOitava()+1);
            }
            else
                t.setAcidente(1);

        }
        else if (t.getAcidente()==1) {// notas sustenidas
            t.setNota(t.getNota()+1);
            t.setAcidente(0);
        }
        else if (t.getAcidente()==-1){

            //cout << "*" << getNota() << "-" << getAcidente() <<"*";
            t.setAcidente(0);
        }
    }
    else
        cout << "Ultima tecla";

}

*/
