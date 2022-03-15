#pragma once
#ifndef NODO_H
#define NODO_H

#include "ListaEstatica.h"


/*
* Classe que implementa os nodos membros da �rvore bin�ria
*/
class Nodo {
public: 
	
	/*
	* Fun��o que cria um nodo com um dado informado;
	* 
	* @param newData		Dado que ser� guardado pelo novo nodo;
	*/
	Nodo(int newData);


	/*
	* Fun��o que cria um nodo vazio;
	*/
	Nodo();


	/*
	* Fun��o que apaga um nodo criado (N�o implementado);
	*/
	~Nodo();


	/*
	* Fun��o que imprime nodos em pr�-ordem de forma recursiva;
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

