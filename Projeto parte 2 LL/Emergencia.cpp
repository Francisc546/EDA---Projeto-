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
			aux->vagas++;
			removido = true;
		}
		else {
			while (!removido && iterator->seguinte != NULL ) {
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
						aux->vagas++;
						removido = true;
					}
					else {
						iterator->seguinte = iterator->seguinte->seguinte;
						delete remover;
						aux->vagas++;
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


Mesa * removegrupoEmergencia(Mesa * mesas, int numerogrupo, int custo){
	Mesa * aux = mesas;
	while (aux != NULL) {
		identidade * iterator = aux->pessoas;
		while (iterator != NULL) {
			if (iterator->numerogrupo == numerogrupo) {
				cout << "-------------------------------------------------------------------" << endl;
				cout << iterator->primeironome << " " << iterator->ultimonome << " Plafond: " << iterator->plafond - custo << endl;
				cout << "-------------------------------------------------------------------" << endl;
				removeElemento(mesas, iterator->numeroid,custo);
				iterator = iterator->seguinte;
			}
			else {

				iterator = iterator->seguinte;
			}
		}
		aux = aux->seguinte;
	}
	return mesas;
}

