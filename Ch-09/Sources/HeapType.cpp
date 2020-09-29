
#ifndef HEAPTYPE_CPP
#define HEAPTYPE_CPP

//	C++ Plus Data Structures, Chapter 9.

template <class ItemType>
void Swap(ItemType &x, ItemType &y)
{
    ItemType z = x;
    x = y, y = z;
}

template <class ItemTypeu
struct HeapType
{
    int numElements;
    ItemType *elements;
    void ReheapUp(int, int);
    void ReheapDown(int, int);
};

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild = root * 2 + 2;
    int leftChild = root * 2 + 1;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
        {
            maxChild = leftChild;
        }
        else
        {
            if (elements[leftChild] <= elements[rightChild])
            {
                maxChild = rightChild;
            }
            else
            {
                maxChild = leftChild;
            }
        }
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    if (bottom > root)
    {
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

template <class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom)
{
    int maxChild;
    int rightChild = root * 2 + 2;
    int leftChild = root * 2 + 1;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
        {
            maxChild = leftChild;
        }
        else
        {
            if (elements[leftChild] <= elements[rightChild])
            {
                maxChild = rightChild;
            }
            else
            {
                maxChild = leftChild;
            }
        }
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(elements, maxChild, bottom);
        }
    }
}

template <class ItemType>
void HeapSort(ItemType values[], int numValues)
{
    for (int index = numValues / 2 - 1; index >= 0; index--)
    {
        ReheapDown(values, index, numValues - 1);
    }

    for (int index = numValues - 1; index >= 1; index--)
    {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}

#endif //HEAPTYPE_CPP