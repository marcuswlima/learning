#include <iostream>

class Hello{
	public:
		void helloworld(){
			std::cout << "Ola, Mundo!" << '\n';
		}
};

int main( int argc, char **argv ){
	Hello *hello;
	hello->helloworld();
	return 0;
}


