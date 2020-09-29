
#ifndef QUETYPE_H
#define QUETYPE_H

//	C++ Plus Data Structures, Chapter 5.

//	Class Specification.

class EmptyQueue
{
};

class FullQueue
{
};

typedef char ItemType;

struct NodeType
{
    ItemType info;
    NodeType *nextPtr;
};

class QueType
{

public:
    //	Constructors.
    QueType(void);
    virtual ~QueType();

    //	Transformers.
    void Enqueue(ItemType);
    void Dequeue(void);
    void MakeEmpty(void);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;

private:
    NodeType *frontPtr;
    NodeType *rearPtr;
};

#endif //QUETYPE_H