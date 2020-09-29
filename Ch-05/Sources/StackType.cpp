

#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

//	C++ Plus Data Structures, Chapter 5.

//	Class Implementation.

#include <new>

#include "../Headers/StackType.h"

//	Constructors.
StackType::StackType(void)
{
    topPtr = NULL;
}
StackType::~StackType()
{
    while (topPtr != NULL)
    {
        NodeType *tempPtr = topPtr;
        topPtr = topPtr->nextPtr;
        delete tempPtr;
    }
}

//	Transformers.
void StackType::Push(ItemType newItem)
{
    if (IsFull())
    {
        throw FullStack();
    }
    NodeType *location = new NodeType;
    location->info = newItem;
    location->nextPtr = topPtr;
    topPtr = location;
}
void StackType::Pop(void)
{
    if (IsEmpty())
    {
        throw EmptyStack();
    }
    NodeType *tempPtr = topPtr;
    topPtr = topPtr->nextPtr;
    delete tempPtr;
}

//	Observers.
bool StackType::IsFull(void) const
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
bool StackType::IsEmpty(void) const
{
    return topPtr == NULL;
}

//	Iterators.
ItemType StackType::Top(void) const
{
    if (IsEmpty())
    {
        throw EmptyStack();
    }
    return topPtr->info;
}

#endif //STACKTYPE_CPP