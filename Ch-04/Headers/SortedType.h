
#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

//	C++ Plus Data Structures, Chapter 4.

//	Class Specification.

#include "../../ItemType.cpp"

class SortedType
{

public:
	//	Constructors.
	SortedType(void);
	SortedType(int);
	virtual ~SortedType();

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
	int maxList;
	ItemType *info;
	int currentPosition;
	
};

#endif //SORTEDTYPE_H