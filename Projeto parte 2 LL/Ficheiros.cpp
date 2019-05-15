
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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


void Insere(string * Nome, string filename, int tamanho) {
	int i = 0;
	ifstream file;
	file.open(filename);
	for (int i = 0; i < tamanho; i++) {
		getline(file, Nome[i]);
	}
	file.close();
}





void InsereFicheiros(string * nome, string filename) {

	int i = 0;
	ifstream file;
	file.open(filename);
	string aux;
	while (getline(file, aux)) {
		nome[i] = aux;
		i++;

	}
	file.close();
}
void escreveFicheiros(string *nome, int tamanho) {

	for (int i = 0; i < tamanho; i++) {
		cout << nome[i] << endl;
	}
}
