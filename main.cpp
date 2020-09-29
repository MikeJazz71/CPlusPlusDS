
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>

using namespace std;

namespace myNames
{
	void printf(int);
};
using namespace myNames;

int main(void)
{

	cout << "Welcome, Data Structures!\n";

	return EXIT_SUCCESS;
}

void myNames::printf(int value)
{
	cout << value << "\n";
}

#endif //MAIN_CPP