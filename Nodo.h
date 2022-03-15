#pragma once
#ifndef NODO_H
#define NODO_H

#include "ListaEstatica.h"


/*
* Classe que implementa os nodos membros da árvore binária
*/
class Nodo {
public: 
	
	/*
	* Função que cria um nodo com um dado informado;
	* 
	* @param newData		Dado que será guardado pelo novo nodo;
	*/
	Nodo(int newData);


	/*
	* Função que cria um nodo vazio;
	*/
	Nodo();


	/*
	* Função que apaga um nodo criado (Não implementado);
	*/
	~Nodo();


	/*
	* Função que imprime nodos em pré-ordem de forma recursiva;
	*/
	void PreOrdem() const;


	/*
	* Imprime os dados armazenado em um nodo;
	*/
	void PrintData() const;

	/*
	* Atributos da classe Nodo;
	*/
	Nodo* right;
	Nodo* left;
	int data = 0;
};

#endif // !NODO_H

