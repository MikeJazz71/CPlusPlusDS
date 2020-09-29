
#ifndef TREEFUNCTIONS_CPP
#define TREEFUNCTIONS_CPP

//	C++ Plus Data Structures, Chapter 8.

#include "../Headers/TreeType.h"

int CountNodes(TreeNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }
}
void Retrieve(TreeNode *tree, ItemType &item, bool &found)
{
    if (tree == NULL)
        found = false;
    else if (item < tree->info)
        Retrieve(tree->left, item, found);
    else if (item > tree->info)
        Retrieve(tree->right, item, found);
    else
    {
        found = true;
    }
}
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
    }
    else
    {
        Insert(tree->right, item);
    }
}
void GetPredecessor(TreeNode *tree, ItemType &data)
{
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    data = tree->info;
}
void DeleteNode(TreeNode *&tree)
{
    ItemType data;
    TreeNode *tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}
void Delete(TreeNode *&tree, ItemType item)
{
    if (item < tree->info)
    {
        Delete(tree->left, item);
    }
    else if (item > tree->info)
    {
        Delete(tree->right, item);
    }
    else
    {
        DeleteNode(tree);
    }
}
void PrintTree(TreeNode *tree)
{
    if (tree != NULL)
    {
        PrintTree(tree->left);
        std::cout << tree->info;
        PrintTree(tree->right);
    }
}
void Destroy(TreeNode *&tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}
void CopyTree(TreeNode *&copy, const TreeNode *originalTree)
{
    if (originalTree == NULL)
    {
        copy = NULL;
    }
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}
void PreOrder(TreeNode *tree, QueType &preQue)
{
    if (tree != NULL)
    {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}
void InOrder(TreeNode *tree, QueType &inQue)
{
    if (tree != NULL)
    {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}
void PostOrder(TreeNode *tree, QueType &postQue)
{
    if (tree != NULL)
    {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree->info);
    }
}
void FindNode(TreeNode *tree, ItemType item, TreeNode *&nodePtr, TreeNode *&parentPtr)
{
    nodePtr = tree;
    parentPtr = NULL;
    bool found = false;
    while (nodePtr != NULL && !found)
    {
        if (item < nodePtr->info)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->left;
        }
        else if (item > nodePtr->info)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->right;
        }
        else
        {
            found = true;
        }
    }
}

#endif //TREEFUNCTIONS_CPP