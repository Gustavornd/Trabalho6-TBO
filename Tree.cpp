#include "Tree.h"

/*
* Fun��o de inicializa��o da �rvore;
*/
Tree::Tree() {
	raiz = NULL;
}


/*
* Fun��o que apaga a �rvore bin�ria e faz a limpeza da mem�ria;
*/
Tree::~Tree() {
	if (raiz)
		Apaga(raiz);
}


/*
* Fun��o que imprime os elementos da �rvore em pr�-Ordem;
*/
void Tree::PreOrdem() const {
	raiz->PreOrdem();
	cout << endl;
}


/*
* Fun��o que apaga um nodo da �rvore;
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
* Cria e insere um novo nodo na �rvore a partir
* de um dado informado;
*
* @param data			Dado que ser� inserido na �rvore;
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
* Realiza a busca bin�ria na �rvore pelo valor informado
* e retorna o nodo caso seja localizado;
*
* @param data			Dado que ser� buscado na �rvore;
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
		cout << "�rvore Vazia!!!" << endl;
		return NULL;
	}
}
