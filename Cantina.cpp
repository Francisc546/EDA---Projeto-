#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
using namespace std;

void InsereRefeição(refeiçao * novaref) {
	cout << "**************REFEICAO NOVA*****************" << endl;
	cout << "Necessario uma nova refeicao, por favor atualize os seguintes dados" << endl;
	cout << "Introduza a entrada: ";
	getline(cin, novaref->entrada);
	cout << "Introduza o prato principal: ";
	getline(cin, novaref->principal);
	cout << "Introduza o custo da refeicao: ";
	cin >> novaref->custo;
}


void ImprimeRefeição(refeiçao * novaref) {
	cout << "Refeicao Atual: " << endl;
	cout << "\t Entrada: " << novaref->entrada << endl;
	cout << "\t Prato Principal: " << novaref->principal << endl;
	cout << "\t Custo: " << novaref->custo << " euros " << endl;

}
int contaLinhas(string filename) {
	int nLinhas = 0;
	ifstream file(filename);
	string temp = "";
	while (getline(file, temp)) {
		nLinhas++;
	}
	file.close();
	return nLinhas;
}

void InserepNome(string * pNome, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (file >> aux) {
		pNome[i] = aux;
		i++;

	}
	file.close();

}
void InsereuNome(string * uNome, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (file >> aux) {
		uNome[i] = aux;
		i++;

	}
	file.close();

}
void InsereCurso(string * cursos, string filename) {
	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (getline(file, aux)) {
		cursos[i] = aux;
		i++;

	}
	file.close();
}



void escrevepNome(string * pNome, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << pNome[i] << endl;

	}
}

void escreveuNome(string * uNome, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << uNome[i] << endl;
	}
}

void escrevecursos(string * cursos, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		cout << cursos[i] << endl;
	}
}

void criamesas(int tamanhocantina) {
	int i = 0;
	int n_mesa = 1;
	while (i < tamanhocantina) {
		if (tamanhocantina > 5) {
			int lugares = rand() % 4 + 2;
			Mesa* mesa = new Mesa;
			mesa->numMesa = n_mesa;
			mesa->tamanho = lugares;

			tamanhocantina = tamanhocantina - lugares;
			n_mesa = n_mesa + 1;
			cout << "Numero de mesa: " << mesa->numMesa << endl << "Lugares da mesa: " << mesa->tamanho << endl << endl;


		}
		else {
			Mesa* mesa = new Mesa;
			mesa->numMesa = n_mesa;
			mesa->tamanho = tamanhocantina;
			tamanhocantina = tamanhocantina - tamanhocantina;
			cout << "Numero de mesa: " << mesa->numMesa << endl << "Lugares da mesa: " << mesa->tamanho << endl << endl;

		}
	}
}
void criaidentidades(string * pNome, string * uNome, string * cursos) {
	int i = rand() % 43;
	int j = rand() % 96;
	int k = rand() % 18;
	alunos * aluno = new alunos;
	aluno->primeironome = pNome[i];
	aluno->ultimonome = uNome[j];
	aluno->curso = cursos[k];
	cout << "Nome do aluno: " << aluno->primeironome << " " << aluno->ultimonome << "Curso: " << aluno->curso << endl;


}