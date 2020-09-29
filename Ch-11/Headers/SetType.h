
#ifndef SETTYPE_H
#define SETTYPE_H

//	C++ Plus Data Structures, Chapter 11.

//	Class Specification.

typedef char ItemType;

class SetType
{

public:
    //	Constructors.
    SetType(int);
    SetType(void);
    virtual ~SetType();

    //	Transformers.
    void MakeEmpty(void);
    void PutItem(ItemType);
    void DeleteItem(ItemType);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;

    //	Iterators.
    int Cardinality(void);
    SetType Union(SetType);
    SetType Difference(SetType);
    SetType Intersection(SetType);

private:
    int maxItems;
    ItemType *items;
};

#endif //SETTYPE_H