
#ifndef TREETYPE_H
#define TREETYPE_H

//	C++ Plus Data Structures, Chapter 8.

//	Class Specification.

#include "../../Ch-05/Sources/QueType.cpp"

typedef char ItemType;

enum OrderType
{
    PRE_ORDER = -1,
    IN_ORDER,
    POST_ORDER
};

struct TreeNode
{
    ItemType info;
    TreeNode *left;
    TreeNode *right;
};

class TreeType
{

public:
    //	Constructors.
    TreeType(void);
    virtual ~TreeType();
    TreeType(const TreeType &);

    //	Transformers.
    void MakeEmpty(void);
    void PutItem(ItemType);
    void DeleteItem(ItemType);
    void ResetTree(OrderType);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;
    void operator=(const TreeType &);
    int GetLength(void) const;

    //	Iterators.
    ItemType GetItem(ItemType, bool &) const;
    ItemType GetNextItem(OrderType, bool &);
    void Print(void) const;

private:
    TreeNode *root;
    QueType inQue;
    QueType preQue;
    QueType postQue;
};

#endif //TREETYPE_H