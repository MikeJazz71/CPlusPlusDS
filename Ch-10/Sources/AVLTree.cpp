
#ifndef AVLTREE_CPP
#define AVLTREE_CPP

//	C++ Plus Data Structures, Chapter 10.

#include "../../Ch-08/Sources/TreeType.cpp"

TreeNode *RotateRight(TreeNode *T)
{
    TreeNode *S = T->left;
    TreeNode *B = S->right;
    S->right = T;
    T->left = B;
    return S;
}
TreeNode *RotateLeft(TreeNode *T)
{
    TreeNode *S = T->right;
    TreeNode *B = S->left;
    S->left = T;
    T->right = B;
    return S;
}
TreeNode *RotateRightLeft(TreeNode *T)
{
    TreeNode *S = T->right;
    T->right = RotateRight(S);
    return RotateLeft(T);
}
TreeNode *RotateLeftRight(TreeNode *T)
{
    TreeNode *S = T->left;
    T->left = RotateLeft(S);
    return RotateRight(T);
}
int Height(TreeNode *T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int heightLeft = Height(T->left);
        int heightRight = Height(T->right);
        if (heightLeft > heightRight)
        {
            return heightLeft + 1;
        }
        else
        {
            return heightRight + 1;
        }
    }
}
int Difference(TreeNode *T)
{
    return Height(T->left) - Height(T->right);
}
TreeNode *Balance(TreeNode *T)
{
    int balanceFactor = Difference(T);
    if (balanceFactor > 1)
    {
        if (Difference(T->left) > 1)
        {
            return RotateRight(T);
        }
        else
        {
            return RotateLeftRight(T);
        }
    }
    else if (balanceFactor < -1)
    {
        if (Difference(T->right) < 0)
        {
            return RotateLeft(T);
        }
        else
        {
            return RotateRightLeft(T);
        }
    }
    else
    {
        return T;
    }
}

#ifndef TREETYPE_CPP

void Insert(TreeNode *&tree, ItemType item)
{
    if (tree == NULL)
    {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        Insert(tree->left, item);
        tree->left = Balance(tree->left);
    }
    else
    {
        Insert(tree->right, item);
        tree->right = Balance(tree->right);
    }
}
void DeleteNode(TreeNode *&tree)
{
    ItemType data;
    TreeNode *tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
        tree = Balance(tree);
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
        tree = Balance(tree);
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
        tree->left = Balance(tree->left);
    }
}
void Delete(TreeNode *&tree, ItemType item)
{
    if (item < tree->info)
    {
        Delete(tree->left, item);
        tree->left = Balance(tree->left);
    }
    else if (item > tree->info)
    {
        Delete(tree->right, item);
        tree->right = Balance(tree->right);
    }
    else
    {
        DeleteNode(tree);
    }
}
void TreeType::PutItem(ItemType item)
{
    Insert(root, item);
    root = Balance(root);
}
void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
    root = Balance(root);
}

#endif //TREETYPE_CPP

#endif //AVLTREE_CPP