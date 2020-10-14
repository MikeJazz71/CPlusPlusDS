
#ifndef QUETYPE_CPP
#define QUETYPE_CPP

//	C++ Plus Data Structures, Chapter 5.

//	Class Implementation.

#include <iostream>

#include "../Headers/QueType.h"

QueType::QueType(void)
{
	frontPtr = NULL;
	rearPtr = NULL; 
}
QueType::~QueType()
{
	MakeEmpty();
   
}

//	Transformers.
void QueType::Enqueue(ItemType newItem)
{
	if (IsFull())
	

		throw FullQueue(); 

	else
	{

		NodeType* newNode;
		newNode = new NodeType;
		newNode->info = newItem;
		newNode->nextPtr = NULL;

		if (rearPtr == NULL)
			frontPtr = newNode;
		else
			rearPtr->nextPtr = newNode;
		rearPtr = newNode; 
	}
	
}
void QueType::Dequeue(ItemType& item)
{

	if (IsEmpty())
		throw EmptyQueue(); 

	else
	{
		NodeType* tempPtr; 
		tempPtr = frontPtr;
		item = frontPtr->info; 
		frontPtr = frontPtr->nextPtr;

		if (frontPtr == NULL)
			rearPtr = NULL; 
		delete tempPtr; 
		
	}

	
   
}
void QueType::MakeEmpty(void)
{
	NodeType* tempPtr;
	while (frontPtr != NULL)
	{
		tempPtr = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete tempPtr; 
		
	}
}

//	Observers.
bool QueType::IsFull(void) const
{

	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
		
	}
	catch (std::bad_alloc)
	{

		return true; 
	}
}
bool QueType::IsEmpty(void) const
{
	return (frontPtr == NULL); 
}

#endif //QUETYPE_CPP