#include "project.h"

void _help(){
	std::cout << "Uso: ./a.out [--parametros] [numero]\n"
		" -- dec2bin: conversao de decimal para binario\n"
		" -- bin2dec: conversao de binario para decimal\n";
}//_help

void dec2bin( int number ){
	int binary_arr[32], i = {0};

	while( number > 0 ){
		binary_arr[i] = number % 2;
		number = number / 2;
		i++;
	}

	for( int k = i-1; k >= 0; k-- ){
		std::cout << binary_arr[k];
	}
	std::cout << '\n';


}//dec2bin

int bin2dec( int number ){

	int ultimo_digito = {0}, num_dec = {0}, base = {1};

	while( number ){
		ultimo_digito = number % 10;
		number = number / 10;
		num_dec += ultimo_digito * base;
		base = base * 2;
	}
	return num_dec;
}bin2dec

bool check_number( char *x ){
	bool t = {true};
	for( int i = 0; i < strlen( x ); i++){
		if( isdigit( x[i] == false ) ){
			t = false;
			break;
		}
	}

	return t;

}//check_number

void _start(int argc, char ** argv){

	if( argc > 2 ){
		std::string param  = argv[1];
		int number = {0}; 

		if( !check_number( argv[2] )) {
			_help();
			return;
		}

		number = std::stoi( argv[2] );

		if      ( param == "--dec2bin" || param == "-b"){
			dec2bin( number );
		}else if( param == "--bin2dec" || param == "-d" ){
			std::cout << bin2dec( number ) << '\n';
		}else{
			_help();
		}
	}else{
		_help();
	}
}//_start

