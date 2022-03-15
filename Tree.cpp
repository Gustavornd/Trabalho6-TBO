#include "Tree.h"

/*
* Função de inicialização da árvore;
*/
Tree::Tree() {
	raiz = NULL;
}


/*
* Função que apaga a árvore binária e faz a limpeza da memória;
*/
Tree::~Tree() {
	if (raiz)
		Apaga(raiz);
}


/*
* Função que imprime os elementos da árvore em pré-Ordem;
*/
void Tree::PreOrdem() const {
	raiz->PreOrdem();
	cout << endl;
}


/*
* Função que apaga um nodo da árvore;
*
* @param nodePtr		Ponteiro para o nodo que deve ser apagado;
*/
void Tree::Apaga(Nodo* nodePtr) {
	if (nodePtr->left)
		Apaga(nodePtr->left);
	if (nodePtr->right)
		Apaga(nodePtr->right);
	cout << "\n\t!" << nodePtr->data;
	delete nodePtr;
}


/*
* Cria e insere um novo nodo na árvore a partir
* de um dado informado;
*
* @param data			Dado que será inserido na árvore;
*/
void Tree::Insere(int data) {
	Nodo* newNodoPtr = new Nodo(data);
	Nodo* ptrNodoAtual = raiz;

	if (!raiz) {
		raiz = newNodoPtr;
		return;
	}

	while (true) {
		if (ptrNodoAtual->data < data) {
			if (ptrNodoAtual->right)
				ptrNodoAtual = ptrNodoAtual->right;
			else {
				ptrNodoAtual->right = newNodoPtr;
				return;
			}
		}
		else {
			if (ptrNodoAtual->left)
				ptrNodoAtual = ptrNodoAtual->left;
			else {
				ptrNodoAtual->left = newNodoPtr;
				return;
			}
		}
	}
}


/*
* Realiza a busca binária na árvore pelo valor informado
* e retorna o nodo caso seja localizado;
*
* @param data			Dado que será buscado na árvore;
*/
Nodo Tree::Busca_Binaria(int data){
	Nodo* ptrNodoAtual = raiz;
	if (ptrNodoAtual) {
		while (ptrNodoAtual) {
			cout << "<" << ptrNodoAtual->data << "> ";
			if (ptrNodoAtual->data == data) {
				cout << endl;
				return *ptrNodoAtual;
			}
			else if (ptrNodoAtual->data < data)
				ptrNodoAtual = ptrNodoAtual->right;
			else
				ptrNodoAtual = ptrNodoAtual->left;
		}
		cout << "Erro!!!" << endl;
		return NULL;
	}
	else {
		cout << "Árvore Vazia!!!" << endl;
		return NULL;
	}
}
