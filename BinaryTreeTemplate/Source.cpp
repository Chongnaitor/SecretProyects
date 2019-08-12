#include "MyClass.h"
#include <iostream>
int main()
{
	MyClass<int>B;
	std::cout<< B.MyFunction(12, 2);
	std::cin.get();
}