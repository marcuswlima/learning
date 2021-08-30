#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void paraTela(char caracter) {
    cout << caracter << '\t' << static_cast< int > ( caracter ) << endl;
}

int main()
{
    cout << static_cast< int > ( 'A' ) << "-";
    cout << static_cast< int > ( 'B' ) << "-";
    cout << static_cast< int > ( 'C' ) << "-";

    cout << static_cast< int > ( 'a' ) << "-";
    cout << static_cast< int > ( 'b' ) << "-";
    cout << static_cast< int > ( 'c' ) << "-";

    cout << static_cast< int > ( '0' ) << "-";
    cout << static_cast< int > ( '1' ) << "-";
    cout << static_cast< int > ( '2' ) << "-";

    cout << static_cast< int > ( '$' ) << "-";
    cout << static_cast< int > ( '*' ) << "-";
    cout << static_cast< int > ( '+' ) << "-";
    cout << static_cast< int > ( '/' ) << "-";
    cout << static_cast< int > ( ' ' ) << "-";

    cout << endl << endl;

    char caracter;

    caracter = 'A';
    cout << caracter << '\t' << static_cast< int > ( caracter ) << endl;
    caracter = 'B';
    cout << caracter << '\t' << static_cast< int > ( caracter ) << endl;
    caracter = 'C';
    cout << caracter << '\t' << static_cast< int > ( caracter ) << endl;
    caracter = 'a';
    cout << caracter << '\t' << static_cast< int > ( caracter ) << endl;

    cout << endl << endl;


    paraTela ('A');
    paraTela ('B');
    paraTela ('C');
    paraTela ('a');
    paraTela ('b');
    paraTela ('c');
    paraTela ('0');
    paraTela ('1');
    paraTela ('2');
    paraTela ('$');
    paraTela ('*');
    paraTela ('+');
    paraTela ('/');
    paraTela (' ');
    cout << endl;



    return 0;
}

