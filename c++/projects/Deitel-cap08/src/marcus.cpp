#include <iostream>

int main() {
	char color[]="1234";
	const char *colorPrt="blue";

	std::string color2[]={"blue"};
	std::string *prtString=color2;
	prtString = color2;

	std::cout << prtString << '\n';
	std::cout << *prtString << '\n';
	std::cout << &color2 << '\n';

	char word[2];
	std::cin >> word;
	std::cout << word;

	return 0;
}

