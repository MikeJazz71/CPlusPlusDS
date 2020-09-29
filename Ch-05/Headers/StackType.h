
#ifndef STACKTYPE_H
#define STACKTYPE_H

//	C++ Plus Data Structures, Chapter 5.

//	Class Specification.

class FullStack
{
};

class EmptyStack
{
};

#include "../../ItemType.cpp"

struct NodeType
{
    ItemType info;
    NodeType *nextPtr;
};

class StackType
{

public:
    //	Constructors.
    StackType(void);
    virtual ~StackType();

    //	Transformers.
    void Push(ItemType);
    void Pop(void);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;

    //	Iterators.
    ItemType Top(void) const;

private:
    NodeType *topPtr;
};

#endif //STACKTYPE_H