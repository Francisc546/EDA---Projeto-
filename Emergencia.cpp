#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"


void apagaElmentoMesaEspera(identidade * ocupantes, int indiceRemover, int tamanho) {
	identidade *  f_temp = new identidade[tamanho];
	for (int i = tamanho; i < tamanho; i++) {
		ocupantes[i - indiceRemover] = ocupantes[i];
	}
	for (int i = tamanho - 1; i >= tamanho - indiceRemover; i--)
		ocupantes[i] = f_temp[i];

}





void removeElemento(Mesa * cantina, int id, int numeromesas, int custoref) {
	int i = 0;
	while (i < numeromesas) {
		cout << "Vagas: " << cantina[i].vagas << endl;
		for (int j = 0; j < cantina[i].tamanho; j++) {
			if (cantina[i].pessoas[j].numeroid == id) {
				cout << "*****************ELEMENTO REMOVIDO***********************" << endl << endl;
				cout << "Identidade Removida: " << cantina[i].pessoas[j].primeironome << " " << cantina[i].pessoas[j].ultimonome << " | Plafond: " << cantina[i].pessoas[j].plafond - custoref << endl;
				cout << "*********************************************************" << endl;
				//for (int r = j; r < cantina[i].tamanho - 1; r++) {
					//cantina[i].pessoas[r] = cantina[i].pessoas[r + 1];
				apagaElmentoMesaEspera(cantina[i].pessoas, j, cantina[i].tamanho);
				break;

				//}
			}
		}
		i++;
	}
}

