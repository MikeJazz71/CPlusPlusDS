
#ifndef HASH_CPP
#define HASH_CPP

#include "../../Ch-06/Headers/SortedDoublyLinkedType.h"

#define MAX_ITEMS 100

const ItemType NULLITEM = ItemType(-1);

int ItemType::hash(void) const
{
    return idNum % MAX_ITEMS;
}

void SortedDoublyLinkedType::RetrieveItem(ItemType &item)
{
    int location;
    location = item.hash();
    item = listData[location].info;
}

void SortedDoublyLinkedType::InsertItem(ItemType item)
{
    int location;
    location = item.hash();
    listData[location].info = item;
    length++;
}

void SortedDoublyLinkedType::InsertItem(ItemType item)
{
    int location;
    location = item.hash();
    while (listData[location].info.comparedTo(NULLITEM) == EQUAL)
    {
        location = (location + 1) % MAX_ITEMS;
    }
    listData[location].info = item;
    length++;
}

void SortedDoublyLinkedType::RetrieveItem(ItemType &item, bool &found)
{
    int location;
    int startLoc;
    bool moreToSearch = true;
    startLoc = item.hash();
    location = startLoc;
    do
    {
        if (listData[location].info.comparedTo(item) == EQUAL || listData[location].info.comparedTo(NULLITEM) == EQUAL)
        {
            moreToSearch = false;
        }
        else
        {
            location = (location + 1) % MAX_ITEMS;
        }
    } while (location != startLoc && moreToSearch);
    found = (listData[location].info.comparedTo(item) == EQUAL);
    if (found)
    {
        item = listData[location].info;
    }
}

#endif //HASH_CPP