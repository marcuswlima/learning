#include <vector>

#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet{
public:
	IntegerSet();
	void unionOfSets(const IntegerSet &,const IntegerSet &);
	static bool isEqual(const IntegerSet &,const IntegerSet &);
	void intersectionOfSets(const IntegerSet &,const IntegerSet &);
	void printSet()const;
	void insertElement(const size_t);
	void deleteElement(const size_t);
	bool getElement(const size_t)const;
private:
	const int INITIAL_SIZE=10;
	std::vector<bool> numeros;
};
#endif
