
#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 4.

//	Class Implementation.

#include "../Headers/SortedType.h"

//	Constructors.
SortedType::SortedType(void)
{
	length = 0;
	currentPosition = 0;
	maxList = 500;
	info = new ItemType[500];
	
}
SortedType::SortedType(int size)
{
	length = 0;
	currentPosition = 0;
	maxList = size; 
	info = new ItemType[size]; 
}
SortedType::~SortedType()
{
	delete[] info;
	info = NULL; 
}

//	Transformers.
void SortedType::makeEmpty(void)
{
	length = -1; 
}
void SortedType::putItem(ItemType item)
{

   


	bool moreToSearch;
	int location = 0;
	moreToSearch = currentPosition < length; 

	while (moreToSearch)
	{
		switch (item.comparedTo(info[location]))
		{

		case LESS: location++;
			moreToSearch = (location < length); 
			break;

		case GREATER: moreToSearch = false;
			; 
			
			break; 
			
		}
		

		
	}

	for (int index = length; index > currentPosition; index--)
	{
		info[index] = info[index - 1];

		info[location] = item; 



	}

	length++; 
	
	
}
void SortedType::deleteItem(ItemType item)
{
	
	currentPosition = 0;
	

	while (item.comparedTo(info[currentPosition]) != EQUAL)
	{
		currentPosition++; 

		
	}

	for (int index = currentPosition;  index < length; index++)
	{
		info[index] = info[index + 1];
	   

		
	}

	length--;
}

//	Observers.
bool SortedType::isFull(void) const
{
	return (length == maxList);
}
int SortedType::getLength(void) const
{
	return length; 
}

//	Iterators.
void SortedType::resetList(void)
{
	length = -1; 
}
ItemType SortedType::getItem(ItemType item, bool &found)
{

	int first = 0, last = length - 1, midPoint;
	found = false;
	bool moreToSearch = (first <= last);

	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;
		switch (item.comparedTo(info[midPoint]))
		{
		case LESS: last = midPoint - 1;
			moreToSearch = (first <= last);
			break;
		case GREATER: first = midPoint = +1;
			moreToSearch = (first <= last); 
			break;

		case EQUAL: found = true;
			item = info[midPoint];
			break; 
		

			
		}
	   
	}
	return item;
}
ItemType SortedType::getNextItem(void)
{
	return info[currentPosition++];
}

#endif //SORTEDTYPE_CPP