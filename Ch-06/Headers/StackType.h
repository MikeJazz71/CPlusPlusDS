
#ifndef STACKTYPE_H
#define STACKTYPE_H

//	C++ Plus Data Structures, Chapter 6.

//	Class Specification.

class FullStack
{
};

class EmptyStack
{
};

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType *nextPtr;
};

template <class ItemType>
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
    NodeType<ItemType> *topPtr;
};

#endif //STACKTYPE_H