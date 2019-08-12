#include "NodeT.h"
template<class Type>
inline NodeT<Type>::NodeT()
{
}
template<class Type>
NodeT<Type>::~NodeT()
{
}

template class NodeT<int>;
template class NodeT<string>;
