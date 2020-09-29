
#ifndef PQTYPE_H
#define PQTYPE_H

//	C++ Plus Data Structures, Chapter 9.

//	Class Specification.

#include "../Sources/HeapType.cpp"

class FullPQ
{
};

class EmptyPQ
{
};

template <class ItemType>
class PQType
{

public:
    //	Constructors.
    PQType(int);
    virtual ~PQType();

    //	Transformers.
    void MakeEmpty(void);
    void Enqueue(ItemType Item);
    void Dequeue(ItemType &item);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;

private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};

#endif //PQTYPE_H