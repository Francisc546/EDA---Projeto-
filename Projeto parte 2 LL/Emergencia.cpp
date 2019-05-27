#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"
#include "Emergencia.h"
using namespace std;

Mesa * removeElemento(Mesa* mesas, int id, int custo) {
	Mesa * aux = mesas;
	bool removido = false;
	while (aux != NULL && !removido) {
		identidade * iterator = aux->pessoas;

		if (aux->pessoas->numeroid == id) {
			aux->pessoas = aux->pessoas->seguinte;
			removido = true;
		}
		else {
			while (iterator->seguinte != NULL && !removido) {
				if (iterator->seguinte->numeroid == id) {
					cout << "--------------------------------------------------------" << endl;
					cout << "Identidade Removida: " << iterator->seguinte->primeironome << " " << iterator->seguinte->ultimonome << " Plafond: " << iterator->seguinte->plafond - custo << endl;
					cout << "--------------------------------------------------------" << endl;

					/*identidade * remover = iterator->seguinte;
					cout << "Probelma " <<( iterator->seguinte->seguinte == NULL);
					iterator->seguinte = iterator->seguinte->seguinte;
					delete remover;
					removido = true;*/

					identidade * remover = iterator->seguinte;
					if (iterator->seguinte->seguinte == NULL) {
						iterator->seguinte = NULL;
						delete remover;
						removido = true;
					}
					else {
						iterator->seguinte = iterator->seguinte->seguinte;
						delete remover;
						removido = true;
					}
					
					

				}
				iterator = iterator->seguinte;
			}
		}
		aux = aux->seguinte;
	}
	return mesas;
}

Mesa * removegrupo(Mesa* mesas, int numerogrupo) {
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * aux2 = aux->pessoas;
		while (aux2 != NULL) {
			if (aux2->numerogrupo == numerogrupo) {
				identidade * aux3 = aux2;
				while (aux3->numerogrupo == numerogrupo) {
					aux3 = aux3->seguinte;
					
				}
				aux2 = aux3->seguinte;
				delete aux3;
			}
			aux2 = aux2->seguinte;
		}
		aux = aux->seguinte;
	}
	return mesas;
}

