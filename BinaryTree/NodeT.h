#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class Type>
class NodeT {
public:
	Type Dato;
	NodeT<Type>*Izquierda;
	NodeT<Type>*Derecha;
	NodeT<Type>();
	~NodeT<Type>();
	

};

