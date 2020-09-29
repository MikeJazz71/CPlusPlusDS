
#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 3.

//	Class Implementation.

#include "../Headers/UnsortedType.h"

//	Constructors.
UnsortedType::UnsortedType(void)
{
	currentPosition = 0;
	length = 0;
}

//	Transformers.
void UnsortedType::makeEmpty(void)
{
	length = 0;
}
void UnsortedType::putItem(ItemType item)
{
	info[length++] = item;
}
void UnsortedType::deleteItem(ItemType item)
{
	int location = 0;

	while (item.comparedTo(info[location]) != EQUAL)
	{
		location++;
	}
	info[location] = info[length-- - 1];
}

//	Observers.
bool UnsortedType::isFull(void) const
{
	return length == MAX_ITEMS;
}
int UnsortedType::getLength(void) const
{
	return length;
}

//	Iterators.
void UnsortedType::resetList(void)
{
	currentPosition = -1;
}
ItemType UnsortedType::getItem(ItemType item, bool &found)
{
	bool moreToSearch;
	int location = 0;
	found = false;

	moreToSearch = location < length;

	while (moreToSearch && !found)
	{
		switch (item.comparedTo(info[location]))
		{
		case LESS:
		case GREATER:
			moreToSearch = ++location < length;
			break;
		default:
			found = true;
		}
	}
	return item;
}
ItemType UnsortedType::getNextItem(void)
{
	return info[++currentPosition];
}

#endif //UNSORTEDTYPE_CPP