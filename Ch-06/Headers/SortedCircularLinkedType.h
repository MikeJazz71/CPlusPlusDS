
#ifndef SORTEDCIRCULARLINKEDTYPE_H
#define SORTEDCIRCULARLINKEDTYPE_H

//	C++ Plus Data Structures, Chapter 6.

//	Class Specification.


template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType *next;
};

template <class ItemType>
class SortedCircularLinkedType
{

public:
    //	Constructors.
    SortedCircularLinkedType(void);
    virtual ~SortedCircularLinkedType();

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
    int length;
    NodeType<ItemType> *listData;
    NodeType<ItemType> *currentPos;
};

#endif //SORTEDCIRCULARLINKEDTYPE_H