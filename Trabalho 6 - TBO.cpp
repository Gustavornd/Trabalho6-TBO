// Trabalho 6 - TBO.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <locale>
#include "Functions.h"
#include "ListaEstatica.h"
#include "Nodo.h"
#include "Tree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
	ListaEstatica l1("dados.txt");
	Tree t1;
    CreateInputFile();
	while (true) {
		unsigned opcao;

		system("cls");
		cout << "1. Criar árvore binária" << endl;
		cout << "2. Buscar um item na árvore" << endl;
		cout << "0. Sair." << endl;

		cout << "Escolha uma opção: ";
		cin >> opcao;

		if (opcao == 0)
			break;

		if (opcao == 1)
		{
			system("cls");
			cout << endl << "------------------CRIAR ARVORE DE BUSCA BINÁRIA--------------------" << endl << endl;

			for (int i=0; i < l1.tamanho; i++) {
				t1.Insere(l1.dados[i]);
			}

			t1.PreOrdem();
			system("pause");
		}

		
		if (opcao == 2) {
			system("cls");

			int i=0;
			cout << "Digite um número para ser pesquisado: ";
			cin >> i;
			Nodo resultado = t1.Busca_Binaria(i);
			resultado.PrintData();
			system("pause");
		}
	}


    
}
