
#ifndef SORTEDDOUBLYLINKEDTYPE_CPP
#define SORTEDDOUBLYLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.

#include <new>

#include "../Headers/SortedDoublyLinkedType.h"

//	Helpers.
void findItem(NodeType *listData, ItemType item, NodeType *&location, bool &found)
{
    bool moreToSearch = true;

    location = listData->next;
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
            location = location->next;
            moreToSearch = location != NULL;
        }
    }
}

//	Constructors.
SortedDoublyLinkedType::SortedDoublyLinkedType(void)
{
    listData = NULL;
    length = 0;
    currentPos = NULL;
}
SortedDoublyLinkedType::~SortedDoublyLinkedType()
{
    makeEmpty();
}

//	Transformers.
void SortedDoublyLinkedType::makeEmpty(void)
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
void SortedDoublyLinkedType::putItem(ItemType item)
{
    NodeType *location;
    bool found;

    NodeType *newNode = new NodeType;
    newNode->info = item;

    switch (listData->info.comparedTo(item))
    {
    case LESS:
        findItem(listData, item, location, found);
        newNode->next = location;
        newNode->back = location->back;
        location->back = newNode;

        if (listData->info.comparedTo(item) == LESS)
        {
            listData = newNode;
        }
        break;
    default:
        listData = newNode;
        newNode->next = newNode;
        newNode->back = newNode;
    }

    length++;
}
void SortedDoublyLinkedType::deleteItem(ItemType item)
{
    NodeType *location;
    bool found;

    findItem(listData, item, location, found);

    if (location->next == location->back)
    {
        listData = NULL;
    }
    else
    {
        (location->back)->next = location->next;
        if (location == listData)
        {
            listData = location->back;
        }
    }
    delete location;
    location = NULL;
    length--;
}

//	Observers.
bool SortedDoublyLinkedType::isFull(void) const
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
int SortedDoublyLinkedType::getLength(void) const
{
    return length;
}

//	Iterators.
void SortedDoublyLinkedType::resetList(void)
{
    currentPos = listData;
}
ItemType SortedDoublyLinkedType::getItem(ItemType item, bool &found)
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
ItemType SortedDoublyLinkedType::getNextItem(void)
{
    return (currentPos = currentPos->next)->info;
}

#endif //SORTEDDOUBLYLINKEDTYPE_CPP