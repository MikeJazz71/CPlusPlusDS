
#ifndef QUETYPE_CPP
#define QUETYPE_CPP

//	C++ Plus Data Structures, Chapter 5.

//	Class Implementation.

#include <iostream>

#include "../Headers/QueType.h"

QueType::QueType(void)
{
    frontPtr = rearPtr = NULL;
}
QueType::~QueType()
{
    MakeEmpty();
}

//	Transformers.
void QueType::Enqueue(ItemType newItem)
{
    if (IsFull())
    {
        throw FullQueue();
    }
    NodeType *location = new NodeType;
    location->info = newItem;
    location->nextPtr = NULL;
    if (rearPtr == NULL)
    {
        frontPtr = location;
    }
    else
    {
        rearPtr->nextPtr = location;
    }
    rearPtr = location;
}
void QueType::Dequeue(void)
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    NodeType *tempPtr = frontPtr;
    frontPtr = frontPtr->nextPtr;
    if (frontPtr == NULL)
    {
        rearPtr = NULL;
    }
    delete tempPtr;
}
void QueType::MakeEmpty(void)
{
    while (frontPtr != NULL)
    {
        NodeType *tempPtr = frontPtr;
        frontPtr = frontPtr->nextPtr;
        delete tempPtr;
    }
    rearPtr = NULL;
}

//	Observers.
bool QueType::IsFull(void) const
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
    return false;
}
bool QueType::IsEmpty(void) const
{
    return frontPtr == NULL;
}

#endif //QUETYPE_CPP