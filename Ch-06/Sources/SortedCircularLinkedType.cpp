
#ifndef SORTEDCIRCULARLINKEDTYPE_CPP
#define SORTEDCIRCULARLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.

#include <new>

#include "../Headers/SortedCircularLinkedType.h"
#include "../../ItemType.cpp"

//	Helpers.
template <class ItemType>
void findItem(NodeType<ItemType> *listData,
              ItemType item, NodeType<ItemType> *&location,
              NodeType<ItemType> *&predLoc, bool &found)
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while (moreToSearch && !found)
    {
        switch (item.comparedTo(location->info))
        {
        case LESS:
            moreToSearch = false;
            break;
        case EQUAL:
            found = true;
            break;
        default:
            predLoc = location;
            location = location->next;
            moreToSearch = location != listData->next;
        }
    }
}

//	Constructors.
template <class ItemType>
SortedCircularLinkedType<ItemType>::SortedCircularLinkedType(void)
{
    listData = NULL;
    length = 0;
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
    NodeType<ItemType> *tempPtr;

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
    NodeType<ItemType> *location;
    NodeType<ItemType> *predLoc;
    bool found;

    NodeType<ItemType> *newNode = new NodeType<ItemType>;
    newNode->info = item;

    switch (listData->info.comparedTo(item))
    {
    case LESS:
        findItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;

        if (listData->info.comparedTo(item) == LESS)
        {
            listData = newNode;
        }
        break;
    default:
        listData = newNode;
        newNode->next = newNode;
    }

    length++;
}
template <class ItemType>
void SortedCircularLinkedType<ItemType>::deleteItem(ItemType item)
{
    NodeType<ItemType> *location;
    NodeType<ItemType> *predLoc;
    bool found;

    findItem(listData, item, location, predLoc, found);

    if (predLoc == location)
    {
        listData = NULL;
    }
    else
    {
        predLoc->next = location->next;
        if (location == listData)
        {
            listData = predLoc;
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
    NodeType<ItemType> *location = listData;
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
template <class ItemType>
ItemType SortedCircularLinkedType<ItemType>::getNextItem(void)
{
    return (currentPos = currentPos->next)->info;
}

#endif //SORTEDCIRCULARLINKEDTYPE_CPP