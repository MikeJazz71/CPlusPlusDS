
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

//	C++ Plus Data Structures, Chapter 3.

//	Class Specification.

#include <fstream>

enum RelationType
{
	LESS = -1,
	GREATER,
	EQUAL
};

class ItemType
{

public:
	//	Constructors.
	ItemType(int);
	ItemType(void);

	//	Transformers.
	void initialize(int);

	//	Observers.
	int hash(void) const;
	void print(std::ostream &) const;
	RelationType comparedTo(ItemType) const;

private:
	int idNum;
	int value;
	
};

#endif //ITEMTYPE_H