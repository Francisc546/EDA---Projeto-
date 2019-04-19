#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"
#include <locale>

using namespace std;


void main() {
	locale::global(locale(""));
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InserepNome(pNome, "primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome];
	InsereuNome(uNome, "ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereCurso(cursos, "cursos.txt");
	/*refeiçao * novaref = new refeiçao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefeição(novaref);
	ImprimeRefeição(novaref);*/
	escrevecursos(cursos, tamanhocursos);
	cout << endl;
	escrevepNome(pNome, tamanhopNome);
	cout << endl;
	escreveuNome(uNome, tamanhouNome);
	cout << endl;

	
	


	
	system("Pause");

}