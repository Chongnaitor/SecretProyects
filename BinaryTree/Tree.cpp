#include "Tree.h"
#include <iostream>
using std::cout;
BinaryTree::BinaryTree() {
	raiz = nullptr;
}

BinaryTree::~BinaryTree() {
	destruir_tree();
}

void BinaryTree::destruir_tree(Node*rama) {
	if (rama != nullptr) {
		destruir_tree(rama->izquierda);
		destruir_tree(rama->derecha);
		delete rama;
	}
}

void BinaryTree::insert(int Dato, string Nombre, string Apellido, Node*rama)
{

	if (Apellido < rama->Apellido) {
		if (rama->izquierda != nullptr) {
			insert(Dato, Nombre, Apellido, rama->izquierda);
		}
		else {
			rama->izquierda = new Node;
			rama->izquierda->Dato = Dato;
			rama->izquierda->Nombre = Nombre;
			rama->izquierda->Apellido = Apellido;
			rama->izquierda->izquierda = nullptr;
			rama->izquierda->derecha = nullptr;
		}
	}
	else if (Apellido >= rama->Apellido)
	{
		if (rama->derecha != nullptr) {
			insert(Dato, Nombre, Apellido, rama->derecha);
		}
		else {
			rama->derecha = new Node;
			rama->derecha->Dato = Dato;
			rama->derecha->Nombre = Nombre;
			rama->derecha->Apellido = Apellido;
			rama->derecha->derecha = nullptr;
			rama->derecha->izquierda = nullptr;
		}
	}

}

void BinaryTree::insert(int Dato, string Nombre, string Apellido) {
	if (raiz != nullptr) {
		insert(Dato, Nombre, Apellido, raiz);
	}
	else {
		raiz = new Node;
		raiz->Dato = Dato;
		raiz->Nombre = Nombre;
		raiz->Apellido = Apellido;
		raiz->izquierda = nullptr;
		raiz->derecha = nullptr;
	}
}

void BinaryTree::destruir_tree() {
	destruir_tree(raiz);
}

void BinaryTree::enorden_print(Node*rama) {
	if (rama != nullptr) {
		enorden_print(rama->izquierda);
		cout << rama->Dato << "," << rama->Nombre << "," << rama->Apellido << ",";
		enorden_print(rama->derecha);
	}
}

void BinaryTree::usuarioInsert(BinaryTree* raiz)
{
	int Dato;
	string temp;
	string temp2;
	int Ciclo = 0;
	cout << "Cuantos datos quieres meter" << std::endl;
	std::cin >> Ciclo;
	for (int i = 0; i < Ciclo; i++)
	{
		cout << "Inserte edad:" << std::endl;
		std::cin >> Dato;
		cout << "Escribe el nombre" << std::endl;
		std::cin >> temp;
		cout << "Escribe el apellido" << std::endl;
		std:: cin >> temp2;
		raiz->insert(Dato, temp, temp2);
		cout << "Dato ingresado" << std::endl;

	}
}

Node * BinaryTree::ValorMinimo(Node * raiz)
{
 Node*Actual = raiz;

 while (Actual && Actual->izquierda != nullptr)

 {
	 Actual = Actual->izquierda;
 }

	return Actual;
}

Node * BinaryTree::BorrarNode(Node * raiz, string Apellido)
{
	if (raiz == nullptr)
	{
		return raiz;
	}
	
	if (Apellido < raiz->Apellido)
		{
			raiz->izquierda = BorrarNode(raiz->izquierda, Apellido);
		}
		 
	else if (Apellido > raiz->Apellido)
	{
		raiz->derecha = BorrarNode(raiz->derecha, Apellido);
	}
		
	else
	{
	 
		if (raiz->izquierda == nullptr)
		{
			Node *temp = raiz->derecha;
			free(raiz);
			return temp;
		}
		else if (raiz->derecha == nullptr)
		{
			Node *temp = raiz->izquierda;
			free(raiz);
			return temp;
		}

	 
	    Node* temp = ValorMinimo(raiz->derecha);
		raiz->Apellido = temp->Apellido;
		raiz->derecha = BorrarNode(raiz->derecha, temp->Apellido);
	}
	return raiz;
}

Node*BinaryTree::DerechaADerechaR(Node * Padre)
{
	Node*Temporal;
	Temporal = Padre->derecha;
	Padre->derecha = Temporal->izquierda;
	Temporal->izquierda = Padre;
	return Temporal;
}

Node*BinaryTree::IzquierdaAIzquierda(Node * Padre)
{
	Node*Temporal;
	Temporal = Padre->izquierda;
	Padre->izquierda = Temporal->derecha;
	Temporal->derecha = Padre;
	return Temporal;
}

Node*BinaryTree::DerechaAIzquierda(Node * Padre)
{
	Node*Temporal;
	Temporal = Padre->derecha;
	Padre->derecha = DerechaADerechaR(Temporal);
	return DerechaADerechaR(Padre);

}

Node*BinaryTree::IzquierdaADerecha(Node * Padre)
{
	Node*Temporal;
	Temporal = Padre->izquierda;
	Padre->izquierda = DerechaADerechaR(Temporal);
	return IzquierdaAIzquierda(Padre);
}

void BinaryTree::enorden_print() {
	enorden_print(raiz);
	cout << "\n";
}

void BinaryTree::postordenado_print() {
	postordenado_print(raiz);
	cout << "\n";
}

void BinaryTree::postordenado_print(Node*rama) {
	if (rama != nullptr) {
		enorden_print(rama->izquierda);
		enorden_print(rama->derecha);
		cout << rama->Dato << "," << rama->Nombre << "," << rama->Apellido << ",";
	}
}

void BinaryTree::preordenado_print() {
	preordenado_print(raiz);
	cout << "\n";
}

void BinaryTree::preordenado_print(Node*rama) {
	if (rama != nullptr) {
		cout << rama->Dato << ",";
		enorden_print(rama->izquierda);
		enorden_print(rama->derecha);
	}
}