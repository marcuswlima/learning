#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;
using std::cin;


int main(){
    srand( time(0) );

    const int linha=2;
    const int coluna=3;
    int t[linha][coluna];

    for (int i=0; i<linha; i++)
        for (int j=0; j<coluna; j++)
            t[i][j] = gerarInteiro(1,1000);
    mostraArr2D(t,linha,coluna);

    cout << "f) ";

    cout << "\n";
    for (int i=0;i<linha; i++)
        cout << "[" << i << ",1]=" << t[i][1] << "\n";

    cout << "g) ";
    int t_g[linha][coluna]={{1,2,3},{4,5,6}};
    t_g[1][2]=0;
    mostraArr2D(t_g,linha,coluna);

    cout << "h) ";
    int t_h[linha][coluna]={{0,0,0},{0,0,0}};
    mostraArr2D(t_h,linha,coluna);

/*
    cout << "j)\n";
    int t_j[linha][coluna];
    for (int i=0; i<linha; i++)
        for (int j=0; j<coluna; j++){
            cout << "[" << i << "," << j << "] -> " ;
            cin >> t_j[i][j];
        }
    mostraArr2D(t_j,linha,coluna);
*/    
    cout << "k)\n";
    int t_k[linha][coluna];
    for (int i=0; i<linha; i++)
        for (int j=0; j<coluna; j++)
            t_k[i][j] = gerarInteiro(1,10);
    mostraArr2D(t_k,linha,coluna);

    int menor=t_k[0][0];
    for (int i=0; i<linha; i++)
        for (int j=0; j<coluna; j++)
            if (t_k[i][j]<menor)
                menor = t_k[i][j];
    cout << "O menor valor é : " << menor << "\n";

    cout << "\neli) ";
    mostarArray(t_k[0],coluna);

    cout << "\nm) ";
    for (int i=0;i<linha; i++)
        cout << "[" << i << ",2]=" << t_k[i][2] << " ";
    cout << "\n";

    cout << "n)\n";
    cout << "\t[0]\t[1]\t[2]\n";
    for (int i=0;i<linha; i++){
        cout << "[" << i << "]\t" ;
        for (int j=0; j<coluna; j++)
            cout << t_k[i][j] << "\t";
        cout << "\n";
    }

    cout << "\n";
    return 0;
}
