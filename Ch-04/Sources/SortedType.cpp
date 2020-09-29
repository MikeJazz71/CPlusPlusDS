
#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

//	C++ Plus Data Structures, Chapter 4.

//	Class Implementation.

#include "../Headers/SortedType.h"

//	Constructors.
SortedType::SortedType(void)
{
    length = 0;
    maxList = 500;
    currentPosition = 0;
    info = new ItemType[500];
}
SortedType::SortedType(int size)
{
    length = 0;
    maxList = size;
    currentPosition = 0;
    info = new ItemType[size];
}
SortedType::~SortedType()
{
    delete[] info;
    info = NULL;
}

//	Transformers.
void SortedType::makeEmpty(void)
{
    length = 0;
}
void SortedType::putItem(ItemType item)
{
    int location = 0;
    bool moreToSearch = (location < length);

    while (moreToSearch)
    {
        switch (item.comparedTo(info[location]))
        {
        case EQUAL:
        case LESS:
            moreToSearch = false;
            break;
        default:
            location++;
            moreToSearch = (location < length);
        }
    }
    for (int index = length++; index > location; index--)
    {
        info[index] = info[index - 1];
    }
    info[location] = item;
}
void SortedType::deleteItem(ItemType item)
{
    int location = 0;

    while (item.comparedTo(info[location]) != EQUAL)
    {
        location++;
    }
    for (int index = location + 1; index < length; index++)
    {
        info[index - 1] = info[index];
    }
    length--;
}

//	Observers.
bool SortedType::isFull(void) const
{
    return length == maxList;
}
int SortedType::getLength(void) const
{
    return length;
}

//	Iterators.
void SortedType::resetList(void)
{
    currentPosition = -1;
}
ItemType SortedType::getItem(ItemType item, bool &found)
{
    int first = 0, last = length - 1, midPoint;
    bool moreToSearch = (first <= last);
    found = false;

    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        switch (item.comparedTo(info[midPoint]))
        {
        case LESS:
            last = midPoint - 1;
            moreToSearch = first <= last;
            break;
        case GREATER:
            first = midPoint + 1;
            moreToSearch = first <= last;
            break;
        default:
            found = true;
        }
    }
    return item;
}
ItemType SortedType::getNextItem(void)
{
    return info[++currentPosition];
}

#endif //SORTEDTYPE_CPP