
#ifndef UNSORTEDLINKEDTYPE_H
#define UNSORTEDLINKEDTYPE_H

//	C++ Plus Data Structures, Chapter 3.

//	Class Specification.

#include "../../ItemType.cpp"

struct NodeType
{
    ItemType info;
    NodeType *next;
};

class UnsortedLinkedType
{

public:
    //	Constructors.
    UnsortedLinkedType(void);
    virtual ~UnsortedLinkedType();

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

#endif //UNSORTEDLINKEDTYPE_H