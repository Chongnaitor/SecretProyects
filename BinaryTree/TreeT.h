#pragma once
#include "NodeT.h"
template<class Type>
class BinaryTreeT {
public:
	BinaryTreeT();
	~BinaryTreeT();
	void postordenado_print(NodeT<Type> *rama);
	void preordenado_print(NodeT<Type> *rama);
	void insert(NodeT<Type>*rama,NodeT<Type>Dato);
	void destruir_tree();
	void enorden_print();
	void postordenado_print();
	void preordenado_print();
	void destruir_tree(NodeT<Type> *rama);
	void insert(NodeT<Type>Dato);
	void enorden_print(NodeT<Type> *rama);
	void usuarioInsert();
	NodeT<Type>*ValorMinimo(NodeT<Type>*raiz);
	NodeT<Type>*BorrarNodo(NodeT<Type>*raiz,Type Dato);
	NodeT<Type>*raiz;
};
