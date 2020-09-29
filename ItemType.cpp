
#ifndef ITEMTYPE_CPP
#define ITEMTYPE_CPP

//	C++ Plus Data Structures, Chapter 3.

//	Class Implementation.

#include "ItemType.h"

//	Constructors.
ItemType::ItemType(void)
{
	value = 0;
}
ItemType::ItemType(int number)
{
	value = number;
}

//	Transformers.
void ItemType::initialize(int number)
{
	value = number;
}

//	Observers.
void ItemType::print(std::ostream &out) const
{
	out << value;
}
RelationType ItemType::comparedTo(ItemType OtherItem) const
{
	if (value < OtherItem.value)
	{
		return LESS;
	}
	else if (value > OtherItem.value)
	{
		return GREATER;
	}
	else
	{
		return EQUAL;
	}
}

#endif //ITEMTYPE_CPP