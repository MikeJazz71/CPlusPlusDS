
#ifndef SORTS_CPP
#define SORTS_CPP

#include <chrono>
#include <thread>

//  Selection Sort.
template <class ItemType>
inline void Swap(ItemType &item1, ItemType &item2)
{
    ItemType tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}
template <class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex)
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
        if (values[index] < values[indexOfMin])
            indexOfMin = index;
    return indexOfMin;
}
template <class ItemType>
void SelectionSort(ItemType values[], int numValues)
{
    int endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++)
        Swap(values[current],
             values[MinIndex(values, current, endIndex)]);
}

//  Bubble Sort.
template <class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex)
{
    for (int index = endIndex; index > startIndex; index--)
        if (values[index] < values[index - 1])
            Swap(values[index], values[index - 1]);
}
template <class ItemType>
void BubbleSort(ItemType values[], int numValues)
{
    int current = 0;
    while (current < numValues - 1)
    {
        BubbleUp(values, current, numValues - 1);
        current++;
    }
}
template <class ItemType>
void BubbleUp2(ItemType values[], int startIndex, int endIndex,
               bool &sorted)
{
    sorted = true;
    for (int index = endIndex; index > startIndex; index--)
        if (values[index] < values[index - 1])
        {
            Swap(values[index], values[index - 1]);
            sorted = false;
        }
}
template <class ItemType>
void ShortBubble(ItemType values[], int numValues)
{
    int current = 0;
    bool sorted = false;
    while (current < numValues - 1 && !sorted)
    {
        BubbleUp2(values, current, numValues - 1, sorted);
        current++;
    }
}

//  Insertion Sort.
template <class ItemType>
void InsertItem(ItemType values[], int startIndex, int endIndex)
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);
    while (moreToSearch && !finished)
    {
        if (values[current] < values[current - 1])
        {
            Swap(values[current], values[current - 1]);
            current--;
            moreToSearch = (current != startIndex);
        }
        else
            finished = true;
    }
}
template <class ItemType>
void InsertionSort(ItemType values[], int numValues)
{
    for (int count = 0; count < numValues; count++)
        InsertItem(values, 0, count);
}

//  Merge Sort.
template <class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast,
           int rightFirst, int rightLast, ItemType tempArray[])
{
    int index = leftFirst;
    int saveFirst = leftFirst;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst] < values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }
    while (leftFirst <= leftLast)
    // Copy remaining items from left half.
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    while (rightFirst <= rightLast)
    // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}
template <class ItemType>
void MergeSort(ItemType values[], int first, int last, ItemType tempArray)
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort<ItemType>(values, first, middle, tempArray);
        MergeSort<ItemType>(values, middle + 1, last, tempArray);
        /*
        thread left (MergeSort<ItemType>, values, first, middle, tempArray);
        thread right (MergeSort<ItemType>, values, middle + 1, last, tempArray);
        left.join();
        right.join();
        */
        Merge<ItemType>(values, first, middle, middle + 1, last, tempArray);
    }
}

//  Radix Sort.
template <class ItemType>
void CollectQueues(ItemType values[], QueType<ItemType> queues[],
                   int radix)
// Post: queues are concatenated with queue[0]'s on top and
// queue[9]'s on the bottom and copied into values.
{
    int index = 0;
    ItemType item;
    for (int counter = 0; counter < radix; counter++)
    {
        while (!queues[counter].IsEmpty())
        {
            queues[counter].Dequeue(item);
            values[index] = item;
            index++;
        }
    }
}
template <class ItemType>
void RadixSort(ItemType values[], int numValues, int numPositions, int radix)
// Post: Elements in values are in order by key.
{
    QueType<ItemType> queues[radix];
    // With default constructor, each queue size is 500. int whichQueue;
    for (int position = 1; position <= numPositions; position++)
    {
        for (int counter = 0; counter < length; counter++)
        {
            whichQueue = values[counter].SubKey(position);
            queues[whichQueue].Enqueue(values[counter]);
        }
        CollectQueues(values, queues, radix);
    }
}
#endif //SORTS_CPP