
#ifndef UNSORTEDLINKEDTYPE_CPP
#define UNSORTEDLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 3.

//	Class Implementation.

#include "../Headers/UnsortedLinkedType.h"

//	Constructors.
UnsortedLinkedType::UnsortedLinkedType(void)
{
    listData = NULL;
    length = 0;
    currentPos = NULL;
}
UnsortedLinkedType::~UnsortedLinkedType()
{
    makeEmpty();
}

//	Transformers.
void UnsortedLinkedType::makeEmpty(void)
{
    NodeType *tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
        tempPtr = NULL;
    }
    length = 0;
}
void UnsortedLinkedType::putItem(ItemType item)
{
    NodeType *location = new NodeType;

    location->info = item;
    location->next = listData;
    listData = location;

    length++;
}
void UnsortedLinkedType::deleteItem(ItemType item)
{
    NodeType *location = listData;
    NodeType *tempLocation;

    if (item.comparedTo(listData->info) == EQUAL)
    {
        tempLocation = listData;
        listData = listData->next;
    }
    else
    {
        while (item.comparedTo((location->next)->info) != EQUAL)
        {
            location = location->next;
        }
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    tempLocation = NULL;
    length--;
}

//	Observers.
bool UnsortedLinkedType::isFull(void) const
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
int UnsortedLinkedType::getLength(void) const
{
    return length;
}

//	Iterators.
void UnsortedLinkedType::resetList(void)
{
    currentPos = NULL;
}
ItemType UnsortedLinkedType::getItem(ItemType item, bool &found)
{
    NodeType *location = listData;
    bool moreToSearch = location != NULL;
    found = false;
    while (moreToSearch && !found)
    {
        switch (item.comparedTo(location->info))
        {
        case LESS:
        case GREATER:
            location = location->next;
            moreToSearch = location != NULL;
            break;
        default:
            found = true;
        }
    }
    return item;
}
ItemType UnsortedLinkedType::getNextItem(void)
{
    if (currentPos == NULL)
    {
        currentPos = listData;
    }
    else
    {
        currentPos = currentPos->next;
    }
    return currentPos->info;
}

#endif //UNSORTEDLINKEDTYPE_CPP