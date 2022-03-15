#pragma once
#ifndef TREE_H
#define TREE_H

#include "Nodo.h"


/*
* Classe que implementa uma árvore de busca binária 
* com elementos do tipo int;
*/
class Tree {
public:


	/*
	* Função de inicialização da árvore;
	*/
	Tree();


	/*
	* Função que apaga a árvore binária e faz a limpeza da memória;
	*/
	~Tree();


	/*
	* Função que imprime os elementos da árvore em pré-Ordem;
	*/
	void PreOrdem() const;


	/*
	* Função que apaga um nodo da árvore;
	* 
	* @param nodePtr		Ponteiro para o nodo que deve ser apagado;		
	*/
	void Apaga(Nodo* nodePtr);


	/*
	* Cria e insere um novo nodo na árvore a partir
	* de um dado informado;
	* 
	* @param data			Dado que será inserido na árvore;
	*/
	void Insere(int data);


	/*
	* Realiza a busca binária na árvore pelo valor informado
	* e retorna o nodo caso seja localizado;
	* 
	* @param data			Dado que será buscado na árvore;
	*/
	Nodo Busca_Binaria(int data);


	/*
	* Atributos da classe ListaEstatica;
	*/
	Nodo* raiz;
};



#endif // !TREE_H

