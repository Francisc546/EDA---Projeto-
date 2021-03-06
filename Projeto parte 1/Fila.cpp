#include "Cantina.h"
#include <iostream>
#include <fstream>
#include <string>





int adicionafila(identidade * filadeespera, int posicaovazia, string * pNome, string * uNome, string * cursos) {
	bool tipo = true;
	tipo = decide(tipo); // decide qual vai o tipo do grupo (aluno ou staff)
	int elementos = rand() % 10 + 1; // numero de elementos do grupo
	//criagrupo(pNome, uNome, cursos, elementos,tipo);
	int numerogrup = rand() % 400 + 100;

	if (posicaovazia > 50 - 10)
		elementos = 50 - posicaovazia;

	
	identidade * novogrupo = criagrupo(pNome, uNome, cursos, elementos, tipo, numerogrup); // cria o grupo
	

	for (int i = 0; i < elementos && (posicaovazia + i < 50); i++) {
		filadeespera[posicaovazia] = novogrupo[i]; //adiciona o grupo a posicao vazia;
		posicaovazia++;

	}



	return posicaovazia - 1;

}



void imprimeFila(identidade * filadeespera, int tamanho) {
	cout << "******************FILA DE ESPERA*************************" << endl << endl;
	for (int i = 0; i < tamanho; i++) {
		//if (filadeespera[i].special == 0) {
			if (filadeespera[i].tipo == 1) { // se for aluno

				cout << " -> " << "ALUNO" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Grupo: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
			}
			else { // se for staff
				cout << " -> " << "STAFF" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Departamento: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;
			}
		
		/*else {
			if (filadeespera[i].tipo == 1)

				cout << " -> " << "ALUNO ESPECIAL" << ", " << filadeespera[i].primeironome << " " << filadeespera[i].ultimonome << ", " << filadeespera[i].curso << ", " << filadeespera[i].numeroid << ", Grupo: " << filadeespera[i].numerogrupo << ", " << filadeespera[i].plafond << " euros, (Duracao: " << filadeespera[i].duracao << ")" << endl;


		}*/




	}
}

void apagaFilaEspera(identidade * f, int n_elem) {
	identidade *  f_temp = new identidade[50];
	for (int i = n_elem; i < 50; i++) {
		f[i - n_elem] = f[i];
	}
	for (int i = 50-1; i >= 50 - n_elem; i--)
		f[i] = f_temp[i];
}

int apagaElementoFilaespera(identidade * filadeespera, int custo) {
	int valoresremovidos = 0;
	int num_elementos = filadeespera[0].n_elementos;
	for (int j = 0; j < num_elementos - 1; j++) {
		if (filadeespera[j].plafond < custo) {

			//cout << "Apagando elemento" << endl;
			for (int i = j; i < 48; i++) {
				filadeespera[i] = filadeespera[i + 1];
			}
			valoresremovidos++;
			//	j++;
		}

	}
	
	atualizagrupo(filadeespera, filadeespera[0].numerogrupo, num_elementos - valoresremovidos); // atualiza o numero de elementos do grupo;

	return valoresremovidos;
}