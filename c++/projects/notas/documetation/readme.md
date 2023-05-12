# Gerador Exercícios

![Modelo](usecase.png)

## Intervalos Simples

- 2m(1), 2M(2)
- 3m(3), 3M(4)
- 4J(5), 5J(7)
- 6m(8), 6M(9)
- 7m(10), 7M(11)
- 8J(12)

## Tríades

- Maior - 3M + 3m
- Menor - 3m + 3M
- Aumentado - 3M + 3M
- Diminuto - 3m + 3m

## Novas Funcionalidades
1. Intervalos Descendentes
1. Tétrades
1. Inversões de Tétrades
1. Campo Harmônico Maior
1. Campo Harmônico Menor (Primitiva, Harmônica e Melódica)
1. Cifras
1. Melhoria na interação; com repecção de resposta, correção e avaliação
1. Opção de Dificuldade
   1. Facil - randomizar notas sem acidentes
   1. medio - randomizar notas com 1 acidente (b ou #)
   1. dificil - randomizar notas com 2 acidente (bb ou *)
1. Intervalos Compostos

# Class Diagram

![Modelo](classDiagram.png)

```                           
                                            ,---------------------------------.
,----------------------------------------.  |Triade                           |
|Nota                                    |  |---------------------------------|
|----------------------------------------|  |Triade();                        |
|Nota();                                 |  |Triade(Intervalo);               |
|Nota(int, int, int );                   |  |Triade(Intervalo, Intervalo);    |
|void setOitava(int);                    |  |void setInt1(Intervalo);         |
|void setGrau(int);                      |  |Intervalo getInt1();             |
|void setAcidente(int);                  |  |void setInt2(Intervalo);         |
|int getOitava();                        |  |Intervalo getInt2();             |
|int getGrau();                          |  |Nota getFundamental();           |
|int getAcidente();                      |  |Nota getTerca();                 |
|void setNota( int, int, int );          |  |Nota getQuinta();                |
|void RandomizarNota();                  |  |void ImprimirEmTela();           |
|Nota qualRelativa(int);                 |  |void ImprimirFundamentalEmTela();|
|string GerarDescricao();                |  |string GerarDescricao();         |
|void ImprimirEmTela();                  |  |string RandomizarTipoTriade();   |
|int oitava;     // 0--8                 |  |void RandomizarTriade();         |
|int grau;       // 1--7                 |  |Intervalo i1;                    |
|int acidente;   // [-2,0,2] [bb,b,0,#,*]|  |Intervalo i2;                    |
`----------------------------------------'  `---------------------------------'
                                                                               
                                                                               
                      ,------------------------------------.                   
                      |Intervalo                           |                   
                      |------------------------------------|                   
                      |Intervalo();                        |                   
                      |Intervalo(Nota);                    |                   
                      |Intervalo(Nota,Nota);               |                   
                      |void setN1(Nota);                   |                   
                      |void setN2(Nota);                   |                   
                      |void setN2(string);                 |                   
                      |void setN2();                       |                   
                      |void setQtdNotasNaturais(int);      |                   
                      |void setQtdSemiTons(int);           |                   
                      |Nota getN1();                       |                   
                      |Nota getN2();                       |                   
                      |int  getQtdNotasNaturais();         |                   
                      |int  GetQtdSemiTons();              |                   
                      |void SetIntervalo(Nota,Nota);       |                   
                      |void CalcularAtributosSecundarios();|                   
                      |void RandomizarSegundaNota();       |                   
                      |string RandomizarDescricao();       |                   
                      |string GerarDescricao();            |                   
                      |void ImprimirEmTela();              |                   
                      |Nota n1;                            |                   
                      |Nota n2;                            |                   
                      |int qtdNotasNaturais; //[2-7]       |                   
                      |int qtdSemiTons;     //[2-12]       |                   
                      |int orientacao; //[-1 desc, 1 asc]  |                   
                      `------------------------------------'                   
