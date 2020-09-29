
#ifndef SORTEDLINKEDTYPE_CPP
#define SORTEDLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 4.

//	Class Implementation.

#include "../Headers/SortedLinkedType.h"

//	Constructors.
SortedLinkedType::SortedLinkedType(void)
{
    listData = NULL;
    length = 0;
    currentPos = NULL;
}
SortedLinkedType::~SortedLinkedType()
{
    makeEmpty();
}

//	Transformers.
void SortedLinkedType::makeEmpty(void)
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
void SortedLinkedType::putItem(ItemType item)
{
    NodeType *predLoc = NULL;
    NodeType *location = listData;
    NodeType *newNode = new NodeType;
    bool moreToSearch = location != NULL;
    newNode->info = item;

    while (moreToSearch)
    {
        switch (item.comparedTo(location->info))
        {
        case LESS:
            moreToSearch = false;
            break;
        case GREATER:
            predLoc = location;
            location = location->next;
            moreToSearch = location != NULL;
        }
    }

    if (predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }

    length++;
}
void SortedLinkedType::deleteItem(ItemType item)
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
bool SortedLinkedType::isFull(void) const
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
int SortedLinkedType::getLength(void) const
{
    return length;
}

//	Iterators.
void SortedLinkedType::resetList(void)
{
    currentPos = NULL;
}
ItemType SortedLinkedType::getItem(ItemType item, bool &found)
{
    NodeType *location = listData;
    bool moreToSearch = location != NULL;
    found = false;
    while (moreToSearch && !found)
    {
        switch (item.comparedTo(location->info))
        {
        case LESS:
            moreToSearch = false;
            break;
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
ItemType SortedLinkedType::getNextItem(void)
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

#endif //SORTEDLINKEDTYPE_CPP