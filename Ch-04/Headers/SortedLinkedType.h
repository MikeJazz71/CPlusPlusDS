
#ifndef SORTEDLINKEDTYPE_H
#define SORTEDLINKEDTYPE_H

//	C++ Plus Data Structures, Chapter 4.

//	Class Specification.

#include "../../ItemType.cpp"

struct NodeType
{
    ItemType info;
    NodeType *next;
};

class SortedLinkedType
{

public:
    //	Constructors.
    SortedLinkedType(void);
    virtual ~SortedLinkedType();

    //	Transformers.
    void makeEmpty(void);
    void putItem(ItemType);
    void deleteItem(ItemType);

    //	Observers.
    bool isFull(void) const;
    int getLength(void) const;

    //	Iterators.
    void resetList(void);
    ItemType getItem(ItemType, bool &);
    ItemType getNextItem(void);

private:
    NodeType *listData;
    int length;
    NodeType *currentPos;
};

#endif //SORTEDLINKEDTYPE_H