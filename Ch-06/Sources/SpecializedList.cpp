
#ifndef SPECIALIZEDLIST_CPP
#define SPECIALIZEDLIST_CPP

//	C++ Plus Data Structures, Chapter 6.

//	Class Implementation.

#include "../Headers/SpecializedList.h"

//	Constructors.
SpecializedList::SpecializedList(void)
{
    length = 0;
    list = currentNextPos = currentBackPos = NULL;
}
SpecializedList::~SpecializedList() {}
SpecializedList::SpecializedList(const SpecializedList &someList)
{
    length = 0;
    list = currentNextPos = currentBackPos = NULL;
}

//	Transformers.
void SpecializedList::PutEnd(ItemType item)
{
    PutFront(item);
    list = list->next;
}
void SpecializedList::PutFront(ItemType item)
{
    NodeType *newNode = new NodeType;
    newNode->info = item;
    if (list == NULL)
    {
        newNode->back = newNode;
        newNode->next = newNode;
        list = newNode;
    }
    else
    {
        newNode->back = list;
        newNode->next = list->next;
        list->next->back = newNode;
        list->next = newNode;
    }
    length++;
}
void SpecializedList::ResetForward(void)
{
    currentNextPos = NULL;
}
void SpecializedList::ResetBackward(void)
{
    currentBackPos = NULL;
}

//	Observers.
int SpecializedList::GetLength(void)
{
    return length;
}

//	Iterators.
void SpecializedList::GetNextItem(ItemType &item, bool &finished)
{
    if (currentNextPos == NULL)
    {
        currentNextPos = list->next;
    }
    else
    {
        currentNextPos = currentNextPos->next;
    }
    item = currentNextPos->info;
    finished = currentNextPos == list;
}
void SpecializedList::GetPriorItem(ItemType &item, bool &finished)
{
    if (currentBackPos == NULL)
    {
        currentBackPos = list;
    }
    else
    {
        currentBackPos = currentBackPos->back;
    }
    item = currentBackPos->info;
    finished = currentBackPos == list->next;
}

#endif //SPECIALIZEDLIST_CPP