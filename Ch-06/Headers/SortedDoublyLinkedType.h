
#ifndef SORTEDDOUBLYLINKEDTYPE_H
#define SORTEDDOUBLYLINKEDTYPE_H

//	C++ Plus Data Structures, Chapter 6.

//	Class Specification.

#include "../../ItemType.cpp"

enum RelationType
{
    LESS = -1,
    GREATER,
    EQUAL
};

struct NodeType
{
    ItemType info;
    NodeType *next;
    NodeType *back;
};

class SortedDoublyLinkedType
{

public:
    //	Constructors.
    SortedDoublyLinkedType(void);
    virtual ~SortedDoublyLinkedType();

    //	Transformers.
    void makeEmpty(void);
    void putItem(ItemType);
    void deleteItem(ItemType);
    void InsertItem(ItemType);

    //	Observers.
    bool isFull(void) const;
    int getLength(void) const;
    void RetrieveItem(ItemType &);

    //	Iterators.
    void resetList(void);
    ItemType getNextItem(void);
    ItemType getItem(ItemType, bool &);
    void RetrieveItem(ItemType &, bool &);

private:
    int length;
    NodeType *listData;
    NodeType *currentPos;
};

#endif //SORTEDDOUBLYLINKEDTYPE_H