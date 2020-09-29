
#ifndef SPECIALIZEDLIST_H
#define SPECIALIZEDLIST_H

//	C++ Plus Data Structures, Chapter 6.

//	Class Specification.

#include "../../ItemType.cpp"

struct NodeType
{
    ItemType info;
    NodeType *next;
    NodeType *back;
};

class SpecializedList
{

public:
    //	Constructors.
    SpecializedList(void);
    virtual ~SpecializedList();
    SpecializedList(const SpecializedList &);

    //	Transformers.
    void PutEnd(ItemType);
    void PutFront(ItemType);
    void ResetForward(void);
    void ResetBackward(void);

    //	Observers.
    int GetLength(void);

    //	Iterators.
    void GetNextItem(ItemType &, bool &);
    void GetPriorItem(ItemType &, bool &);

private:
    int length;
    NodeType *list;
    NodeType *currentNextPos;
    NodeType *currentBackPos;
};

#endif //SPECIALIZEDLIST_H