#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
#include "Ficheiros.h"
#include "Fila.h"
#include "Opcoes.h";
#include <Windows.h>

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


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


identidade * alteraduracaofila(identidade * filadeespera, int numgrupo, int duracao) {
	identidade * aux = filadeespera;
	while (aux != NULL) {
		if (aux->numerogrupo == numgrupo) {
			while (aux->numerogrupo == numgrupo) {

				aux->duracao = duracao;
				aux = aux->seguinte;


			}

		}

		aux = aux->seguinte;
	}
	return filadeespera;
}

Mesa * alteraduracaomesas(Mesa * mesas, int numgrupo, int duracao) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * iterator = aux->pessoas;
		while (iterator != NULL) {
			if (iterator->numerogrupo == numgrupo) {
				iterator->duracao = duracao;
			}
			iterator = iterator->seguinte;
		}
		aux = aux->seguinte;
	}
	return mesas;
}

identidade * alterarnome(identidade * filadeespera, int id, string pnome, string unome) {
	identidade * aux = filadeespera;
	while (aux != NULL) {
		if (aux->numeroid == id) {
			aux->primeironome = pnome;
			aux->ultimonome = unome;
			break;
		}
		aux = aux->seguinte;

	}
	return filadeespera;
}

Mesa * alterarnome2(Mesa* mesas, int id, string pnome, string unome) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * iterator = aux->pessoas;
		while (iterator != NULL) {
			if (iterator->numeroid == id) {
				iterator->primeironome = pnome;
				iterator->ultimonome = unome;
				break;
			}
			iterator = iterator->seguinte;
		}
		aux = aux->seguinte;
	}
	return mesas;
}

void imprime(identidade * filadeespera, int departamento) {
	identidade * aux = filadeespera;
	while (aux != NULL) {
		if (aux->numerogrupo == departamento) {
			cout << "Identidade: " << aux->primeironome << " " << aux->ultimonome << " Plafond:" << aux->plafond << endl;

		}
		aux = aux->seguinte;
	}

}

void imprime2(identidade * filadeespera, string curso) {
	identidade * aux = filadeespera;
	while (aux != NULL) {
		if (aux->curso == curso) {
			cout << "Identidade: " << aux->primeironome << " " << aux->ultimonome << " Plafond:" << aux->plafond << endl;

		}
		aux = aux->seguinte;
	}

}


void imprimemesa(Mesa * mesas, int departamento) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * aux2 = aux->pessoas;
		while (aux2 != NULL) {
			if (aux2->numerogrupo == departamento) {
				cout << "Identidade: " << aux2->primeironome << " " << aux2->ultimonome << " Plafond:" << aux2->plafond << endl;
			}
			aux2 = aux2->seguinte;
		}
		aux = aux->seguinte;
	}
}


void imprimemesa2(Mesa * mesas, string curso) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * aux2 = aux->pessoas;
		while (aux2 != NULL) {
			if (aux2->curso == curso) {
				cout << "Identidade: " << aux2->primeironome << " " << aux2->ultimonome << " Plafond:" << aux2->plafond << endl;
			}
			aux2 = aux2->seguinte;
		}
		aux = aux->seguinte;
	}
}



void imprime3(identidade * filadeespera, int id) {
	identidade * aux = filadeespera;
	while (aux != NULL) {
		if (aux->numeroid == id) {
			if (aux->tipo = 1) {
				cout << "Identidade: " << aux->primeironome << " " << aux->ultimonome << " Curso: " << aux->curso << " Numero de grupo: " << aux->numerogrupo << " Plafond:" << aux->plafond << endl;
			}
			else {
				cout << "Identidade: " << aux->primeironome << " " << aux->ultimonome <<  " Departamento: " << aux->numerogrupo << " Plafond:" << aux->plafond << endl;
			}
		}
		aux = aux->seguinte;
	}


}

void imprimemesa3(Mesa * mesas, int id) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * aux2 = aux->pessoas;
		while (aux2 != NULL) {
			if (aux2->numeroid == id) {
				if (aux2->tipo == 1) {
					cout << "Identidade: " << aux2->primeironome << " " << aux2->ultimonome << " Curso: " << aux2->curso << " Numero de grupo: " << aux2->numerogrupo << " Plafond:" << aux2->plafond << endl;

				}
				else {
					cout << "Identidade: " << aux2->primeironome << " " << aux2->ultimonome << " Departamento: " << aux2->numerogrupo << " Plafond:" << aux2->plafond << endl;
				}

				
			}
			aux2 = aux2->seguinte;
		}
		aux = aux->seguinte;
	}
}

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

void bbubblesort(int id[], string * a, int n) {
	bool swapped = true;
	for (int i = 0; i < n - 1 && swapped; i++) {
		swapped = false;
		for (int j = n - 1; j > i; j--) {
			if (a[j] <= a[j - 1]) {
				swap(a[j], a[j - 1]);
				swap(id[j], id[j - 1]);
				swapped = true;
			}
		}
	}

}

