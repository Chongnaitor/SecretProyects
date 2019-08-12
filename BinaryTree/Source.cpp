#include <iostream>
#include<string>
using namespace std;
#include "Tree.h"
#include "TreeT.h"
int tamaño(Node* Node);
bool Balance(Node *raiz)
{
	int lh; 
	int rh;
	
	if (raiz == nullptr)
	{
		return true;
		cout << "Esta balanceado" << endl;
	}
		

	lh = tamaño(raiz->izquierda);
	rh = tamaño(raiz->derecha);

	if (abs(lh - rh) <= 1 && Balance(raiz->izquierda) && Balance(raiz->derecha))
	{
		return true;
		cout << "Esta balanceado" << endl;
	}
		
	return false;
	cout << "Esta desbalanceado" << endl;
}
int max(int a, int b)
{
	return (a >= b) ? a : b;
}
int tamaño(Node* Node)
{
	if (Node == nullptr)
		return 0;


	return 1 + max(tamaño(Node->izquierda),
		tamaño(Node->derecha));
}
void MenuPersona() {
	BinaryTree *tree = new BinaryTree();
	
	tree->usuarioInsert(tree);
	tree->preordenado_print();
	tree->enorden_print();
	tree->postordenado_print();

	cout << "De sea borrar un Node?" << endl;
	string temp;
	cin >> temp;
	if (temp == "si" || temp == "SI" || temp == "Si")
	{
		cout << "Ponga el apellido de la persona que quiera sacar" << endl;
		cin >> temp;
		tree->BorrarNode(tree->raiz, temp);
		cout << "Node eliminado" << endl;
	}
	cin.ignore();
	cin.get();
	delete tree;

}
void MenuTemplate()
{


}
template<class Type>
int main()
{
	


}
