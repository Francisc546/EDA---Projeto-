#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"

void apagagrupo(identidade * ocupantes, int numerogrupo, int tamanho) {
	identidade * aux = new identidade[tamanho];
	for (int i = 0; i < tamanho; i++) {
		ocupantes[i] = aux[i];
	}
}




void apagaElmentoMesaEspera(identidade * ocupantes, int indiceRemover, int tamanho) {

	for (int i = indiceRemover; i < tamanho - 1; i++) {
		ocupantes[i] = ocupantes[i + 1];
	}
}





void removeElemento(Mesa * cantina, int id, int numeromesas, int custoref) {
	int i = 0;
	while (i < numeromesas) {
		//cout << "Vagas: " << cantina[i].vagas << endl;
		for (int j = 0; j < cantina[i].tamanho; j++) {
			if (cantina[i].pessoas[j].numeroid == id) {
				cout << "*****************ELEMENTO REMOVIDO***********************" << endl << endl;
				cout << "Identidade Removida: " << cantina[i].pessoas[j].primeironome << " " << cantina[i].pessoas[j].ultimonome << " | Plafond: " << cantina[i].pessoas[j].plafond - custoref << endl;
				cout << "*********************************************************" << endl;
				
				apagaElmentoMesaEspera(cantina[i].pessoas, j, cantina[i].tamanho);
				identidade   f_temp;
				cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas - 1] = f_temp;
				cantina[i].vagas++;
				
			}
		}
		i++;
	}
}

void removeGrupo(Mesa * cantina, int numerogrupo, int numeromesas, int custoref) {
	int i = 0;
	while (i < numeromesas) {
		//cout << "Vagas: " << cantina[i].vagas << endl;
		for (int j = 0; j < cantina[i].tamanho; j++) {
			while (cantina[i].pessoas[j].numerogrupo == numerogrupo) {
				cout << "*****************ELEMENTO REMOVIDO***********************" << endl << endl;
				cout << "Identidade Removida: " << cantina[i].pessoas[j].primeironome << " " << cantina[i].pessoas[j].ultimonome << " | Plafond: " << cantina[i].pessoas[j].plafond - custoref << endl;
				cout << "*********************************************************" << endl;

				apagaElmentoMesaEspera(cantina[i].pessoas, j, cantina[i].tamanho);
				identidade   f_temp;
				cantina[i].pessoas[cantina[i].tamanho - cantina[i].vagas - 1] = f_temp;
				cantina[i].vagas++;

			}
		}
		i++;
	}
}