void imprimePRIMOS(Mesa*mesas, identidade * filadeespera, int id) {
	Mesa*aux = mesas;
	identidade*aux3 = filadeespera;
	bool printed = false;
	while (aux != NULL) {
		identidade * aux2 = aux->pessoas;
		while (!printed && aux2 != NULL) {
			if (aux2->numeroid == id) {
				if (aux2->tipo == 0) {
					SetConsoleTextAttribute(color, 7);
					cout << aux2->entidade << aux2->primeironome << " ";
					SetConsoleTextAttribute(color, 4);
					cout << aux2->ultimonome;
					SetConsoleTextAttribute(color, 7);
					cout << " , Departamento " << aux2->numerogrupo << " | " << aux2->numeroid << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;
				}
				else {
					SetConsoleTextAttribute(color, 7);
					cout << aux2->entidade << aux2->primeironome << " ";
					SetConsoleTextAttribute(color, 4);
					cout << aux2->ultimonome;
					SetConsoleTextAttribute(color, 7);
					cout << " , grupo " << aux2->numerogrupo << " | " << aux2->numeroid << " | " << aux2->curso << " | (ciclos restantes: " << aux2->duracao << ") Plafond : " << aux2->plafond << endl;

				}printed = true;
			}
			else {
				aux2 = aux2->seguinte;
			}
		}
		aux = aux->seguinte;
	}
	while (!printed &&aux3 != NULL) {
		if (aux3->numeroid == id) {
			if (aux3->tipo == 0) {
				SetConsoleTextAttribute(color, 7);
				cout << aux3->entidade << aux3->primeironome << " ";
				SetConsoleTextAttribute(color, 4);
				cout << aux3->ultimonome;
				SetConsoleTextAttribute(color, 7);
				cout << " , Departamento " << aux3->numerogrupo << " | " << aux3->numeroid << " | (ciclos restantes: " << aux3->duracao << ") Plafond : " << aux3->plafond << endl;
			}
			else {
				SetConsoleTextAttribute(color, 7);
				cout << aux3->entidade << aux3->primeironome << " ";
				SetConsoleTextAttribute(color, 4);
				cout << aux3->ultimonome;
				SetConsoleTextAttribute(color, 7);
				cout << " , grupo " << aux3->numerogrupo << " | " << aux3->numeroid << " | " << aux3->curso << " | (ciclos restantes: " << aux3->duracao << ") Plafond : " << aux3->plafond << endl;
			}
			printed = true;
		}
		else {
			aux3 = aux3->seguinte;
		}

	}
}

void imprimeMesa2(Mesa * mesas, int nMesa) {
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


void ordenaFmaisM(identidade * filadeespera, Mesa * mesas) { //Para ordenadar a fila de espera e as mesas por ordem alfabética do último nome juntos
	identidade * auxF = filadeespera;
	identidade * auxF2 = filadeespera;

	Mesa * auxM2 = mesas;
	int iiid = 0;
	Mesa * auxM3 = mesas;
	int nMesas = 0;
	int nFiladeespera = 0;
	int i = 0;
	identidade * auxdelete = auxM2->pessoas;
	identidade * auxdelete2 = auxM2->pessoas;
	// Mesas
	while (auxM2 != NULL) {   //Passa  os últimos nomes das mesas para o array

		if (auxdelete != NULL) { //Ve mesa a mesa
			auxdelete = auxdelete->seguinte;
			nMesas++;

		}

		else if (auxM2->seguinte == NULL) //Verifica se a próxima mesa é a última para não sair fora da lista ligada o auxdelete
		{
			auxM2 = auxM2->seguinte;
			delete auxdelete;
		}

		else if (auxM2 != NULL) { // Passa para a mesa seguinte
			delete auxdelete;

			auxM2 = auxM2->seguinte;
			auxdelete = auxM2->pessoas;


		}

	}
	// Fila de espera
	while (auxF != NULL) { //Contando o nº de elementos da fila de espera

		auxF = auxF->seguinte;
		nFiladeespera++;

	}
	string * array = new string[nFiladeespera + nMesas];
	int * id = new int[nFiladeespera + nMesas];
	while (auxF2 != NULL) {  // Passa os últimos nome dos membros da fila de espera para o array
		array[i] = auxF2->ultimonome;
		id[i] = auxF2->numeroid;
		i++;
		auxF2 = auxF2->seguinte;

	}

	while (auxM3 != NULL) {   //Passa  os últimos nomes das mesas para o array

		if (auxdelete2 != NULL) { //Ve mesa a mesa
			array[i] = auxdelete2->ultimonome;
			id[i] = auxdelete2->numeroid;
			auxdelete2 = auxdelete2->seguinte;
			i++;

		}

		else if (auxM3->seguinte == NULL) //Verifica se a próxima mesa é a última para não sair fora da lista ligada o auxdelete
		{
			auxM3 = auxM3->seguinte;
			delete auxdelete2;
		}

		else if (auxM3 != NULL) { // Passa para a mesa seguinte
			delete auxdelete2;
			auxM3 = auxM3->seguinte;
			auxdelete2 = auxM3->pessoas;
		}
	}
	/*cout << "Desordenado :" << endl;
	cout << endl;
	for (int j = 0; j < nFiladeespera + nMesas; j++) {
		cout << array[j] << endl;
	}
	*/
	cout << endl << "Ordenado :" << endl;
	cout << endl;
	bbubblesort(id, array, nMesas + nFiladeespera);
	for (int j = 0; j < nFiladeespera + nMesas; j++) {
		iiid = id[j];
		imprimePRIMOS(mesas, filadeespera, iiid);
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
		imprimeMesa2(mesas, nMesas[j]);
	}
}
