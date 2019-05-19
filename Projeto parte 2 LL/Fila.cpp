#include <iostream>
#include "Cantina.h"
using namespace std;

int retornapos(identidade * filadeespera, int custo) {
	int count = 0;
	int num_grupo = filadeespera->numerogrupo;
	identidade * aux = filadeespera;
	while (aux->numerogrupo == num_grupo) {
		if (aux->plafond < custo) {
			return count;
			break;
		}
		count++;
		aux = aux->seguinte;
	}
}


identidade * removerInicio(identidade * filadeespera) {
	identidade * aux = filadeespera;
	filadeespera = filadeespera->seguinte;
	delete aux;
	return filadeespera;
}

void removerFim(identidade * filadeespera) {
	identidade * iterator = filadeespera;

	while (iterator->seguinte->seguinte != NULL) {
		iterator = iterator->seguinte;
	}

	identidade * aux = iterator->seguinte;
	iterator->seguinte = NULL;
	delete aux;
}


int comprimento(identidade * filadeespera) {
	int contador = 0;
	identidade * aux = filadeespera;
	int numerogrupo = filadeespera->numerogrupo;
	while (aux->numerogrupo == numerogrupo)//enquanto não chegar ao fim da LL
	{
		contador++;
		aux = aux->seguinte; //vai para o nodo seguinte
	}
	return contador;
}


identidade * removerPos(identidade * filadeespera, int pos) {
	int tamanho = comprimento(filadeespera);
	if (pos == 0) {
		return removerInicio(filadeespera);
	}
	else if (pos == tamanho) {
		removerFim(filadeespera);
		return filadeespera;
	}
	else if (pos > tamanho) {
		cout << " erro fim de lista " << pos << tamanho << endl;
		return filadeespera;
	}
	else {
		identidade * iterator = filadeespera;
		int pos_count = 1;
		while (iterator->seguinte != NULL && pos != pos_count) {
			iterator = iterator->seguinte;
			pos_count++;
		}
		identidade * aux = iterator->seguinte;
		iterator->seguinte = iterator->seguinte->seguinte;
		delete aux;
		return filadeespera;
	}
}


void removeGrupo(identidade * filadeespera) {
	int num_grupo = filadeespera->numerogrupo;
	identidade * aux = filadeespera;
	while (aux->seguinte->numerogrupo == num_grupo) {
		aux = aux->seguinte;
		
	}
	identidade * iterator = aux->seguinte;
	aux->seguinte = aux->seguinte->seguinte;
	filadeespera = aux->seguinte;
	delete aux;
	
}

