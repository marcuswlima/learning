#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

int main()
{

    int base=2, expoente = 0, resto, decimal,octal, resultado;
    double potencia;


    for (int numero=1; numero<=100; numero++) {
/*
        if ( numero != 01 && 
             numero != 02 && 
             numero != 04 && 
             numero != 16 &&
             numero != 32 &&
             numero != 64 &&
             numero != 128 &&
             numero != 256 &&
             numero != 512 &&
             numero != 1024 &&
             numero != 2048
           )
            continue;
*/
        cout << "numero -> " << numero << "\t";

        {
            // ****************
            // Binário
            // ****************
            base = 2;
            expoente = 0;

            // encontrar a base 
            while ( numero >= pow(base,expoente) ) {
                ++expoente;
            }
            --expoente;

            decimal = numero;
            // escrever o número binário
            for (int i = expoente; i>=0; --i) {

                potencia = pow (base,i);
                if ( potencia > decimal )
                    cout << "0";
                else {
                    cout << "1";
                    resto = decimal % static_cast< int > (potencia) ;
                    decimal = resto;
                }
            }//escrevendo o binario
        }


        {
            // ****************
            // Octal
            // ****************
            cout << "\t\t\t\t";
            base = 8;
            expoente = 0;
            while ( numero >= pow(base,expoente) ) {
                ++expoente;
            }
            --expoente;

            octal = numero;
            // escrever o número octal
            for (int i = expoente; i>=0; --i) {

                potencia = pow (base,i);

                if ( potencia > octal )
                    cout << "0";
                else {
                    resultado = octal / static_cast< int > (potencia);
                    cout << resultado;
                    resto = octal % static_cast< int > (potencia) ;
                    octal = resto;
                }
            
            }//escrevendo o Octal

        }

        {
            // ****************
            // Hexadecimal
            // ****************
            cout << "\t";
            base = 16;
            expoente = 0;
            while ( numero >= pow(base,expoente) ) {
                ++expoente;
            }
            --expoente;

            octal = numero;
            // escrever o número octal
            for (int i = expoente; i>=0; --i) {

                potencia = pow (base,i);

                if ( potencia > octal )
                    cout << "0";
                else {
                    resultado = octal / static_cast< int > (potencia);

                    switch (resultado) {
                        case 10: cout << "A"; break;
                        case 11: cout << "B"; break;
                        case 12: cout << "C"; break;
                        case 13: cout << "D"; break;
                        case 14: cout << "E"; break;
                        case 15: cout << "F"; break;
                        
                        default:
                            cout << resultado;
                            break;
                    }

                    resto = octal % static_cast< int > (potencia) ;
                    octal = resto;
                }
            
            }//escrevendo o Octal

        }


        cout <<  endl;
    }// para cada numero gerado

//--------------------------------------------
    cout << endl << endl ;

    return 0;
}

