
#ifndef MAPTYPE_H
#define MAPTYPE_H

//	C++ Plus Data Structures, Chapter 11.

//	Class Specification.

#include "../../ItemType.cpp"
#include "../../Ch-08/Sources/TreeType.cpp"

class MapType
{
public:
    //	Constructors.
    MapType();
    virtual ~MapType();

    //	Transformers.
    void MakeEmpty(void);
    void Store(ItemType item);
    void Delete(ItemType item);

    //	Observers.
    bool IsFull(void) const;
    bool IsEmpty(void) const;

    //	Iterators.
    ItemType Find(ItemType item, bool &found);
    void Print(std::ofstream &outFile);

private:
    TreeType items;
};

#endif //MAPTYPE_H