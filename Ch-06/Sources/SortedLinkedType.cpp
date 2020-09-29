
#ifndef SORTEDLINKEDTYPE_CPP
#define SORTEDLINKEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 4.

//	Class Implementation.

#include "../Headers/SortedLinkedType.h"

//	Constructors.
template <class T>
SortedLinkedType<T>::SortedLinkedType(void)
{
    listData = NULL;
    length = 0;
    currentPos = NULL;
}
template <class T>
SortedLinkedType<T>::~SortedLinkedType()
{
    makeEmpty();
}

//	Transformers.
template <class T>
void SortedLinkedType<T>::makeEmpty(void)
{
    NodeType<T> *tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
        tempPtr = NULL;
    }
    length = 0;
}
template <class T>
void SortedLinkedType<T>::putItem(T item)
{
    NodeType<T> *predLoc = NULL;
    NodeType<T> *location = listData;
    NodeType<T> *newNode = new NodeType;
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
template <class T>
void SortedLinkedType<T>::deleteItem(T item)
{
    NodeType<T> *location = listData;
    NodeType<T> *tempLocation;

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
template <class T>
bool SortedLinkedType<T>::isFull(void) const
{
    NodeType<T> *location;

    try
    {
        location = new NodeType<T>;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }

    delete location;
    location = NULL;
    return false;
}
template <class T>
int SortedLinkedType<T>::getLength(void) const
{
    return length;
}

//	Iterators.
template <class T>
void SortedLinkedType<T>::resetList(void)
{
    currentPos = NULL;
}
template <class T>
T SortedLinkedType<T>::getItem(T item, bool &found)
{
    NodeType<T> *location = listData;
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
template <class T>
T SortedLinkedType<T>::getNextItem(void)
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
template <class T>
SortedTypeIterator<T> SortedLinkedType<T>::begin()
{
    SortedTypeIterator<T> it(listData);
    return it;
}
template <class T>
SortedTypeIterator<T> SortedLinkedType<T>::end()
{
    SortedTypeIterator<T> it(NULL);
    return it;
}

//	Constructors.
template <class T>
SortedTypeIterator<T>::SortedTypeIterator(NodeType<T> *start)
{
    this->item = start;
}

//	Observers.
template <class T>
T &SortedTypeIterator<T>::operator*()
{
    return this->item->info;
}
template <class T>
bool SortedTypeIterator<T>::operator!=(const SortedTypeIterator<T> &it) const
{
    return this->item != it.item;
}

//	Transformers.
template <class T>
SortedTypeIterator<T> &SortedTypeIterator<T>::operator++()
{
    if (item != NULL)
    {
        item = item->next;
    }
    return *this;
}

#endif //SORTEDLINKEDTYPE_CPP