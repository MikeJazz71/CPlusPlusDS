
#ifndef REDBLACKTREE_CPP
#define REDBLACKTREE_CPP

//	C++ Plus Data Structures, Chapter 10.

#include <iostream>

#include "AVLTree.cpp"
#include "../../Ch-08/Sources/TreeType.cpp"

#ifndef TREETYPE_CPP

enum Color
{
    RED = -1,
    BLACK = 1
};

void SwapColors(Color &x, Color &y)
{
    Color z = x;
    x = y, y = z;
}

struct TreeNode
{
    Color color;
    ItemType info;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode *Parent(TreeNode *N)
{
    return N->parent;
}
TreeNode *GrandParent(TreeNode *N)
{
    TreeNode *P = Parent(N);
    if (P == NULL)
    {
        return NULL;
    }
    else
    {
        return Parent(P);
    }
}
TreeNode *Uncle(TreeNode *N)
{
    TreeNode *G = GrandParent(N);
    if (G == NULL)
    {
        return NULL;
    }
    else if (Parent(N) == G->left)
    {
        return G->right;
    }
    else
    {
        return G->left;
    }
}
Color GetColor(TreeNode *N)
{
    if (N == NULL)
    {
        return BLACK;
    }
    else
    {
        return N->color;
    }
}
void SetColor(TreeNode *N, Color color)
{
    if (N != NULL)
    {
        N->color = color;
    }
}
void ReStructure(TreeNode *N)
{
    TreeNode *P = Parent(N);
    TreeNode *G = GrandParent(N);
    if (P == G->left && N == P->left)
    {
        G = RotateRight(G);
        SwapColors(G->color, P->color);
    }
    else if (P == G->left && N == P->right)
    {
        P = RotateLeftRight(P);
        SwapColors(G->color, N->color);
    }
    else if (P == G->right && N == P->right)
    {
        G = RotateLeft(G);
        SwapColors(G->color, P->color);
    }
    else if (P == G->right && N == P->left)
    {
        P = RotateRightLeft(P);
        SwapColors(G->color, N->color);
    }
}
void ReColor(TreeNode *N)
{
    if (N == NULL)
    {
        return;
    }
    TreeNode *P = Parent(N);
    TreeNode *G = GrandParent(N);
    TreeNode *U = Uncle(N);
    if (P == NULL)
    {
        N->color = BLACK;
    }
    else if (P != NULL || GetColor(P) != BLACK)
    {
        if (GetColor(U) == RED)
        {
            SetColor(P, BLACK);
            SetColor(U, BLACK);
            SetColor(G, RED);
            ReColor(G);
        }
        else
        {
            ReStructure(N);
        }
    }
}
void Insert(TreeNode *&tree, TreeNode *parent, ItemType item)
{
    if (tree == NULL)
    {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->parent = parent;
        tree->info = item;
        ReColor(tree);
    }
    else if (item < tree->info)
    {
        Insert(tree->left, tree, item);
    }
    else
    {
        Insert(tree->right, tree, item);
    }
}
void TreeType::PutItem(ItemType item)
{
    Insert(root, NULL, item);
}

#endif //TREETYPE_CPP

#endif //REDBLACKTREE_CPP