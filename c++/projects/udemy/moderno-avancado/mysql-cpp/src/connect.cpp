#include <iostream>
#include <mysql.h>

int main(){

	MYSQL * connect;
	connect = mysql_init(NULL);
	if( !connect ){ 
		std::cout << "O Mysql não inicializou" << '\n';
		return 1;
	}

	connect = mysql_real_connect(connect, "localhost", "root", "marcus", "cpp", 0, NULL, 0);
	
	if( connect ){ 
		std::cout << "Conectado com sucesso" << '\n';
	}else{
		std::cout << "Falha ao conectar!!!" << '\n';
	}

	mysql_close( connect );

	return 0;
}

// g++ connect.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o connect
//sudo apt install libmysqlclient-dev

