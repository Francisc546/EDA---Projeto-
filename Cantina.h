#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refeiçao {

	string entrada;
	string principal;
	float custo;
};
struct identidade {
	
		string primeironome, ultimonome;
		int numeroid, numerogrupo, duraçao;
		string curso;
		float plafond;

};
struct grupo {
	int numerogrupo;
	identidade * pessoas;
};

struct Mesa {
	int numMesa;
	int tamanho;
	grupo * pessoas;

};

void InsereRefeição(refeiçao * novaref);
void ImprimeRefeição(refeiçao * novaref);
int contaLinhas(string filename);
void InserepNome(string * pNome, string filename);
void InsereuNome(string * uNome, string filename);
void InsereCurso(string * cursos, string filename);
void escrevepNome(string * pNome, int tamanho);
void escreveuNome(string * uNome, int tamanho);
void escrevecursos(string * cursos, int tamanho);
void criamesas(int tamanhocantina);
void criaidentidades( string * pNome, string * uNome, string * cursos);
void criagrupo(string * pNome, string * uNome, string * cursos);