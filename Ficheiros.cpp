#include <iostream>
#include <fstream>
#include <string.h>

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

void lePrimeiroNome(string primeiro_nome ) {
	int i = 0;
	int nLinhas = contaLinhas(primeiro_nome);
	ifstream file;
	file.open(primeiro_nome, ifstream::out);
	char p_nome;
	string pNome = new string[nLinhas];
	for (int i = 0; i < nLinhas;i++) {
		pNome[i] = p_nome;
		
	}


	file.close();
}
	
void leUltimoNome(string ultimo_nome ) {
	int i = 0;
	int nLinhas = contaLinhas(ultimo_nome);
	ifstream file;
	file.open(ultimo_nome);
	char u_nome;
	string uNome = new string[nLinhas];
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
	string c = new string[nLinhas];
	for (int i = 0; i < nLinhas; i++) {
		c[i] = curso;

	}

	file.close();
}