#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contaLinhas(string filename) {
	int nLinhas = 0 ;
	ifstream file(filename);
	string temp = " ";
	while (getline(file, temp)) {
		nLinhas++;
	}
	file.close();
	return nLinhas;
}

void lePrimeiroNome(string * pNome,string filename ) {
	fstream ficheiro(nome_ficheiro, ios::in);
	if (ficheiro.is_open()) {
		int i = 0;
		string aux;
		while (getline(ficheiro, aux)) {
			pNome[i] = aux
			i++;
		}
	}
	else {
		cout << "Erro ao ler ficheiro de alunos";
}
	
void leUltimoNome(string ultimo_nome ) {
	int i = 0;
	int nLinhas = contaLinhas(ultimo_nome);
	ifstream file;
	file.open(ultimo_nome);
	char u_nome;
	string *uNome = new string[nLinhas];
	for (int i = 0; i < nLinhas; i++) {
		uNome[i] = u_nome;

	}


	file.close();
}


void leCursos(string cursos) {
	int i = 0;
	int nLinhas = contaLinhas(cursos);
	ifstream file;
	file.open(cursos);
	char curso;
	string* c = new string[nLinhas];
	for (int i = 0; i < nLinhas; i++) {
		c[i] = curso;

	}

	file.close();
}
