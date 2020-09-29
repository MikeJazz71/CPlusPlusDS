
#ifndef TREETYPE_CPP
#define TREETYPE_CPP

//	C++ Plus Data Structures, Chapter 8.

//	Class Implementation.

#include "TreeFunctions.cpp"

//	Constructors.
TreeType::TreeType(void)
{
    root = NULL;
}
TreeType::~TreeType()
{
    Destroy(root);
}
TreeType::TreeType(const TreeType &originalTree)
{
    CopyTree(root, originalTree.root);
}

//	Transformers.
void TreeType::MakeEmpty(void)
{
    Destroy(root);
}
void TreeType::PutItem(ItemType item)
{
    Insert(root, item);
}
void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}
void TreeType::ResetTree(OrderType order)
{
    QueType preQue, inQue, postQue;
    switch (order)
    {
    case PRE_ORDER:
        PreOrder(root, preQue);
        break;
    case IN_ORDER:
        InOrder(root, inQue);
        break;
    case POST_ORDER:
        PostOrder(root, postQue);
        break;
    }
}

//	Observers.
bool TreeType::IsFull(void) const
{
    TreeNode *location;

    try
    {
        location = new TreeNode;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }

    delete location;
    location = NULL;
    return false;
}
bool TreeType::IsEmpty(void) const
{
    return root == NULL;
}
void TreeType::operator=(const TreeType &originalTree)
{
    if (&originalTree == this)
    {
        return;
    }
    Destroy(root);
    CopyTree(root, originalTree.root);
}

//	Iterators.
ItemType TreeType::GetItem(ItemType item, bool &found) const
{
    Retrieve(root, item, found);
    return item;
}
ItemType TreeType::GetNextItem(OrderType order, bool &finished)
{
    ItemType item;
    finished = false;
    switch (order)
    {
    case PRE_ORDER:
        preQue.Dequeue();
        if (preQue.IsEmpty())
        {
            finished = true;
        }
        break;
    case IN_ORDER:
        inQue.Dequeue();
        if (inQue.IsEmpty())
        {
            finished = true;
        }
        break;
    case POST_ORDER:
        postQue.Dequeue();
        if (postQue.IsEmpty())
        {
            finished = true;
        }
        break;
    }
    return item;
}
void TreeType::Print(void) const
{
    PrintTree(root);
}

#endif //TREETYPE_CPP