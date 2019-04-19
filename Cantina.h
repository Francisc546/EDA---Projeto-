#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refei�ao {

	string entrada;
	string principal;
	float custo;
};
struct alunos {
	string primeironome;
	string ultimonome;
	int numero;
	int numerogrupo;
	string curso;
	float plafond;

};

struct Mesa {
	int numMesa;
	int tamanho;
	alunos * pessoas;

};

void InsereRefei��o(refei�ao * novaref);
void ImprimeRefei��o(refei�ao * novaref);
int contaLinhas(string filename);
void InserepNome(string * pNome, string filename);
void InsereuNome(string * uNome, string filename);
void InsereCurso(string * cursos, string filename);
void escrevepNome(string * pNome, int tamanho);
void escreveuNome(string * uNome, int tamanho);
void escrevecursos(string * cursos, int tamanho);
void criamesas(int tamanhocantina);
void criaidentidades( string * pNome, string * uNome, string * cursos);