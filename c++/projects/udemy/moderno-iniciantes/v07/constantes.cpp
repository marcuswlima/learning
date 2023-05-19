#include <iostream>
#include <string>
#define HELLO "Hello, constant!"
using namespace std;

int main(){
	const string hello = "Hello constant, again!";

	// Sem código de escapes
	cout << "************************" << endl;
	cout << "01 - Constant Macro HELLO: " << HELLO << endl;
	cout << "01 - Constant literal hello: " << hello << endl;

	// Com com o código de escape \n
	cout << "************************" << endl;
	cout << "02 - Constant Macro HELLO: \n" << HELLO << endl;
	cout << "02 - Constant literal hello: \n" << hello << endl;

	// Com com o código de escape \r
	cout << "************************" << endl;
	cout << "03 - Constant Macro HELLO(com \\r): \r" << HELLO << endl;
	cout << "03 - Constant literal hello(com \\r): \r" << hello << endl;

	// Com com o código de escape \t
	cout << "************************" << endl;
	cout << "04 - Constant Macro HELLO(com \\t): \t" << HELLO << endl;
	cout << "04 - Constant literal hello(com \\t): \t" << hello << endl;

	// Com com o código de escape \v
	cout << "************************" << endl;
	cout << "Constant Macro HELLO(com \\v): \v" << HELLO << endl;
	cout << "Constant literal hello(com \\v): \v" << hello << endl;

	// Com com o código de escape \b
	cout << "************************" << endl;
	cout << "Constant Macro HELLO(com \\b): \b" << HELLO << endl;
	cout << "Constant literal hello(com \\b): \b" << hello << endl;

	// Com com o código de escape \f
	cout << "************************" << endl;
	cout << "Constant Macro HELLO(com \\f): \f" << HELLO << endl;
	cout << "Constant literal hello(com \\f): \f" << hello << endl;

/*
	// Com com o código de escape \a
	cout << "Constant Macro HELLO(com \\a): \a" << HELLO << endl;
	cout << "Constant literal hello(com \\a): \a" << hello << endl;

	// Se atribuírmos um valor para hello ou HELLO, o código não compilará
	// Exemplo: hello = "new hello" , ou HELLO = "New Hello"
*/
	return 0;
}