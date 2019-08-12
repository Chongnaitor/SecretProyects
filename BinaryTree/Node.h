#pragma once
#include<string>
using std::string;
struct Node {
	int Dato;
	string Nombre;
	string Apellido;
	Node *izquierda;
	Node *derecha;
	bool operator<(Node*raiz)
	{
		if (raiz->Apellido == this->Apellido)
		{
			if (raiz->Nombre == this->Nombre)
			{
				return raiz->Dato < this->Dato;
			}
			else
			{
				 return raiz->Nombre < this->Nombre;
			}

		}
		return raiz->Apellido < this->Apellido;
	}
	bool operator>(Node*raiz)
	{
		if (raiz->Apellido == this->Apellido)
		{
			if (raiz->Nombre == this->Nombre)
			{
				return raiz->Dato > this->Dato;
			}
			else
			{
				return raiz->Nombre > this->Nombre;
			}

		}
		return raiz->Apellido > this->Apellido;
	}
};