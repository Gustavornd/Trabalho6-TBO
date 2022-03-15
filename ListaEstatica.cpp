#pragma warning(disable: 4996)
#include "ListaEstatica.h"

/*
* Fun��o destrutora da classe (N�o Implementada)
*/
ListaEstatica::~ListaEstatica(){}


/*
* Fun��o que inicializa uma lista com dados lidos em aquivo
*
* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
*/
ListaEstatica::ListaEstatica(string file_name) {
	fstream input;
	input.open(file_name, ios::in);

	if (!input)
		abort();

	char linha[TAM_LINHA + 1];
	input.getline(linha, TAM_LINHA);
	tamanho = atoi(strtok(linha,"endl"));

	input.getline(linha, TAM_LINHA);
	dados[0] = atoi(strtok(linha, " "));
	for (unsigned i = 1; i < tamanho; i++){
		dados[i] = atoi(strtok(NULL, " "));
	}

	input.close();
}


/*
* Fun��o que inicializa uma lista com dados aleat�rios, com o
* tamanho definido;
*
* @param tam		N�mero de elementos da lista (tamanho) que deve ser gerada
*/
ListaEstatica::ListaEstatica(unsigned tam){
	tamanho = tam;
	int seed = 107140;
	cout << "Semente de gera��o da lista: " << seed << endl;
	srand(seed);

	for (unsigned i=0; i < tamanho; i++){
		dados[i] = 1 + rand() % 1000;
	}
}

/*
	* Fun��o que faz a inser��o de um novo elemento na lista,
	* na posi��o indicada.
	*
	* @param posicao		Posi��o onde o elemento deve ser inserido;
	* @param valor			Valor do elemento que ser� inserido na lista;
	*/
void ListaEstatica::Inserir(unsigned posicao, int valor) {
	if (posicao > tamanho){
		cout << "Posi��o Inv�lida!!!" << endl;
		return;
	}
	
	if (MAX_TAM == tamanho) {
		cout << "Lista Cheia!!!" << endl;
		return;
	}

	for (unsigned i = tamanho; i > posicao; i--) {
		dados[i] = dados[i - 1];
	}

	dados[posicao] = valor;
	tamanho++;
}

/*
	* Fun��o que realiza uma busca na lista por um valor especificado,
	* retornando sua posi��o;
	*
	* @param valor		Valor que deve ser buscado na lista
	*/
int ListaEstatica::Buscar(int valor) {
	unsigned acesso = 0;
	unsigned posicao = 0;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return -1;
	}

	while(posicao<tamanho){
		acesso++;
		if (dados[posicao] == valor) {
			cout << "Posi��o: " << posicao << endl;
			cout << "Acessos: " << acesso << endl << endl;
			return posicao;
		}
		posicao++;
	}

	cout << "N�o encontrado!!" << endl;
	cout << "Acessos: " << acesso << endl << endl;
	return -1;
}

/*
	* Fun��o que realiza a busca pelo menor elemento da lista,
	* retornando sua posi��o.
	*/
int ListaEstatica::BuscarMenor() {
	unsigned acesso = 0;
	unsigned posicao = 1;
	int menorValor, posicaoMenorValor = -1;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return -1;
	}

	acesso++;
	menorValor = dados[0];

	while (posicao < tamanho) {
		acesso++;
		if (menorValor > dados[posicao]) {
			menorValor = dados[posicao];
			posicaoMenorValor = posicao;
		}
		posicao++;
	}

	cout << "Menor valor: " << menorValor << endl;
	cout << "Posi��o: " << posicaoMenorValor << endl;
	cout << "Acessos: " << acesso << endl;
	return posicaoMenorValor;

}

/*
	* Fun��o que realiza a troca de elementos nas posi��es indicadas
	*
	* @param posicao1		Posi��o do primeiro elemento;
	* @patam posicao2		Posi��o do segundo elemento;
	*/
bool ListaEstatica::Swap(unsigned posicao1, unsigned posicao2) {
	int aux;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return false;
	}

	if (posicao1 == posicao2) {
		//cout << "As posi��es informadas s�o iguais!!!" << endl;
		return false;
	}

	if (posicao1 < tamanho && posicao2 < tamanho) {
		aux = dados[posicao1];
		dados[posicao1] = dados[posicao2];
		dados[posicao2] = aux;
		return true;
	}
	else {
		if(posicao1 > tamanho)
			cout << "Posi��o 1 Inv�lida!!!" << endl;
		if(posicao2 > tamanho)
			cout << "Posi��o 2 Inv�lida!!!" << endl;
		return false;
	}

}

/*
	* Fun��o que faz a impress�o dos elementos na tela
	*/
void ListaEstatica::print(){
	for (unsigned i = 0; i < tamanho; i++){
		cout << dados[i] << " ";
	}
	cout << endl;
}


/*
* Atributos da classe ListaEstatica;
*/
void ListaEstatica::printInvertido() {
	if (tamanho == 0){
		cout << "Lista Vazia!!" << endl;
	}
	else{
		for (unsigned i = tamanho; i > 0; i--){
			cout << dados[i - 1] << " ";
		}

		cout << endl;
	}
}
