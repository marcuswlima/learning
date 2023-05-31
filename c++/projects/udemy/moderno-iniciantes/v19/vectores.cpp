#include <iostream>
#include <vector>
using namespace std;

int main(){

	vector<string> choices={"Shell","C++","Oracle PL/SQL","Java","C#"};
	vector<string>::iterator inicio=choices.begin();
//	choices.pop_back();
	vector<string>::iterator ultimo=choices.end();
	vector<string>::iterator i;

//	cout << *inicio << endl;
//	cout << *ultimo << endl;
	for (const string& i:choices){
		cout << i << endl;
	}
	return 0;
}

