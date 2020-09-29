
#ifndef SORTEDLINKEDTYPE_H
#define SORTEDLINKEDTYPE_H

//	C++ Plus Data Structures, Chapter 4.

//	Class Specification.

#include "../../ItemType.cpp"

template <class T>
struct NodeType
{
    T info;
    NodeType *next;
};

template <class T>
class SortedTypeIterator
{
public:
    //	Constructors.
    SortedTypeIterator(NodeType<T> *start);

    //	Transformers.
    SortedTypeIterator<T> &operator++();

    //	Observers.
    T &operator*();
    bool operator!=(const SortedTypeIterator<T> &it) const;

private:
    NodeType<T> *item;
};

template <class T>
class SortedLinkedType
{

public:
    //	Constructors.
    SortedLinkedType(void);
    virtual ~SortedLinkedType();

    //	Transformers.
    void makeEmpty(void);
    void putItem(T);
    void deleteItem(T);

    //	Observers.
    bool isFull(void) const;
    int getLength(void) const;

    //	Iterators.
    void resetList(void);
    T getItem(T, bool &);
    T getNextItem(void);
    SortedTypeIterator<T> begin();
    SortedTypeIterator<T> end();

private:
    NodeType<T> *listData;
    int length;
    NodeType<T> *currentPos;
};

#endif //SORTEDLINKEDTYPE_H