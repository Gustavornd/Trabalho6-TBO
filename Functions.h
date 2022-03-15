#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "ListaEstatica.h"


using namespace std;

/*
* Fun��o usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile();

/*
* Fun��o usada para criar um aquivo de entrada com dados
* aleat�rios, mas n�o foi utilizado;
*/
void CreateRandomInputFile();


/*
* Fun��o que realiza a ordena��o da lista pelo m�todo
* Bubble Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int BubbleSort(ListaEstatica &Le, bool imprime_lista);


/*
* Fun��o que realiza a ordena��o da lista pelo m�todo
* Bubble Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int InsertionSort(ListaEstatica &le, bool imprime_lista);


/*
* Fun��o de chamada recursiva que realiza a ordena��o da lista pelo m�todo
*  Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param left				Primeira posi��o da lista � esquerda do piv�
* @param right				Primeira posi��o da lista � direita do piv�
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
void QuickSort(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista);


/*
* Fun��o divide a lista em duas � partir do piv� e realiza
* a troca das posi��es dos elementos da lista pelo m�todo
* para orden�-la pelo Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param left				Primeira posi��o da lista � esquerda do piv�
* @param right				Primeira posi��o da lista � direita do piv�
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int Partition(ListaEstatica	&le, int left, int right, int &acessos, bool imprime_lista);


/*
* Fun��o de chamada recursiva que realiza a restaura��o da
* propriedade de heap.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param i					Raiz da "�rvore" heap.
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
void Heapify(ListaEstatica &le, int i, int &acessos, bool imprime_lista);


/*
* Fun��o que realiza a convers�o da lista est�tica em um heap
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
void CreateHeap(ListaEstatica &le, int &acessos, bool imprime_lista);


/*
* Fun��o que realiza a ordena��o da lista pelo m�todo
* HeapSort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
void HeapSort(ListaEstatica &le, int &acessos, bool imprime_lista);

#endif // !FUNCTIONS_H



