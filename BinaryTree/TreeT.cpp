#include "TreeT.h"
#include "Node.h"
template<class Type>
inline BinaryTreeT<Type>::BinaryTreeT()
{
	raiz = nullptr;
}
template<class Type>
BinaryTreeT<Type>::~BinaryTreeT()
{
	destruir_tree();
}
template<class Type>
void BinaryTreeT<Type>::destruir_tree(NodeT<Type>* rama)
{
	if (rama != nullptr)
	{
		destruir_tree(rama->Izquierda);
		destruir_tree(rama->Derecha);
		delete rama;
	}
}
template<class Type>
void BinaryTreeT<Type>::insert(NodeT<Type>*rama,NodeT<Type>Dato)
{
	if (Dato.Dato<rama->Dato)
	{
		if(rama->Izquierda!=nullptr)
		{
			insert(rama->Izquierda,Dato);
		}
		else
		{
			rama->Izquierda = new NodeT<Type>;
			rama->Izquierda->Dato = Dato.Dato;
		}
	}
	else if (Dato.Dato>=rama->Dato)
	{
		if (rama->Derecha != nullptr)
		{
			insert( rama->Derecha, Dato);
		}
		else {
			rama->Derecha = new NodeT<Type>;
			rama->Derecha->Dato = Dato.Dato;
		}

	}

}
template<class Type>
void BinaryTreeT<Type>::insert(NodeT<Type>Dato)
{
	if (raiz != nullptr)
	{
		insert(raiz,Dato);
	}
	else
	{
		raiz = new NodeT<Type>;
		raiz->Dato = Dato.Dato;
	}
}
template<class Type>
void BinaryTreeT<Type>::destruir_tree()
{
	destruir_tree(raiz);
}
template<class Type>
void BinaryTreeT<Type>::enorden_print(NodeT<Type>* rama)
{
	if (rama != nullptr)
	{
		enorden_print(rama->Izquierda);
		cout << rama->Dato << ",";
		enorden_print(rama->Izquierda);
	}
}
template<class Type>
void BinaryTreeT<Type>::usuarioInsert()
{
	Type A;
	std::cin >> A;
	raiz->Dato = A;
}
template<class Type>
NodeT<Type>*BinaryTreeT<Type>::ValorMinimo(NodeT<Type>* raiz)
{
	NodeT<Type>*Actual = raiz;
	while (Actual&&Actual->Izquierda != nullptr)
	{
		Actual = Actual->Izquierda;
		
	}
	return Actual;
}
template<class Type>
NodeT<Type>*BinaryTreeT<Type>::BorrarNodo(NodeT<Type>* raiz,Type Dato )
{
	if (raiz == nullptr)
	{
		return raiz;
	}
	if (Dato < raiz->Dato)
	{
		raiz->Izquierda = BorrarNodo(raiz->Izquierda, Dato);
	}
	else if (Dato > raiz->Dato)
	{
		raiz->Derecha = BorrarNodo(raiz->Derecha, Dato);
	}
	else
	{
		if (raiz->Izquierda == nullptr)
		{
			NodeT<Type>*temp = raiz->Izquierda;
			free(raiz);
			return temp;
		}
		else if (raiz == nullptr)
		{
			NodeT<Type>*temp = raiz->Izquierda;
			free(raiz);
			return temp;
		}
		NodeT<Type>*temp = ValorMinimo(raiz->Derecha);
		raiz->Dato = temp->Dato;
		raiz->Derecha = BorrarNodo(raiz->Derecha, temp->Dato);



	}
	return raiz;
}
template<class Type>
void BinaryTreeT<Type>::enorden_print()
{
	enorden_print(raiz);
	cout << "\n";
}
template<class Type>
void BinaryTreeT<Type>::postordenado_print()
{
	postordenado_print(raiz);
	cout << "\n";
}
template<class Type>
void BinaryTreeT<Type>::postordenado_print(NodeT<Type>* rama)
{
	if (rama != nullptr)
	{
		enorden_print(rama->Izquierda);
		enorden_print(rama->Derecha);
		cout << rama->Dato << ",";
	}
}
template<class Type>
void BinaryTreeT<Type>::preordenado_print()
{
	preordenado_print(raiz);
	cout << "\n";
}
template<class Type>
void BinaryTreeT<Type>::preordenado_print(NodeT<Type>* rama)
{
	cout << rama->Dato << ",";
	enorden_print(rama->Izquierda);
	enorden_print(rama->Derecha);
}
template class BinaryTreeT<int>;
template class BinaryTreeT<string>;
template class BinaryTreeT<Node>;








