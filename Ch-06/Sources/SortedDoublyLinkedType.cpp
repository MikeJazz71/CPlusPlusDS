
#ifndef SORTEDDOUBLYLINKEDTYPE_CPP
#define SORTEDDOUBLYLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.


#include <new>

#include "../Headers/SortedDoublyLinkedType.h"

//	Helpers.
void findItem(NodeType* listData, ItemType item, NodeType *&location, bool &found)
{
	bool moreToSearch = true;
	location = listData;
	found = false;

	while (moreToSearch && !found)
	{
		switch (item.comparedTo(location->info))
		{
		case LESS: moreToSearch = false;
			break;
		case EQUAL: found = true;
			break; 
		case GREATER: location = location->next;
			moreToSearch = (location != NULL); 
		
		}
	}
}

//	Constructors.
SortedDoublyLinkedType::SortedDoublyLinkedType(void)
{
   
}
SortedDoublyLinkedType::~SortedDoublyLinkedType()
{
   
}

//	Transformers.
void SortedDoublyLinkedType::makeEmpty(void)
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
		tempPtr = NULL; 
		
	}

	length = 0; 
}
void SortedDoublyLinkedType::putItem(ItemType item)
{
  
}
void SortedDoublyLinkedType::deleteItem(ItemType item)
{
  
}

//	Observers.
bool SortedDoublyLinkedType::isFull(void) const
{
	NodeType *location;

	try
	{
		location = new NodeType; 
	}

	catch (std::bad_alloc exception)
	{
		return true;
		
	}
	delete location;
	location = NULL;
	return false; 
	
}
int SortedDoublyLinkedType::getLength(void) const
{
	return length; 
}

//	Iterators.
void SortedDoublyLinkedType::resetList(void)
{
	currentPos = listData; 
}
ItemType SortedDoublyLinkedType::getItem(ItemType item, bool &found)
{
	
}
ItemType SortedDoublyLinkedType::getNextItem(void)
{
	return (currentPos->next->info); 
}

#endif //SORTEDDOUBLYLINKEDTYPE_CPP