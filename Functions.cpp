#include "Functions.h"




/*
* Função usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile() {
	fstream output;
	output.open("dados.txt", ios::out);

	if (!output)
		abort();

	output << "16" << endl;
	output << "31 6 90 91 40 10 7 21 78 14 22 17 20 55 68 39";

	output.close();
}


/*
* Função usada para criar um aquivo de entrada com dados
* aleatórios, mas não foi utilizado;
*/
void CreateRandomInputFile() {
	fstream output;
	output.open("dadosRadom.txt", ios::out);

	if (!output)
		abort();

	output << 100 << endl;

	for (unsigned i = 1; i <= 100; i++)
	{
		output << 1 + rand() % 1000 << " ";
	}

	output.close();
}




/*
* Função que realiza a ordenação da lista pelo método 
* Bubble Sort, ordenando a lista ordem crescente.
* 
* @param le					Lista encadeada estática que será ordenada
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
int BubbleSort(ListaEstatica &le, bool imprime_lista) {

	bool mudou = true;
	int n = le.tamanho;
	int aux = le.tamanho - 1;
	int acessos = 1;

	while (mudou) {
		mudou = false;
		for (int j = 0; j < n-1; j++) {
			if (le.dados[j] > le.dados[j + 1]) {
				mudou = true;
				aux = j;
				le.Swap(j, j + 1);
				acessos += 3;
			}
			acessos += 2;
		}
		n = aux + 1;
		if(imprime_lista)
			le.print();
	}

	if (!imprime_lista) {
		le.print();
	}
	return acessos;
}



/*
* Função que realiza a ordenação da lista pelo método
* Insertion Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada estática que será ordenada
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
int InsertionSort(ListaEstatica &le, bool imprie_lista) {
	int acessos = 1;
	for (int i = 1; i < le.tamanho; i++) {
		int j = i - 1;
		int valor = le.dados[i];
		acessos++;
		while ((j >= 0) && (valor < le.dados[j])) {
			le.dados[j + 1] = le.dados[j];
			acessos += 2;
			j--;
		}
		le.dados[j + 1] = valor;
		acessos++; 
		if(imprie_lista)
			le.print();
	}
	if (!imprie_lista)
		le.print();
	return acessos;
}




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
void QuickSort(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista) {
	acessos++;
	if (left < right) {
		int c = Partition(le, left, right, acessos, imprime_lista);
		QuickSort(le, left, c - 1, acessos, imprime_lista);
		QuickSort(le, c + 1, right, acessos, imprime_lista);
		acessos += 3;
	}
}



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
int Partition(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista)//1
{
	int c, i, pivo = le.dados[right];//1
	bool swap = false;
	acessos += 2; 

	c = (left - 1);

	for (i = left; i <= right - 1; i++){
		if (le.dados[i] < pivo){//1
			c++;
			swap = le.Swap(c, i);

			if (swap) {
				acessos = +3;
			}
			else {
				acessos++;
			}

			swap = false;
		}
	}
	swap = le.Swap(c+1,right);
	if (swap) {
		acessos += 3;
	}
	if (imprime_lista) {
		cout << pivo << "\t";
		le.print();
	}

	return c + 1;
}


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
void Heapify(ListaEstatica& le, int i, int &acessos, bool imprime_lista)
{
	bool swap = false;
	int g=i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((left < le.tamanho) && le.dados[left] > le.dados[i]) {
		g = left;
	}

	if ((right < le.tamanho) && le.dados[right] > le.dados[g]) {
		g = right;
	}

	if (g != i) {
		swap = le.Swap(i, g);
		if (swap) {
			acessos += 3;
		}
		if (imprime_lista) {
			le.print();
		}
		Heapify(le, g, acessos, imprime_lista);
	}
}


/*
* Função que realiza a conversão da lista estática em um heap
*
* @param le					Lista encadeada estática que será ordenada
* @param acessos			Variável externa para a contagem de acessos de memória
* @param imprime_lista		Indica se deve ser printada cada execução
*							da ordenação ou apenas a lista ordenada no
*							final da execução.
*/
void CreateHeap(ListaEstatica& le, int &acessos, bool imprime_lista) {
	for (int i = (le.tamanho/2)-1; i >= 0; i--) {
		Heapify(le, i, acessos, imprime_lista);
	}
}


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
void HeapSort(ListaEstatica& le, int &acessos, bool imprime_lista) {
	CreateHeap(le, acessos, imprime_lista);  
	bool swap = false;
	int aux = le.tamanho;
	for (int i = le.tamanho-1; i >= 1; i--) {
		swap = le.Swap(0, i);
		if (swap) {
			acessos += 3;
		}
		le.tamanho--;
		Heapify(le, 0, acessos, imprime_lista);
		swap = false;
	}
	le.tamanho = aux;
}
