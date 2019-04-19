#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"
#include <locale>

using namespace std;


void main() {
locale::global(locale(""));
	srand(time(NULL));

	
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InserepNome(pNome, "primeiro_nome.txt");
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome];
	InsereuNome(uNome, "ultimo_nome.txt");
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereCurso(cursos, "cursos.txt");/*

	int tamanhocantina = rand() % 21 + 30;
	int * cantina = new int[tamanhocantina];
	criamesas(tamanhocantina);
	*/
	alunos* filadeespera = new alunos[50];
	criaidentidades(pNome, uNome, cursos);
	




	/*refeiçao * novaref = new refeiçao;
	cout << "-------------------------CANTINA EDA ------------------------------" << endl;
	InsereRefeição(novaref);
	ImprimeRefeição(novaref);*/
	

	
	


	
	system("Pause");

}