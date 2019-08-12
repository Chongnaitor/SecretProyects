#pragma once
#include "Node.h"
class BinaryTree {
public:

	BinaryTree();
	~BinaryTree();
	void postordenado_print(Node *rama);
	void preordenado_print(Node *rama);
	void insert(int Dato, string Nombre, string Apellido);
	void destruir_tree();
	void enorden_print();
	void postordenado_print();
	void preordenado_print();
	void destruir_tree(Node *rama);
	void insert(int Dato, string Nombre, string Apellido, Node *rama);
	void enorden_print(Node *rama);
	void usuarioInsert(BinaryTree *raiz);
	Node*ValorMinimo(Node*raiz);
	Node*BorrarNode(Node*raiz, string Apellido);
	Node*DerechaADerechaR(Node*Padre);
	Node*IzquierdaAIzquierda(Node*Padre);
	Node* DerechaAIzquierda(Node*Padre);
	Node*IzquierdaADerecha(Node*Padre);
	Node *raiz;
};

/*avl 
avl *avl_tree::rl_rotat(avl *parent) {
	avl *t;
	t = parent->r;
	parent->r = ll_rotat(t);
	cout << "Right-Left Rotation";
	return rr_rotat(parent);
	}
avl *avl_tree::lr_rotat(avl *parent) {
	avl *t;
	t = parent->l;
	parent->l = rr_rotat(t);
	cout << "Left-Right Rotation";
	return ll_rotat(parent);
}

}*/