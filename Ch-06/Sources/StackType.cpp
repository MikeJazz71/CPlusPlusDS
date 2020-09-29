
#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.

#include <new>
#include <iostream>

#include "../Headers/StackType.h"

//	Constructors.
template <class ItemType>
StackType<ItemType>::StackType(void)
{
    topPtr = NULL;
}
template <class ItemType>
StackType<ItemType>::~StackType()
{
    while (topPtr != NULL)
    {
        NodeType<ItemType> *tempPtr = topPtr;
        topPtr = topPtr->nextPtr;
        delete tempPtr;
    }
}

//	Transformers.
template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
    {
        throw FullStack();
    }
    NodeType<ItemType> *location = new NodeType<ItemType>;
    location->info = newItem;
    location->nextPtr = topPtr;
    topPtr = location;
}
template <class ItemType>
void StackType<ItemType>::Pop(void)
{
    if (IsEmpty())
    {
        throw EmptyStack();
    }
    NodeType<ItemType> *tempPtr = topPtr;
    topPtr = topPtr->nextPtr;
    delete tempPtr;
}

//	Observers.
template <class ItemType>
bool StackType<ItemType>::IsFull(void) const
{
    NodeType<ItemType> *location;
    try
    {
        location = new NodeType<ItemType>;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
    delete location;
    return false;
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty(void) const
{
    return topPtr == NULL;
}

//	Iterators.
template <class ItemType>
ItemType StackType<ItemType>::Top(void) const
{
    if (IsEmpty())
    {
        throw EmptyStack();
    }
    return topPtr->info;
}

#endif //STACKTYPE_CPP