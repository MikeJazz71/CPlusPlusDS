
#ifndef SETTYPE_CPP
#define SETTYPE_CPP

//	C++ Plus Data Structures, Chapter 11.

//	Class Implementation.

#include <new>
#include "../Headers/SetType.h"

//	Constructors.
SetType::SetType(void)
{
    maxItems = 100;
    items = new ItemType[100];
}
SetType::SetType(int max)
{
    maxItems = max;
    items = new ItemType[max];
}
SetType::~SetType()
{
    delete[] items;
}

//	Transformers.
void SetType::MakeEmpty(void)
{
    delete[] items;
    maxItems = 0;
}
void SetType::PutItem(ItemType item)
{
    //Like LinkedList
}
void SetType::DeleteItem(ItemType item)
{
    //Like LinkedList
}

//	Observers.
bool SetType::IsFull(void) const
{
    ItemType *location;

    try
    {
        location = new ItemType;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }

    delete location;
    location = NULL;
    return false;
}
bool SetType::IsEmpty(void) const
{
    return maxItems == 0;
}

//	Iterators.
int SetType::Cardinality(void)
{
    int count = 0;
    for (int i = 0; i < maxItems; i++)
    {
        if (items[i])
        {
            count++;
        }
    }
    return count;
}
SetType SetType::Union(SetType setB)
{
    //  this + setB note without repetation.
}
SetType SetType::Difference(SetType setB)
{
    //  this - setB
}
SetType SetType::Intersection(SetType setB)
{
    //  this & setB
}

#endif //SETTYPE_CPP