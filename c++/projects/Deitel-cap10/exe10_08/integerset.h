#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>

class IntegerSet{
	public:
		IntegerSet();
		void unionOfSets(IntegerSet,IntegerSet);
		void printSet()const;
		void insertElement(const int);
		void deleteElement(const int);
		bool getElement(const size_t)const;
	private:
		const int INITIAL_SIZE=10;
		std::vector<bool> numeros;
};
#endif
