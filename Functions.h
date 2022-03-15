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
* Função usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile();

/*
* Função usada para criar um aquivo de entrada com dados
* aleatórios, mas não foi utilizado;
*/
void CreateRandomInputFile();


/*
* Função que realiza a ordenação da lista pelo método
* Bubble Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
int BubbleSort(ListaEstatica &Le, bool imprime_lista);


/*
* Função que realiza a ordenação da lista pelo método
* Bubble Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
int InsertionSort(ListaEstatica &le, bool imprime_lista);


/*
* Função de chamada recursiva que realiza a ordenação da lista pelo método
*  Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param left				Primeira posição da lista à esquerda do pivô
* @param right				Primeira posição da lista à direita do pivô
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
void QuickSort(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista);


/*
* Função divide a lista em duas à partir do pivõ e realiza
* a troca das posições dos elementos da lista pelo método
* para ordená-la pelo Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param left				Primeira posição da lista à esquerda do pivô
* @param right				Primeira posição da lista à direita do pivô
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
int Partition(ListaEstatica	&le, int left, int right, int &acessos, bool imprime_lista);


/*
* Função de chamada recursiva que realiza a restauração da
* propriedade de heap.
*
* @param le					Lista encadeada estática que será ordenada
* @param i					Raiz da "árvore" heap.
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
void Heapify(ListaEstatica &le, int i, int &acessos, bool imprime_lista);


/*
* Função que realiza a conversão da lista estática em um heap
*
* @param le					Lista encadeada estática que será ordenada
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
void CreateHeap(ListaEstatica &le, int &acessos, bool imprime_lista);


/*
* Função que realiza a ordenação da lista pelo método
* HeapSort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
void HeapSort(ListaEstatica &le, int &acessos, bool imprime_lista);

#endif // !FUNCTIONS_H



