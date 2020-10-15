

#include <complex.h>
#ifndef SORTEDCIRCULARLINKEDTYPE_CPP
#define SORTEDCIRCULARLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.

#include <new>


#include "../../ItemType.cpp"
#include "../Headers/SortedCircularLinkedType.h"

//	Helpers.
template <class ItemType>
void findItem(NodeType<ItemType> *listData,
			  ItemType item, NodeType<ItemType> *&location,
			  NodeType<ItemType> *&predLoc, bool &found)
{
	bool moreToSearch = true;
	location = listData->next;
	found = false;

	while (moreToSearch && !found)
	{

		if (item < location->info)
			moreToSearch = false;
		else if (item == location->info)
			found = true;
		else
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != listData->next); 
			
		}
		
	}
}

//	Constructors.
template <class ItemType>
SortedCircularLinkedType<ItemType>::SortedCircularLinkedType(void)
{
	length = 0;
	listData = NULL;
	currentPos = NULL; 
	
	
}
template <class ItemType>
SortedCircularLinkedType<ItemType>::~SortedCircularLinkedType()
{
	makeEmpty(); 
}

//	Transformers.
template <class ItemType>
void SortedCircularLinkedType<ItemType>::makeEmpty(void)
{
	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
		tempPtr = NULL; 
	}
	length = 0; 
}
template <class ItemType>
void SortedCircularLinkedType<ItemType>::putItem(ItemType item)
{
	NodeType<ItemType>* location;
	NodeType<ItemType>* predLocation;
	bool found;
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode->info = item;

	if (listData !=NULL)
	{

		findItem(listData, item, location, predLocation, found);
		newNode->next = predLocation->next;
		predLocation->next = newNode;

		if (listData->info < item) //Last Item in the List
		{
			listData = newNode; 
		}

		else // Empty List
		{
			listData = newNode;
			newNode->next = newNode; 
		}

		length++; 
	}
}
template <class ItemType>
void SortedCircularLinkedType<ItemType>::deleteItem(ItemType item)
{
	NodeType<ItemType>* location;
	NodeType<ItemType>* preLocation;
	bool found;

	findItem(listData, item, location, preLocation, found);
	if (preLocation == location)
	{
		listData = NULL; 
	}
	else
	{
		preLocation->next = location->next;
		if (location == listData)
		{
			listData = preLocation; 
		}
	}
	delete location;
	location = NULL; 
	length--; 
}

//	Observers.
template <class ItemType>
bool SortedCircularLinkedType<ItemType>::isFull(void) const
{
	NodeType<ItemType>* location;

	try
	{
		location = new NodeType<ItemType>; 
	}
	catch (std::bad_alloc)
	{
		return true; 
	}

	delete location;
	location = NULL;
	return false; 

}
template <class ItemType>
int SortedCircularLinkedType<ItemType>::getLength(void) const
{
	return length; 
}

//	Iterators.
template <class ItemType>
void SortedCircularLinkedType<ItemType>::resetList(void)
{
	currentPos = listData; 
}
template <class ItemType>
ItemType SortedCircularLinkedType<ItemType>::getItem(ItemType item, bool &found)
{
	NodeType<ItemType>* location = listData;
	
	bool moreToSearch = location != NULL;
	found = false; 
	while (moreToSearch && !found)
	{
		switch (item.comparedTo(location->info))
		{
		case RelationType::LESS: moreToSearch = false;
			break;


		case RelationType::GREATER: location = location->next;
			moreToSearch = location != NULL;
			break;

		default:  found = true;

		}

	
	}
	return item; 

}
template <class ItemType>
ItemType SortedCircularLinkedType<ItemType>::getNextItem(void)
{
	return (currentPos->next->info); 
}

#endif //SORTEDCIRCULARLINKEDTYPE_CPP