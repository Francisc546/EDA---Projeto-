#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
#include "Ficheiros.h"
#include "Fila.h"

using namespace std;

void BubbleSort(int m[], int a[], int n)
{
	bool swapped = true;
	for (int i = 0; i < n - 1 && swapped; i++)
	{
		swapped = false;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] > a[j - 1])
			{
				swap(a[j], a[j - 1]);
				swap(m[j], m[j - 1]);
				swapped = true;
			}
		}
	}
}

void imprimeMesa(Mesa * mesas, int nMesa) {
	Mesa*aux = mesas;
	while (aux != NULL) {
		if (aux->numMesa == nMesa) {
			cout << "MESA N: " << aux->numMesa << "   TAMANHO:  " << aux->tamanho << endl;
			identidade * aux2 = aux->pessoas;
			while (aux2 != NULL) {
				if (aux2->tipo == 0)
					cout << aux2->entidade << aux2->primeironome << " , Departamento " << aux2->numerogrupo << " | " << aux2->numeroid << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;
				else
					cout << aux2->entidade << aux2->primeironome << " , grupo " << aux2->numerogrupo << " | " << aux2->numeroid << " | " << aux2->curso << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;
				aux2 = aux2->seguinte;
			}
		}
		aux = aux->seguinte;
	}

}

void ordena(Mesa*mesas) {
	Mesa * aux = mesas;
	Mesa * aux1 = mesas;
	int counter = 0;
	int i = 0;
	while (aux != NULL) {
		counter++;
		aux = aux->seguinte;
	}
	int * Vetor = new int[counter];
	int * nMesas = new int[counter];

	while (aux1 != NULL) {
		Vetor[i] = aux1->tamanho - aux1->vagas;
		nMesas[i] = aux1->numMesa;
		i++;
		aux1 = aux1->seguinte;
	}
	BubbleSort(nMesas, Vetor, counter);
	for (int j = 0; j < counter; j++) {
		imprimeMesa(mesas, nMesas[j]);
	}
}