
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
  
}
void QueType::Dequeue(void)
{
   
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