#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int contaLinhas(string filename) {
	int tamanho = 0 ;
	ifstream file(filename);
	string temp = " ";
	while (getline(file, temp)) {
		tamanho++;
		
	}
	cout << tamanho << endl;
	file.close();
	return tamanho;
}

void lePrimeiroNome(string primeiro_nome, int tamanho,string  *pNome) {
	int i = 0;
	
	ifstream file;
	file.open(primeiro_nome, ifstream::out);
	string p_nome;
	
	for (int i = 0; i < tamanho ;i++) {
		pNome[i] = p_nome;
		cout << pNome[i];
	}


	file.close();
}
	
void leUltimoNome(string ultimo_nome, int tamanho, string *uNome) {
	int i = 0;
	ifstream file;
	file.open(ultimo_nome);
	string u_nome;
	
	for (int i = 0; i < tamanho; i++) {
		uNome[i] = u_nome;
		cout << uNome[i];
	}


	file.close();
}


void leCursos(string cursos, int tamanho, string *c) {
	int i = 0;
	
	ifstream file;
	file.open(cursos);
	string curso;
	
	for (int i = 0; i < tamanho; i++) {
		c[i] = curso;
		cout << c[i];
	}

	file.close();
}
