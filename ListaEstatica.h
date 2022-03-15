#pragma once
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#define TAM_LINHA 5000
#define MAX_TAM 1000

using namespace std;

/*
* Classe que guarda uma lista Estatica de elementos do
* tipo Int;
*/
class ListaEstatica {
public:
	/*
	* Fun��o de incializa��o de lista vazia.
	*/
	ListaEstatica() { tamanho = 0; };

	/*
	* Fun��o que inicializa uma lista com dados lidos em aquivo
	* 
	* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
	*/
	ListaEstatica(string file_name);

	/*
	* Fun��o que inicializa uma lista com dados aleat�rios, com o
	* tamanho definido;
	* 
	* @param tam		N�mero de elementos da lista (tamanho) que deve ser gerada
	*/
	ListaEstatica(unsigned tam);

	/*
	* Fun��o destrutora da classe (N�o Implementada)
	*/
	~ListaEstatica();

	/*
	* Fun��o que faz a inser��o de um novo elemento na lista,
	* na posi��o indicada.
	* 
	* @param posicao		Posi��o onde o elemento deve ser inserido;
	* @param valor			Valor do elemento que ser� inserido na lista;
	*/
	void Inserir(unsigned posicao, int valor);

	/*
	* Fun��o que realiza uma busca na lista por um valor especificado,
	* retornando sua posi��o;
	* 
	* @param valor		Valor que deve ser buscado na lista 
	*/
	int Buscar(int valor);

	/*
	* Fun��o que realiza a busca pelo menor elemento da lista,
	* retornando sua posi��o.
	*/
	int BuscarMenor();

	/*
	* Fun��o que realiza a troca de elementos nas posi��es indicadas
	* 
	* @param posicao1		Posi��o do primeiro elemento;
	* @patam posicao2		Posi��o do segundo elemento;
	*/
	bool Swap(unsigned posicao1, unsigned posicao2);

	/*
	* Fun��o que faz a impress�o dos elementos na tela
	*/
	void print();

	/*
	* Fun��o que faz a impress�o dos elementos na tela em sentido inverso.
	*/
	void printInvertido();

	/*
	* Atributos da classe ListaEstatica;
	*/
	int dados[MAX_TAM] = {0};
	int tamanho;
};

#endif // !LISTA_ESTATICA_H

