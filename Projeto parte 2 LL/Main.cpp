#include <iostream>
#include "Cantina.h"
#include "Ficheiros.h"
#include <string>
#include <fstream>
#include <locale>
using namespace std;



int main() {
	srand(time(NULL));
	int tamanhopNome = contaLinhas("primeiro_nome.txt");
	string * pNome = new string[tamanhopNome];
	InserepNome(pNome, "primeiro_nome.txt"); // insere os primeiros nomes no array pNome
	int tamanhouNome = contaLinhas("ultimo_nome.txt");
	string * uNome = new string[tamanhouNome];
	InsereuNome(uNome, "ultimo_nome.txt"); // insere os ultimos nomes no array uNome
	int tamanhocursos = contaLinhas("cursos.txt");
	string * cursos = new string[tamanhocursos];
	InsereCurso(cursos, "cursos.txt"); // insere os cursos no array cursos
	int n_pontos = 0;
	identidade * filadeespera = NULL;
	filadeespera = criagrupo(filadeespera,pNome,uNome,cursos);
	escreveFiladeEspera(filadeespera);

	Mesa*mesas = NULL;
	int tamanhodacantina = rand() % 20 + 30;
	mesas = criamesas(mesas, tamanhodacantina);
	imprimeCantina(mesas, tamanhodacantina);


	system("PAUSE");
	return 0;

}