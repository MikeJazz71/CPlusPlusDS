
#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 3.

//	Class Implementation.

#include "../Headers/UnsortedType.h"

//	Constructors.
UnsortedType::UnsortedType(void)
{
	length = 0;
	currentPosition = 0; 
}

//	Transformers.
void UnsortedType::makeEmpty(void)
{
	length = 0;
	currentPosition = 0; 
}
void UnsortedType::putItem(ItemType item)
{
	info[length] = item;
	length++; 
	
}
void UnsortedType::deleteItem(ItemType item)
{

	int location = 0;
	bool moreToSearch = location < length;

	while (item.comparedTo(location) != EQUAL)
	{
		info[location] = info[length - 1];
		length--; 

	}

}
//	Observers.
bool UnsortedType::isFull(void) const
{
	return (length == MAX_ITEMS); 
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
	currentPosition = 0;
	found = false;
	
	int location = 0;
	bool moreToSearch = location < length;

	while (moreToSearch && !found)
	{
		switch (item.comparedTo((location)))
		{
		case LESS:

		case GREATER: moreToSearch = location++ < length;
			break;

		case EQUAL: found = true;

			
			
			
			
		}
		
	}

	return item; 

	
	
}
ItemType UnsortedType::getNextItem(void)
{
	return info[currentPosition++]; 
}

#endif //UNSORTEDTYPE_CPP