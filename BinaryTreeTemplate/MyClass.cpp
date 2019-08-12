#include "MyClass.h"
template<class T>
inline T MyClass<T>::MyFunction(T Arg, T Arg2)
{
	return Arg + Arg2;
	std::cout << Arg + Arg2;
}

template class MyClass<int>;