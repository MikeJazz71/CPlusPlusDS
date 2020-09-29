
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

//	C++ Plus Data Structures, Chapter 3.

//	Class Specification.

#include "../../ItemType.cpp"

const int MAX_ITEMS = 5;

class UnsortedType
{

public:
	//	Constructors.
	UnsortedType(void);

	//	Transformers.
	void makeEmpty(void);
	void putItem(ItemType);
	void deleteItem(ItemType);

	//	Observers.
	bool isFull(void) const;
	int getLength(void) const;

	//	Iterators.
	void resetList(void);
	ItemType getItem(ItemType, bool &);
	ItemType getNextItem(void);

private:
	int length;
	ItemType info[MAX_ITEMS];
	int currentPosition;
	
};

#endif //UNSORTEDTYPE_H