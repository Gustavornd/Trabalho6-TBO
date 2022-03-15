#pragma once
#ifndef TREE_H
#define TREE_H

#include "Nodo.h"


/*
* Classe que implementa uma �rvore de busca bin�ria 
* com elementos do tipo int;
*/
class Tree {
public:


	/*
	* Fun��o de inicializa��o da �rvore;
	*/
	Tree();


	/*
	* Fun��o que apaga a �rvore bin�ria e faz a limpeza da mem�ria;
	*/
	~Tree();


	/*
	* Fun��o que imprime os elementos da �rvore em pr�-Ordem;
	*/
	void PreOrdem() const;


	/*
	* Fun��o que apaga um nodo da �rvore;
	* 
	* @param nodePtr		Ponteiro para o nodo que deve ser apagado;		
	*/
	void Apaga(Nodo* nodePtr);


	/*
	* Cria e insere um novo nodo na �rvore a partir
	* de um dado informado;
	* 
	* @param data			Dado que ser� inserido na �rvore;
	*/
	void Insere(int data);


	/*
	* Realiza a busca bin�ria na �rvore pelo valor informado
	* e retorna o nodo caso seja localizado;
	* 
	* @param data			Dado que ser� buscado na �rvore;
	*/
	Nodo Busca_Binaria(int data);


	/*
	* Atributos da classe ListaEstatica;
	*/
	Nodo* raiz;
};



#endif // !TREE_H

