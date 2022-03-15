#include "Nodo.h"

/*
* Função que cria um nodo com um dado informado;
*
* @param newData		Dado que será guardado pelo novo nodo;
*/
Nodo::Nodo(int  newData) {
	left = NULL;
	right = NULL;
	data = newData;
}


/*
* Função que cria um nodo vazio;
*/
Nodo::Nodo() {
	left = NULL;
	right = NULL;
}


/*
* Função que apaga um nodo criado (Não implementado);
*/
Nodo::~Nodo(){}


/*
* Função que imprime nodos em pré-ordem de forma recursiva;
*/
void Nodo::PreOrdem() const{
	cout << "<" << data << "> ";
	if (left)
		left->PreOrdem();
	if (right)
		right->PreOrdem();
}


/*
* Imprime os dados armazenado em um nodo;
*/
void Nodo::PrintData() const {
	if (!left && !right)
		cout << "Nodo: " << data << endl;
	else if (!left && right)
		cout << "<Nodo: " << data << "; Direita: " << right->data << ">" << endl;
	else if (left && !right)
		cout << "<Nodo: " << data << "; Esquerda: " << left->data << ">" << endl;
	else
		cout << "<Nodo: " << data << "; Esquerda: " << left->data << "; Direita: "
		<< right->data << ">" << endl;
}